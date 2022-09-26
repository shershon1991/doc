---
title: "Go标准包(八):sync"
date: 2021-04-08
draft: false
tags: [Go标准包]
categories: [编程, Go]
---

### 1.介绍

`sync`包提供了互斥锁。除了`Once`和`WaitGroup`类型，其余多数适用于低水平的程序，多数情况下，高水平的同步使用`channel`通信性能会更优一些。

### 2.并发等待组(WaitGroup)

`WaitGroup`，即等待一组`Goroutine`结束。父`Goroutine`调用`Add()`方法来设置应等待`Goroutine`的数量。每个被等待的`Goroutine`在结束时应该调用`Done()`方法。与此同时，主`Goroutine`可调用`Wait()`方法阻塞至所有`Goroutine`结束。

#### 2.1 WaitGroup结构

```go
// A WaitGroup must not be copied after first use.
type WaitGroup struct {
	noCopy noCopy
	state1 [3]uint32
}
```

#### 2.2 方法列表

| 方法名                           | 功能                              |
| -------------------------------- | --------------------------------- |
| `(wg *WaitGroup) Add(delta int)` | 等待组的计数器 +1                 |
| `(wg *WaitGroup) Done()`         | 等待组的计数器 -1                 |
| `(wg *WaitGroup) Wait()`         | 当等待组计数器不等于0时,阻塞直到0 |

#### 2.3 Add参数取值范围

等待组内部拥有一个计数器，计数器的值可以通过`Add(delta int)`方法调用实现计数器的增加和减少。该方法应该在创建新的`Goroutine`之前调用。

**参数值x取值**

| 取值         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| `delta < 0 ` | `x`小于0时,但会报错: `panic: sync: negative WaitGroup counter` |
| `delta = 0 ` | `x`等于0时,会释放`Wait()`方法阻塞等待的所有`Goroutine`       |
| `delta > 0`  | `x`大于0时,`Wait()`方法会阻塞`Goroutine`直到`WaitGroup`计数减为0 |

#### 2.4 使用示例

##### 1. 不使用WaitGroup示例

```go
package main
import (
	"fmt"
	"time"
)
func main() {
	// 创建通道
	intChan := make(chan int)

	// 计算1-50的和
	go func(intChan chan int) {
		sum := 0
		for i := 1; i<= 50 ; i++  {
			sum += i
		}
		intChan <- sum
	}(intChan)
	// 计算51-100的和
	go func(intChan chan int) {
		sum := 0
		for i := 51; i<= 100 ; i++  {
			sum += i
		}
		intChan <- sum
	}(intChan)
	// 另外创建个channle聚合结果
	go func(intChan chan int) {
		sum1 := <- intChan
		sum2 := <- intChan
		fmt.Printf("sum1 = %d sum2 = %d  \nsum1 + sum2 = %d \n",sum1,sum2,sum1+sum2)
	}(intChan)

	// 注意,需求手动sleep
	time.Sleep( time.Second)
	fmt.Println("运行结束")
}
/** 输出:
  sum1 = 1275 sum2 = 3775  
  sum1 + sum2 = 5050 
  运行结束
*/
```

##### 2.使用WaitGroup示例

```go
package main
import (
	"fmt"
	"sync"
)
func main() {
	// 声明等待组
	var wg sync.WaitGroup
	// 设置，需要等待3个协程执行完成
	wg.Add(3)
	// 创建通道
	intChan := make(chan int)
	// 计算1-50的和
	go func(intChan chan int, wg *sync.WaitGroup) {
		sum := 0
		for i := 1; i <= 50; i++ {
			sum += i
		}
		intChan <- sum
		// 计数器减一
		wg.Done()
	}(intChan, &wg)
	// 计算51-100的和
	go func(intChan chan int, wg *sync.WaitGroup) {
		sum := 0
		for i := 51; i <= 100; i++ {
			sum += i
		}
		intChan <- sum
		// 计数器减一
		wg.Done()
	}(intChan, &wg)
	// 另外创建个channle聚合结果
	go func(intChan chan int,wg *sync.WaitGroup) {
		sum1 := <-intChan
		sum2 := <-intChan
		fmt.Printf("sum1 = %d sum2 = %d  \nsum1 + sum2 = %d \n", sum1, sum2, sum1+sum2)
		// 计数器减一
		wg.Done()
	}(intChan,&wg)
	// 阻塞，直到等待组的计数器等于0
	wg.Wait()
	fmt.Println("运行结束")
}
/**输出
  sum1 = 3775 sum2 = 1275  
  sum1 + sum2 = 5050 
  运行结束
*/
```

### 3.互斥锁(Mutex)

`Mutex`是一个互斥锁，<font color=red>保证同时只有一个Goroutine可以访问共享资源</font>。`Mutex`类型的锁和`Goroutine`无关，可以由不同的`Goroutine`加锁和解锁。也可以为其他结构体的字段，零值为解锁状态。

#### 3.1 结构介绍

```go
type Mutex struct {
	state int32 // state 表示当前互斥锁的状态
	sema  uint32 // sema 是用于控制锁状态的信号量
}
```

#### 3.2 方法列表

| 方法名                | 描述                                                  |
| --------------------- | ----------------------------------------------------- |
| `(m *Mutex) Lock()`   | 方法锁住`m`，如果` m` 已经加锁，则阻塞直到 `m` 解锁。 |
| `(m *Mutex) Unlock()` | 解锁 `m`，如果 `m` 未加锁会导致运行时错误。           |

#### 3.3 使用(售票)

需求:模拟多个窗口售票

##### 1.不作为结构体属性使用

```go
package main
import (
	"fmt"
	"sync"
	"time"
)
// 声明全局等待组
var wg sync.WaitGroup
// 声明全局锁
var mutex sync.Mutex
// 声明全局余票
var ticket int = 10
func main() {
	// 设置等待组计数器
	wg.Add(3)
	// 窗口卖票
	go saleTicket("窗口A",&wg)
	go saleTicket("窗口B",&wg)
	go saleTicket("窗口C",&wg)
	wg.Wait()
	fmt.Println("运行结束!")
}
// 卖票流程
func saleTicket(windowName string, wg *sync.WaitGroup)  {
	// 卖票流程结束后关闭
	defer wg.Done()
	for {
		// 加锁
		mutex.Lock()
		if  ticket > 0{
			time.Sleep(10 * time.Millisecond)
			ticket--
			fmt.Printf("%s 卖出一张票，余票: %d \n",windowName,ticket)
		} else  {
			fmt.Printf("%s 票已卖完! \n",windowName)
			// 解锁
			mutex.Unlock()
			break
		}
		// 解锁
		mutex.Unlock()
	}
}
/**输出
  窗口C 卖出一张票，余票: 9 
  窗口C 卖出一张票，余票: 8 
  窗口B 卖出一张票，余票: 7 
  窗口A 卖出一张票，余票: 6 
  窗口C 卖出一张票，余票: 5 
  窗口B 卖出一张票，余票: 4 
  窗口A 卖出一张票，余票: 3 
  窗口C 卖出一张票，余票: 2 
  窗口B 卖出一张票，余票: 1 
  窗口A 卖出一张票，余票: 0 
  窗口C 票已卖完! 
  窗口B 票已卖完! 
  窗口A 票已卖完! 
  运行结束!
*/
```

##### 2.作为结构体属性使用

```go
package main
import (
	"fmt"
	"strconv"
	"sync"
	"time"
)
// 声明一个票池
type ticketPool struct {
	over int
	lock sync.Mutex
	wg   sync.WaitGroup
}
// 定义售票方法
func (t *ticketPool) sellTicket(windowName string) {
	// 等待组减一
	defer t.wg.Done()
	for {
		// 加锁
		t.lock.Lock()
		if t.over > 0 {
			time.Sleep(10 * time.Millisecond)
			t.over--
			fmt.Printf("%s 卖出一张票，余票: %d \n", windowName, t.over)
		} else {
			// 无票，跳无限循环并解锁
			t.lock.Unlock()
			fmt.Printf("%s 票已卖完! \n", windowName)
			break
		}
		// 正常售票流程解锁
		t.lock.Unlock()
	}
}
func main() {
	// 创建一个票池
	ticketP := ticketPool{over: 10}
	fmt.Printf("T:%T v: %v \n", ticketP, ticketP)
	// 设置窗口数量
	windowNum := 3
	// 设置等待组计数器
	ticketP.wg.Add(windowNum)
	// 定义3个窗口售票
	for i:= 1 ; i <= windowNum; i++ {
		go ticketP.sellTicket("窗口" + strconv.Itoa(i))
	}
	ticketP.wg.Wait()
	fmt.Println("运行结束!")
}
/**输出
  窗口3 卖出一张票，余票: 9 
  窗口3 卖出一张票，余票: 8 
  窗口1 卖出一张票，余票: 7 
  窗口2 卖出一张票，余票: 6 
  窗口3 卖出一张票，余票: 5 
  窗口1 卖出一张票，余票: 4 
  窗口2 卖出一张票，余票: 3 
  窗口3 卖出一张票，余票: 2 
  窗口1 卖出一张票，余票: 1 
  窗口2 卖出一张票，余票: 0 
  窗口1 票已卖完! 
  窗口2 票已卖完! 
  窗口3 票已卖完! 
  运行结束!
*/
```

### 4.读写锁(RWMutex)

#### 4.1 结构介绍

`RWMutex`是读写互斥锁，简称读写锁。该锁可以同时被多个读取者持有或被唯一个写入者持有。`RWMutex`类型锁跟`Goroutine`无关，可以由不同的`Goroutine`加锁、解锁。`RWMutex`也可以创建为其他结构体的字段；零值为解锁状态。

##### 1. `RWMutex`锁结构

```go
type RWMutex struct {
    w  Mutex //用于控制多个写锁，获得写锁首先要获取该锁，如果有一个写锁在进行，那么再到来的写锁将会阻塞于此
    writerSem  uint32 //写阻塞等待的信号量，最后一个读者释放锁时会释放信号量
    readerSem  uint32 //读阻塞的协程等待的信号量，持有写锁的协程释放锁后会释放信号量
    readerCount int32  //记录读者个数
    readerWait  int32  //记录写阻塞时读者个数
}
```

##### 2. 读写锁堵塞场景

1. 写锁需要阻塞写锁：一个协程拥有写锁时，其他协程写锁需要阻塞
2. 写锁需要阻塞读锁：一个协程拥有写锁时，其他协程读锁需要阻塞
3. 读锁需要阻塞写锁：一个协程拥有读锁时，其他协程写锁需要阻塞
4. 读锁不能阻塞读锁：一个协程拥有读锁时，其他协程也可以拥有读锁

#### 4.2 方法列表

| 方法名                    | 描述                                                         |
| ------------------------- | ------------------------------------------------------------ |
| `(rw *RWMutex) RLock()`   | 获取读锁,当一个协程拥有读锁时，其他协程写锁需要阻塞。        |
| `(rw *RWMutex) RUnlock()` | 释放读锁。                                                   |
| `(rw *RWMutex) Lock()`    | 获取写锁，与Mutex完全一致；<br>当一个协程拥有写锁时，其他协程读写锁都需要阻塞 |
| `(rw *RWMutex) Unlock()`  | 释放写锁                                                     |

#### 4.3 使用(读写文件)

##### 1.不作为结构体属性使用

```go
package main
import (
	"fmt"
	"strconv"
	"sync"
)
// 声明全局变量，文件内容
var fileContext string
// 声明全局读写互斥锁
var rxMutex sync.RWMutex
// 声明全局等待组
var wg sync.WaitGroup
func main() {
	// 设置计数器
	wg.Add(5)
	for i := 1; i <= 5; i++ {
		name := "同学-" + strconv.Itoa(i)
		if i%2 == 0 {
			go readFile(name)
		} else {
			go writeFile(name, strconv.Itoa(i))
		}
	}
	// 等待所有计数器执行完成
	wg.Wait()
	fmt.Println("运行结束!")
}

// 读文件
func readFile(name string) {
	// 释放读锁
	defer rxMutex.RUnlock()
	// 获取读锁
	rxMutex.RLock()
	// 打印读取内容
	fmt.Printf("%s 获取读锁，读取内容为: %s \n", name, fileContext)
	// 计数器减一
	wg.Done()
}
// 写文件
func writeFile(name, s string) {
	// 释放写锁
	defer rxMutex.Unlock()
	// 获取写锁
	rxMutex.Lock()
	// 写入内容
	fileContext = fileContext + " " + s
	fmt.Printf("%s 获取写锁，写入内容: %s。 文件内容变成: %s \n", name, s, fileContext)
	// 计数器减一
	wg.Done()
}

/**输出
  同学-1 获取写锁，写入内容: 1。 文件内容变成:  1 
  同学-4 获取读锁，读取内容为:  1 
  同学-2 获取读锁，读取内容为:  1 
  同学-5 获取写锁，写入内容: 5。 文件内容变成:  1 5 
  同学-3 获取写锁，写入内容: 3。 文件内容变成:  1 5 3 
  运行结束!
*/
```

##### 2.作为结构体属性使用

```go
package main
import (
	"fmt"
	"strconv"
	"sync"
	"time"
)
// 定义一个文件结构体
type fileResource struct {
	content string
	wg sync.WaitGroup
	rwLock sync.RWMutex
}

// 读文件
func (f *fileResource)readFile(name string) {
	// 释放读锁
	defer f.rwLock.RUnlock()
	// 获取读锁
	f.rwLock.RLock()
	// 打印读取内容
	time.Sleep(time.Second)
	fmt.Printf("%s 获取读锁，读取内容为: %s \n", name, f.content)
	// 计数器减一
	f.wg.Done()
}

// 写文件
func (f *fileResource)writeFile(name, s string) {
	// 释放写锁
	defer f.rwLock.Unlock()
	// 获取写锁
	f.rwLock.Lock()
	// 写入内容
	time.Sleep(time.Second)
	f.content = f.content + " " + s
	fmt.Printf("%s 获取写锁，写入内容: %s。 文件内容变成: %s \n", name, s, f.content)
	// 计数器减一
	f.wg.Done()
}
func main() {
	// 声明结构体
	var file fileResource
	// 设置计数器
	file.wg.Add(5)
	for i := 1; i <= 5; i++ {
		name := "同学-" + strconv.Itoa(i)
		if i%2 == 0 {
			go file.readFile(name)
		} else {
			go file.writeFile(name, strconv.Itoa(i))
		}
	}
	// 等待所有计数器执行完成
	file.wg.Wait()
	fmt.Println("运行结束!")
}
/**输出
  同学-5 获取写锁，写入内容: 5。 文件内容变成:  5 
  同学-1 获取写锁，写入内容: 1。 文件内容变成:  5 1 
  同学-2 获取读锁，读取内容为:  5 1 
  同学-3 获取写锁，写入内容: 3。 文件内容变成:  5 1 3 
  同学-4 获取读锁，读取内容为:  5 1 3 
  运行结束!
*/
```

### 5.条件变量(Cond)

#### 5.1 介绍

与互斥锁不同，条件变量的作用并不是保证在同一时刻仅有一个线程访问某一个共享数据，而是在对应的共享数据的状态发生变化时，通知其他因此而被阻塞的线程。<font color=red>条件变量总是与互斥锁组合使用，互斥锁为共享数据的访问提供互斥支持，而条件变量可以就共享数据的状态的变化向相关线程发出通知。</font>

**使用场景: ** 我需要完成一项任务，但是这项任务需要满足一定条件才可以执行，否则我就等着。

#### 5.2 方法列表

| 方法名                    | 描述                                                         |
| ------------------------- | ------------------------------------------------------------ |
| `NewCond(l Locker) *Cond` | 生成一个`cond`,需要传入实现`Locker`接口的变量。<br/>一般是`*Mutex`或`*RWMutex`类型的值。 |
| `(c *Cond) Wait()`        | 等待通知                                                     |
| `(c *Cond) Signal()`      | 发送单个通知                                                 |
| `(c *Cond) Broadcast()`   | 广播(多个通知)                                               |

#### 5.3 使用示例

```go
package main
import (
	"fmt"
	"sync"
	"time"
)
func main() {
	// 声明互斥锁
	var mutex sync.Mutex
	// 声明条件变量
	cond := sync.NewCond(&mutex)
	for i := 1; i <= 10; i++ {
		go func(i int) {
			// 获取锁
			cond.L.Lock()
			// 释放锁
			defer cond.L.Unlock()
			// 等待通知,阻塞当前协程
			cond.Wait()
			// 等待通知后打印输出
			fmt.Printf("输出:%d ! \n", i)
		}(i)
	}
	// 单个通知
	time.Sleep(time.Second)
	fmt.Println("单个通知A！")
	cond.Signal()
	time.Sleep(time.Second)
	fmt.Println("单个通知B！")
	cond.Signal()

	// 广播通知
	time.Sleep(time.Second)
	fmt.Println("广播通知！并睡眠1秒，等待其他协程输出!")
	cond.Broadcast()
	// 等待其他协程处理完
	time.Sleep(time.Second)
	fmt.Println("运行结束！")
}
/**输出
  单个通知A！
  输出:1 ! 
  单个通知B！
  输出:4 ! 
  广播通知！并睡眠1秒，等待其他协程输出!
  输出:10 ! 
  输出:2 ! 
  输出:3 ! 
  输出:8 ! 
  输出:9 ! 
  输出:6 ! 
  输出:5 ! 
  输出:7 ! 
  运行结束！
*/
```

### 6.一次(Once)

`sync.Once` 是使Go方法只执行一次的对象实现，作用与 `init` 函数类似,但也有所不同。区别如下:

- **init** 函数是在文件包首次被加载的时候执行，且只执行一次
- **sync.Onc** 是在代码运行中需要的时候执行，且只执行一次

#### 6.1 方法介绍

| 方法名                   | 描述                                                         |
| ------------------------ | ------------------------------------------------------------ |
| `(o *Once) Do(f func())` | 函数只会执行一次，并保证在返回时，传入`Do`的函数已经执行完成。<br/>多个 `goroutine` 同时执行 `once.Do` 的时候，可以保证抢占到 `once.Do` 执行权的 `goroutine` 执行完 `once.Do` 后，其他` goroutine `才能得到返回 。 |

#### 6.2 使用示例

**示例1: 重复调用只执行一次**

```go
package main
import (
	"fmt"
	"strconv"
	"sync"
	"time"
)
func main() {
	echo := func() {
		t := time.Now().Unix()
		fmt.Printf("输出时间 %v ",strconv.FormatInt(t,10))
	}
	var one sync.Once
  // 虽然遍历调用，但是只会执行一次
	for i := 1; i< 10 ; i++  {
		go func(a,b int) {
			one.Do(echo)
		}(i,i+1)
	}
	time.Sleep(3 * time.Second)
	fmt.Println("运行结束！")
}
/**输出
  输出时间 1608083525 
  运行结束！
*/
```



### 7.对象池(`Pool`)

#### 7.1 为什么使用?

`Go`语言是支持垃圾自动回收的。对于一些暂时用不到但是后续会用到的对象，为了提升性能，可以先暂存起来，这虽然会占用一些内存，但是比起销毁了再新建，要节省运行时间。`Go`语言专门提供了暂存对象的工具，就是`sync.Pool`。

`sync.Pool`是一个对象池，它是并发安全的，而且大小是可伸缩的，仅受限于内存。当需要使用对象的时候可以从对象池中直接取出使用。

#### 7.2 数据结构

```go
type Pool struct {
	noCopy noCopy //禁止复制
	local     unsafe.Pointer //本地缓冲池指针,每个处理器分配一个;其类型是[P]poolLocal数组
	localSize uintptr //数组大小

	victim     unsafe.Pointer // local from previous cycle
	victimSize uintptr        // size of victims array

	// 缓存池没有对象时,调用此方法创建
	New func() interface{}
}
```

#### 7.3 方法列表

`sync.Pool`提供以下两个公共方法，用来操作对象池。

| 方法名                         | 描述           |
| ------------------------------ | -------------- |
| `(p *Pool) Put(x interface{})` | 向池中添加对象 |
| `(p *Pool) Get() interface{}`  | 从池中获取对象 |

> `Get`方法是从池中获取对象，如果没有对象则调用`New`方法创建生成，如果未设置`New`则返回`nil`。

#### 7.4 使用示例

```go
package main
import (
	"fmt"
	"sync"
)
func main() {
	// 创建对象池
	pool := sync.Pool{
		New: func() interface{}{
			return make([]string,5)
		},
	}
	// 首次获取
	fmt.Printf("不设置直接获取: %v\n",pool.Get())
	// 设置后获取
	pool.Put([]string{"Hello","Word"})
	// 设置后获取
	fmt.Printf("设置后,第一次获取: %v\n",pool.Get())
	fmt.Printf("设置后,第二次获取: %v\n",pool.Get())
}
```

#### 7.5 注意事项

存入`sync.Pool`的对象可能会在不通知的情况下被释放，这一点一定要注意。比如一些`socket`长连接就不适合存入`sync.Pool`内。

### 8.`sync.Map`

如果要缓存的数据量不大，可以考虑使用`sync.Map`(`Go 1.9+版本支持`)。<font color=red>**在`1.6`版本以前，`Go`语言自带标准的`map`类型是并发读安全的，但是并发写不安全。**</font>

#### 8.1 查询和新增

**a.查找方法:**

- `Load`: 通过参数`key`查询对应的`value`，如果不存在则返回`nil`；`ok`表示是否找到对应的值。

**b.新增方法:**

- `Store`: 对`sync.Map`的更新或新增，参数是键值对
- `LoadOrStore`: 参数为`key`和`value`。根据参数`key`查找对应的`value`，如果找到,则不修改原来的值并通过`actual`返回，并且`loaded`为`true`；如果未找到，则存储`key-value`并且将存储的`value`通过`actual`返回，`loaded`为`false`。

**c.使用示例:**

```go
package main
import (
	"fmt"
	"sync"
)
func main() {
	// 定义map 类型
	var syncMap sync.Map
	// 新增
	syncMap.Store("name","张三")
	load, _ := syncMap.Load("name")
	fmt.Printf("Store新增->name:%v\n",load)
	// 找到则不更新，返回旧值
	store, loaded := syncMap.LoadOrStore("name", "李四")
	fmt.Printf("找到则返回旧值-> name:%v loaded:%v \n",store,loaded)
	// 找不到则新增
	age, loaded := syncMap.LoadOrStore("age", 20)
	fmt.Printf("找不到则新增-> age:%v loaded:%v \n",age,loaded)
}
/**输出:
Store新增->name:张三
找到则返回旧值-> name:张三 loaded:true 
找不到则新增-> age:20 loaded:false 
*/
```

#### 8.2 删除

**a.方法列表:**

- `LoadAndDelete`: 根据参数`key`删除对应的`value`，如果找到则删除，并通过`value`返回删除的值，并设置`loaded`为`true`；如果未找到，则`value`返回`nil`，`loaded`为`false`。
- `Delete`：根据参数`key`删除对应的`value`。

**b.使用示例:**

```go
package main
import (
	"fmt"
	"sync"
)
func main() {
	// 定义map 类型
	var syncMap sync.Map
	// 新增
	syncMap.Store("name","张三")
	syncMap.Store("age",20)

  // 找到情况
	andDelete, loaded := syncMap.LoadAndDelete("name")
	fmt.Printf("找到-> val:%v loaded:%v \n",andDelete,loaded)
	search, ok := syncMap.Load("name")
	fmt.Printf("删除name后查找-> search:%v ok:%v \n",search,ok)

	// 找不到情况
	andDelete2, loaded := syncMap.LoadAndDelete("name2")
	fmt.Printf("找不到-> val:%v loaded:%v \n",andDelete2,loaded)

	syncMap.Delete("age")
	searchAge, ok := syncMap.Load("name")
	fmt.Printf("删除age后查找-> searchAge:%v ok:%v \n",searchAge,ok)
}
/** 输出
找到-> val:张三 loaded:true 
删除name后查找-> search:<nil> ok:false 
找不到-> val:<nil> loaded:false 
删除age后查找-> searchAge:<nil> ok:false 
*/
```

#### 8.3 遍历

`sync.Map`不能通过`for...range`遍历，只能通过包提供的方法`Range`进行遍历。

```go
package main
import (
	"fmt"
	"sync"
)
func main() {
	// 定义map 类型
	var syncMap sync.Map
	// 新增
	syncMap.Store("name", "张三")
	syncMap.Store("age", 20)
	syncMap.Store("home", "天津永和大区")
	syncMap.Range(func(key, value interface{}) bool {
		fmt.Printf("key: %v value: %v \n", key, value)
		return true
	})
}
/**输出
key: name value: 张三 
key: age value: 20 
key: home value: 天津永和大区 
*/
```

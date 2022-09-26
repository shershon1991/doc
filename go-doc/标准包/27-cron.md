---
title: "Go标准包(二十七):cron"
date: 2021-04-27
draft: false
tags: [Go标准包]
categories: [编程, Go]
---

## 1.介绍

在`Linux`中，通过`crontab`命令使任务在约定的时间执行已经计划好的工作，而`Go`由于语言的特性，不适合直接使用`crontab`来管理计划任务，[cron (目前 Star8.3k)](https://github.com/robfig/cron)是一个用`Go`实现的定时任务库，支持秒级定时任务，可以满足绝大多数工作场景需求。

## 2. 安装

```go
go get github.com/robfig/cron/v3@v3.0.0
```

## 3. 快速使用

```go
package main

import (
	"fmt"
	"github.com/robfig/cron/v3"
	"time"
)
func main() {
	// 开启秒字段支持
	c := cron.New(cron.WithSeconds())
	// 传统表达式写法: 每秒执行一次
	_, _ = c.AddFunc("0/1 * * * * *", func() {
		fmt.Println("传统表达式: ",time.Now().Format("2006-01-02 15:04:05"))
	})
	// 预定义表达式
	_,_ = c.AddFunc("@every 1s", func() {
		fmt.Println("预定义表达式: ",time.Now().Format("2006-01-02 15:04:05"))
	})
	// 启动
	c.Start()
	// 防止程序直接退出
	time.Sleep(time.Second * 3)
}
/**输出
预定义表达式:  2021-07-18 10:44:52
传统表达式:   2021-07-18 10:44:52
传统表达式:   2021-07-18 10:44:53
预定义表达式:  2021-07-18 10:44:53
传统表达式:    2021-07-18 10:44:54
预定义表达式:  2021-07-18 10:44:54
*/
```

## 4. 添加任务方式

### 4.1 通过`AddFunc`

**具体使用，参见上面的快速使用案例**

### 4.2 通过`AddJob`

#### 1. 使用步骤

- 第一步：定义类型
- 第二步：实现`cron.Job`接口，即给自定义类型添加方法`Run()`
- 第三步：通过`AddJob`方法添加到定时任务

#### 2. 使用示例

```go
package main

import (
	"fmt"
	"github.com/robfig/cron/v3"
	"time"
)
// 定义类型
type city struct {
	Name string
}
// 实现cron.Job接口
func (s city) Run()  {
	fmt.Printf("%s时间:%v\n",s.Name,time.Now().Format("2006-01-02 15:04:05"))
}

func main() {
	// 开启秒级别支持,默认支持最小粒度是分钟
	c := cron.New(cron.WithSeconds())
	// 添加定时任务
	_, _ = c.AddJob("@every 1s", city{
		Name: "北京",
	})
	// 启动
	c.Start()
	// 防止程序直接退出
	for {}
}

/**输出
北京时间:2021-07-18 11:21:50
北京时间:2021-07-18 11:21:51
北京时间:2021-07-18 11:21:52
...
*/
```



## 5. 执行频率

### 5.1 cron时间表达式

<font color=red>@注意: cron默认支持最小粒度是分钟，若要支持秒级别,需要传入`cron.WithSeconds()`来开启,开启后的cron时间表达式和Linux中的crontab时间表达式会有区别。</font>

#### 1. 开启秒级别后

![](https://raw.githubusercontent.com/shershon1991/picImgBed/master/go/img/20210824114416.png)



#### 2. 示例

<font color=red>@注意：下面表格示例，是在开启秒级级别支持情况下的写法。</font>

| 表达式            | 说明                |
| ----------------- | ------------------- |
| `* * * * * *`     | 每秒执行一次        |
| `0 */1 * * * *`   | 每分钟执行一次      |
| `0 0 */1 * * *`   | 每小时执行一次      |
| `0 0 0 */1 * *`   | 每天`00:00`执行一次 |
| `0 30 23 */1 * *` | 每天`23:30`执行一次 |
| `0 0 0 1 */1 *`   | 每月的第一天执行    |
| `0 30 21 * * 1`   | 每周一`21:30`执行   |

### 5.2 预定义时间

#### 1. 预表达式

上面通过表达式写，很容易会写错，还好`cron`提供了预表达式，可以很方便各种场景的示例,具体如下:

| 表达式                   | 描述                                                    | 等式            |
| ------------------------ | ------------------------------------------------------- | --------------- |
| `@yearly (or @annually)` | 每年1月1日 00:00:00 执行一次                            | `0 0 0 1 1 *`   |
| `@monthly`               | 每个月第一天的 00:00:00 执行一次                        | `0 0 0 1 * *`   |
| `@weekly`                | 每周周六的 00:00:00 执行一次                            | `0 0 0 * * 0`   |
| `@daily (or @midnight)`  | 每天 00:00:00 执行一次                                  | `0 0 0 * * *`   |
| `@hourly`                | 每小时执行一次                                          | `0 0 * * * *`   |
| `@every duration`        | 指定时间间隔执行一次，如 `@every 5s`，每隔5秒执行一次。 | `0/5 * * * * *` |

#### 2. 固定间隔(`@every `)

`@every duration`含义为每隔`duration`触发一次。`<duration>`会调用`time.ParseDuration()`函数解析，所以`ParseDuration`支持的格式都可以。单位为`h(小时)、m(分钟)、s(秒)`

| 表达式        | 说明                 |
| ------------- | -------------------- |
| `@every 1s`   | 每秒钟执行一次       |
| `@every 1m`   | 每分钟执行一次       |
| `@every 1h`   | 每小时执行一次       |
| `@every 1h1m` | 每小时一分钟执行一次 |
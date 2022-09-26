---
title: "PHP源码"
date: 2022-05-10
categories: [源码, PHP7源码]
tags: [PHP7源码]
cover: false
---

## 1.PHP7的新特性

### 1.太空船操作符 <=>

太空船操作符用于比较两个表达式

例如，当$a 小于、等于或大于$b 时它分别返回-1、0 或 1

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsv74Lfy.jpg)

### 2. 类型声明

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsEPAf4d.jpg)

### 3. NULL 合并操作符

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsoXd0x5.jpg)

### 4. 常量数组

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsS41BPp.jpg)

### 5. NameSpace 批量导入

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsortlA0.jpg)

### 6. Throwable 接口

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsp1DcTJ.jpg)

### 7. Closure::call()

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsmK22vv.jpg)

### 8. intdiv 函数

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsxOqMik.jpg)

### 9. list 的方括号写法

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsPOfViI.jpg)

### 10.抽象语法树（AST）

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsQqjL3g.jpg)

## 2. 基本变量和内存管理

### 1.小而巧的 zval

定义：

```c
typedef union _zend_value {
	zend_long         lval;				/* long value */
	double            dval;				/* double value */
	zend_refcounted  *counted;
	zend_string      *str;
	zend_array       *arr;
	zend_object      *obj;
	zend_resource    *res;
	zend_reference   *ref;
	zend_ast_ref     *ast;
	zval             *zv;
	void             *ptr;
	zend_class_entry *ce;
	zend_function    *func;
	struct {
		uint32_t w1;
		uint32_t w2;
	} ww;
} zend_value;

struct _zval_struct {
	zend_value        value;			/* value */
	union {
		struct {
			ZEND_ENDIAN_LOHI_4(
				zend_uchar    type,			/* active type */
				zend_uchar    type_flags,
				zend_uchar    const_flags,
				zend_uchar    reserved)	    /* call info for EX(This) */
		} v;
		uint32_t type_info;
	} u1;
	union {
		uint32_t     next;                 /* hash collision chain */
		uint32_t     cache_slot;           /* literal cache slot */
		uint32_t     lineno;               /* line number (for ast nodes) */
		uint32_t     num_args;             /* arguments number for EX(This) */
		uint32_t     fe_pos;               /* foreach position */
		uint32_t     fe_iter_idx;          /* foreach iterator index */
		uint32_t     access_flags;         /* class constant access flags */
		uint32_t     property_guard;       /* single property guard */
	} u2;
};
```

大小：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsJKSUql.jpg)

类型：

```c
/* regular data types */
#define IS_UNDEF					0
#define IS_NULL						1
#define IS_FALSE					2
#define IS_TRUE						3
#define IS_LONG						4
#define IS_DOUBLE					5
#define IS_STRING					6
#define IS_ARRAY					7
#define IS_OBJECT					8
#define IS_RESOURCE					9
#define IS_REFERENCE				10
```

### 2. 不同变量对应的 zval

例子：

```php
<?php
/**
 * @date: 2022/3/9
 * @createTime: 10:53 PM
 */

$a = 2;
echo $a;
$b = 1.1;
echo $b;
$c = null;
echo $c;
$d = true;
echo $d;
$e = false;
echo $e;
$f = "string";
echo $f;
$g = [1, 2, 3];
echo $g;
$h = new stdClass();
echo $h; // FATAL ERROR
```

### 3.zend_string 与写时复制(copy on write)

例子：

```php
<?php
/**
 * @date: 2022/3/10
 * @createTime: 11:19 AM
 */

// 常量字符串
$c = 'hello world';
echo $c;
// 变量字符串
$a = time() . 'string';
echo $a;

// COW: copy on write
$b = $a;
echo $a;
echo $b;
$b = 'hello';
echo $a;
echo $b;
```

### 4.zend_reference 的使用

例子：

```php
<?php
/**
 * @date: 2022/3/10
 * @createTime: 11:47 AM
 */

$a = 'string';
$b = &$a;
echo $a . "\n";
echo $b . "\n";

$b = 'hello';
echo $a . "\n";
echo $b . "\n";

unset($b);
echo $b . "\n";
echo $a . "\n";
```

### 5.PHP7 源码中数组的增删改查

例子：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpskKlwLW.jpg)

### 6.内存管理基础知识

申请和释放内存

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsjsHBVj.jpg)

malloc的实现

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsTwf21X.jpg)

6.1 PHP 内存接口

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsCBvfvX.jpg)

6.2 基本概念

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsaLhHzx.jpg)

l chunk：2MB 大小的内存

l page：4KB 大小的内存

l slot：一个page可以划分为多个slot

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpslly3Ab.jpg)

1chunk = 512page

6.3 内存规格

l 内存预分配：使用 mmap 分配 chunk

l 内存分类

a. small内存（size<=3KB），30 种规格

b. large内存（3KB<size<=2MB-4KB），是 4KB 的整数倍

c. huge内存（size>2MB-4KB），是 2MB 的整数倍

6.4 内存分配流程

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpssLiQ23.jpg)

内存管理emalloc内存分配过程

6.5 small 内存

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsSHct1m.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsrq5mVF.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpssneNej.jpg)

6.6 small 内存实战

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps8nUFmN.jpg)

例子：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps7iIkEu.jpg)

注意：

l 传过来的size大小，返回的不一定是size大小的内存。返回的是能够cover住size的最小规格的内存。如申请7B的大小，返回的是8。

l 申请小块内存时，先申请一个page，把它切割成相同大小的内存，然后把这些相同大小的内存的第一个返回，剩下的通过单向链表连接起来，挂在free_slot上，以备后需。

l 根据内存的地址，可以快速的知道内存的大小。

6.7 内存对齐

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsIoH5ZX.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsbsF2II.jpg)

6.8 全局变量

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsVWm5dT.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsowAijY.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsgV1peD.jpg)

6.9 内存类型标记

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsnQSL8j.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsyhmR7b.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsrjLuMO.jpg)

6.10 内存标记和内存释放时大小的判断

例子：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpskT2SG5.jpg)

## 3. PHP运行的生命周期

### 3.1 CLI 模式的生命周期

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsPIOHdN.jpg)

3.1.1 模块初始化部分函数调用图

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpshfkF5n.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsjycMAt.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsHFQIEW.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsByRmGg.jpg)

3.1.2 请求初始化阶段

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsFdc8xW.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsxOQBcv.jpg)

3.1.3 详细执行和管理阶段

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsALqtcN.jpg)

3.1.4 请求关闭阶段

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsNYI6Mj.jpg)

3.1.5 模块关闭阶段

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpseaP7z8.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpszqZ4O7.jpg)

### 3.2 FPM 模式的生命周期

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsftdUMM.jpg)

3.2.1 何为 FPM 的三种模式？

l pm=static

l pm=dynamic

l pm=ondemand

注意：Master 进程不提供服务，只是管理 worker 进程，当 worker 进程挂掉之后，会重新拉一个新的 worker 进程提供服务！

### 3.3 详解 FastCGI 协议

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsSDFPBm.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsYhdUsC.jpg)

Nginx收到HTTP请求，然后Nginx直接把HTTP协议的包进行解包然后做一次封装，然后转发给PHP-FPM，一般PHP-FPM监听9000端口，Nginx向PHP-FPM发出的请求就是FastCGI编码的，这里是一个个的键值对，又有头部和尾部的一个编码，然后PHP-FPM对FastCGI的协议的一个解码，然后走到FPM的生命周期里面，然后转到index.php或者其他PHP文件里面，然后进行脚本的执行，执行完以后，合成一个FastCGI协议返送给Nginx，返回的时候比较简单一些，按照HTTP协议的方式进行内容编码，但是还是FastCGI协议，Nginx再解析成HTTP协议发送给客户端。

总结：

整个FPM模式实际上是一个多进程模式，首先由calling
process进程fork出master进程，然后master进程会创建Socket，然后fork出worker进程，worker进程会在accept处阻塞等待，请求过来时，由其中一个worker进程处理，按照FastCGI模式进行各阶段读取，另外，FPM建立计分板机制，关注全部和每个worker工作情况，方便使用者监控。

3.3.1 FastCGI 协议实战

通过抓包工具抓包理解：tcpdump -i lo port 9000 -XX -S

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsXUiZRb.jpg)

### 3.4 运行原理

3.4.1 常见的4种PHP运行模式

l CGI 模式

CGI就是将Web服务器和PHP执行程序连接起来，把接收的指令传递给PHP执行程序，每有一个用户请求，都会先要创建CGI的子进程，然后处理请求，用户请求数量非常多会大量挤占系统的资源，造成效率低下，所以有多少连接请求就有多少CGI子进程，子进程反复加载是导致CGI性能低下的主要原因。

l Fast-CGI 模式

是CGI的升级版本，FastCGI 像是一个常驻型的 CGI，它可以一直执行着，只要激活后，不会每次都要花费时间去fork 一次，也是一种协议。FastCGI的工作原理是：

1．Web Server启动时载入FastCGI进程管理器【PHP的FastCGI进程管 理器是PHP-FPM(php-FastCGI Process Manager)】（IIS是ISAPI或 Apache是Module);

2．FastCGI进程管理器自身初始化，启动多个CGI解释器进程 (在任务管理器 中可见多个php-cgi.exe)并等待来自Web Server的连接。

3．当客户端请求到达Web Server时，FastCGI进程管理器选择并连接到一个 CGI解释器。Web server将CGI环境变量和标准输入发送到FastCGI子进 程php-cgi。

4．FastCGI子进程完成处理后将标准输出和错误信息从同一连接返回Web Server。当FastCGI子进程关闭连接时，请求便处理完成。FastCGI子进程接 着等待并处理来自FastCGI进程管理器（运行在 Web
Server中）的下一个连 接。在正常的CGI模式中，php-cgi.exe在此便退出了。

在CGI模式中，可以想象 CGI通常有多慢。每一个Web请求PHP都必须重新解析php.ini、重新载入全部dll扩展并重初始化全部数据结构。使用FastCGI，所有这些都只在进程启动时发生一次。

l CLI 模式

l 模块模式

n Apache + mod_php

n lighttp + spawn-fcgi

n nginx + PHP-FPM（php在Nginx中运行模式）

3.4.2 运行原理

PHP-CGI：cgi是一种协议，而php-cgi是实现了这种协议的进程。不过这种实现 比较烂。它是单进程的，一个进程处理一个请求，处理结束后进程就销毁。

PHP - FPM：是对php-cgi的改进版，它直接管理多个php-cgi进程/线程。也就 是说，php-fpm是php-cgi的进程管理器因此它也算是fast-cgi协议的实 现。

php的运行原理：就是在服务器启动时，自动载入PHP-FPM进程管理器，从而管 理多个PHP-CGI进程来准备响应用户的请求，如下图所示：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps9QMsLf.jpg)

由于php-cgi是随服务器启动载入的，所以初始化变量只会发生一次。

3.4.3 SAPI简介

SAPI相当于PHP外部环境的代理器。PHP可以应用在终端上（CLI SAPI），也可以应用在Web服务器上（CGI SAPI）。

## 4. PHP代码的编译与执行

### 1.解释型语言也需要编译？

编译型语言

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsvmpShZ.jpg)

解释型语言

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsdMvo4r.jpg)

### 2.词法分析入门

2.1 NFA（不确定有穷自动机）

l 正则表达式 (a|b)*abb

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsxJnxxg.jpg)

l abb/aabb/babb/aababb

l a/ab/bb/acabb

2.2 DFA（确定有穷自动机）

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpscfMhiE.jpg)

2.3 实战：使用 re2c 做词法分析

例子：/home/git/study/php_bottom/chapter5/integer.l

### 3.语法分析入门

l a = b + c * 2

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsMfTXTB.jpg)

3.1 巴科斯范式

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsgx51Wp.jpg)

3.2 实战：使用 bison 做语法分析

例子：/home/git/study/php_bottom/chapter5/calc.y

### 4.PHP7中词法和语法分析

l Zend/zend_language_scanner.l

l Zend/zend_language_parser.y

4.1 ast 相关数据结构

l _zend_ast

l _zend_ast_list

l _zend_ast_zval

l _zend_ast_decl

4.2 实战：php7 词法分析过程

例子：/home/git/study/php_bottom/chapter5/a.php

4.3 实战：PHP7 语法分析过程

例子：/home/git/study/php_bottom/chapter5/a.php

### 5. AST的编译

l $a = 1;

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsrzvCiL.jpg)

5.1 opcode 相关的数据结构

l Struct _zend_op

l Struct _zend_op_array

l Struct _zend_execute_data

l Struct _zend_vm_stack

5.2 AST 编译成指令集

### 6.Zend虚拟机

6.1 基础

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsd2Np2M.jpg)

6.2 Zend 虚拟机的执行

## 5. 基本语法实现的原理

### 1.break 语法

1.1 生成的 AST

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps2TpDdd.jpg)

1.2 栈、符号表和常量

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsYgcf01.jpg)

1.3 指令集

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpshZrlD2.jpg)

1.4 执行过程

实例：/home/git/study/php_bottom/chapter6/break.php

### 2. include 语法

2.1 生成的 AST

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps0PbJiq.jpg)

2.2 栈、符号表和常量

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsQNWyOO.jpg)

2.3 指令集

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpspfcXcn.jpg)

2.4 执行过程

例子：/home/git/study/php_bottom/chapter6/2.php

生成的 AST

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wps1C8v2j.jpg)

指令集

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpskkEZLc.jpg)

### 3.if 语法

3.1 生成的 AST

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsZkrnsT.jpg)

3.2 栈、符号表和常量

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsOtNdty.jpg)

3.3 指令集

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsMkTSZM.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpstjfcfo.jpg)

3.4 执行过程

例子：/home/git/study/php_bottom/chapter6/condition.php

### 4.foreach 语法

4.1 生成的 AST

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsDI3Ioo.jpg)

4.2 栈、符号表和常量

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsOydwYy.jpg)

4.3 指令集

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsDjKySE.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsV2XuWa.jpg)

4.4 执行过程

## 6. PHP扩展的编写

### 实现 helloworld 扩展

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/sourceCode/php/wpsfTzjCd.jpg) 
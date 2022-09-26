---
title: "PHP-web和框架(三):PHP-CGI/PHP-FPM"
date: 2022-05-05
tags: [PHP-web和框架]
categories: [编程, PHP]
cover: false
---

### CGI与FastCGI

`CGI`程序：

`CGI`程序的每一次web请求都会有启动和退出的过程，也就是最为人诟病的`fork-and-execute`模式（每次HTTP服务器遇到动态请求时都需要重新启动脚本解析器来解析`php.ini`，重新载入全部DLL扩展并初始化全部数据结构，然后把结果返回给HTTP服务器），很明显，这样的接口方式会导致`php`的性能很差，在处理高并发访问时，几乎是不可用的。所以，高并发时`CGI`程序的性能较差。

`FastCGI`程序：

1. Web Server启动的同时，加载`FastCGI`进程管理器（nginx的php-fpm/IIS的ISAPI/Apache的Module)

2. `FastCGI`进程管理器读取`php.ini`配置文件，对自身进行初始化，启动多个`CGI`解释器进程（`PHP-CGI`），等待来自Web Server的连接。

3. 当Web Server接收到客户端请求时，`FastCGI`进程管理器选择并连接到一个`CGI`解释器进程。Web Server会将相关环境变量和标准输入发送到`FastCGI`子进程即`PHP-CGI`进行处理。

4. `PHP-CGI`完成处理后将数据按照`CGI`规定的格式返回给Web Server，然后关闭或者等待下一次请求。

`FastCGI`对进程的管理：

`FastCGI`会先启动一个master进程，解析配置文件，初始化执行环境，然后再启动多个worker进程。当请求过来时，master进程会传递给一个worker进程，然后立即可以接受下一个请求。这样就避免了重复的劳动，效率自然提高。而且当worker进程不够用时，master进程可以根据配置预先启动几个worker进程等着；当空闲worker进程太多时，也会停掉一些，这样就提高了性能，也节约了资源。这就是`FastCGI`对进程的管理。

总结：

1. `CGI` 和 `FastCGI` 都只是一种通信协议规范，不是一个实体，一般说的CGI指的是用各种语言编写的能实现该功能的程序。

2. `CGI` 程序和`FastCGI`程序，是指实现这两个协议的程序，可以是任何语言实现这个协议的。（`PHP-CGI` 是使用PHP实现`CGI`协议的`CGI`程序， `PHP-FPM`是使用PHP实现`FastCGI`协议的`FastCGI`程序）。

3. CGI程序和FastCGI程序的区别：

关于`CGI`程序：
`CGI`使外部程序与Web Server之间交互成为可能。`CGI`程序运行在独立的进程中，并对每个Web请求建立一个进程，这种方法非常容易实现，但效率很差，难以扩展。面对大量请求，进程的大量创建和销毁会使操作系统性能大大下降。此外，由于地址空间无法共享，也限制了资源重用。

关于`FastCGI`程序： 与`CGI`程序为每个请求创建一个新的进程不同，`FastCGI`使用持续的进程（master）来处理一连串的请求。这些进程由`FastCGI`服务器管理，而不是web服务器。当进来一个请求时，web服务器把环境变量和这个页面请求通过一个socket或者一个TCP connection传递给`FastCGI`进程。

### PHP-CGI与PHP-FPM

- PHP-CGI是PHP脚本解析器，它是CGI协议的实现

- PHP-FPM是FastCGI协议的实现

- PHP-CGI和PHP-FPM都是程序

### CGI和FastCGI的执行流程

CGI：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/php/wpsteZWYy.jpg)

FastCGI:

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/php/wps7lEFP8.jpg) 
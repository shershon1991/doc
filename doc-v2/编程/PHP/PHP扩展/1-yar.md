---
title: "php扩展(一):yar"
date: 2022-09-10 22:26:25 
cover: false 
tags: [PHP扩展]
categories: [编程, PHP]
---

## 介绍

`Yar` 是一个 `RPC` 框架，它提供了一种简单易用的方式来在 `PHP` 应用程序之间进行通信，它还提供了同时对远程服务进行多个调用的能力。

## 特征

- 快速、简单
- 并发 RPC 调用
- 支持多种数据打包器（php、json、msgpack 内置）
- 支持多种传输协议（http、https、TCP）
- 详细的调试信息

扩展地址如以下,截止到(2022.09.10):

| 包                                                           | 文档                                                     | Star 数量 | 说明     |
| ------------------------------------------------------------ |--------------------------------------------------------|------| -------- |
| [laruence/yar](https://github.com/laruence/yar.git)         | https://github.com/laruence/yar/blob/master/README.md  | 1.4k | 鸟哥提供 |

## 安装

### 安装yar

Yar 是一个 PECL 扩展，可以简单地通过以下方式安装：
`pecl install yar`

### 在 Linux 中编译 Yar

```sh
$ /path/to/phpize
$ ./configure --with-php-config=/path/to/php-config/
$ make && make install
```

可用的配置说明

```sh
--with-curl=DIR
--enable(disable)-msgpack
--enable(disable)-epoll (require Yar 2.1.2)
```

### 使用 msgpack 安装 Yar

1.为 PHP 扩展安装 msgpack：
`pecl install msgpack`
或者对于 ubuntu 用户
`apt-get install msgpack-php`
或者，可以在此处获取 github 源：[https ://github.com/msgpack/msgpack-php](https ://github.com/msgpack/msgpack-php)

2.配置：

```sh
$phpize
$configure --with-php-config=/path/to/php-config/ --enable-msgpack
$make && make install
```

## 使用

[查看源码](https://github.com/shershon1991/self-api-template/tree/master/common/rpc)

### 服务器端

设置 Yar HTTP RPC 服务器非常容易

```php
<?php

namespace common\rpc;

// 服务器端example
class YarServer
{
    /**
     * the doc info will be generated automatically into service info page.
     * @params
     * @param $parameter
     * @param string $option
     * @return void
     */
    public function some_method($parameter, $option = "foo")
    {
        return $parameter;
    }

    public function some_other_method1($parameter, $option = "foo")
    {
        return $parameter;
    }

    public function some_other_method2($parameter, $option = "foo")
    {
        return $parameter;
    }

    public function some_other_method3($parameter, $option = "foo")
    {
        return $parameter;
    }

    protected function client_can_not_see()
    {
    }
}
```

### 客户端

PHP 客户端调用远程 RPC 非常简单：

#### 同步调用

```php
// 1.同步调用
$client = new Yar_Client("http://self-api.shershon.top/index.php?c=yar&a=server");
$client->setOpt(YAR_OPT_CONNECT_TIMEOUT, 1000);
$client->setOpt(YAR_OPT_HEADER, ["hd1: val", "hd2: val"]);
var_dump($client->some_method("parameter"));
```

#### 并发调用

```php
// 2.并发调用
// 调用
\Yar_Concurrent_Client::call("http://self-api.shershon.top/index.php?c=yar&a=server", "some_method", ["parameters"]);
\Yar_Concurrent_Client::call("http://self-api.shershon.top/index.php?c=yar&a=server", "some_other_method1", ["parameters"], 'callback');
\Yar_Concurrent_Client::call("http://self-api.shershon.top/index.php?c=yar&a=server", "some_other_method2", ["parameters"], 'callback', 'callError');
// 发送请求
\Yar_Concurrent_Client::loop(['YarClient', 'loopCallback'], ['YarClient', 'loopError']);
function callback($retval, $callinfo)
{
    echo 'call自己的回调：' . $callinfo['method'] . '，方法返回数据' . $retval . PHP_EOL;
}

function callError()
{
    echo '发送rpc出错' . PHP_EOL;
}

// 错误回掉函数, 如果设置了, Yar在发送出所有的请求之后立即调用一次这个回掉函数(此时还没有任何请求返回), 调用的时候$callinfo参数是NULL
function loopCallback($retval, $callinfo)
{
    if (is_null($callinfo)) {
        echo '所有rpc请求发送完毕调用' . PHP_EOL;
    } else {
        echo '调用成功后返回' . PHP_EOL;
        var_dump($retval);
        var_dump($callinfo);
    }
}

// 错误回掉函数, 如果设置了, 那么Yar在出错的时候会调用这个回掉函数
function loopError()
{
    echo '发送rpc出错' . PHP_EOL;
}
```

#### 持续通话

```php
// 3.持续通话
$client = new Yar_Client("http://self-api.shershon.top/index.php?c=yar&a=server");
$client->SetOpt(YAR_OPT_PERSISTENT, 1);
var_dump($client->some_method("parameter"));
var_dump($client->some_other_method1("parameter"));
var_dump($client->some_other_method2("parameter"));
var_dump($client->some_other_method3("parameter"));
```
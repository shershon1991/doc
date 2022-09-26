---
title: "Yii2集成(二):yar"
date: 2022-09-18 
cover: false 
tags: [Yii2集成]
categories: [编程, PHP]
---

## 介绍

`Yar` 是一个 `RPC` 框架，它提供了一种简单易用的方式来在 `PHP` 应用程序之间进行通信，同时它还提供了对远程服务进行多个调用的能力。

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

## 集成代码

[查看源码](https://github.com/shershon1991/yii-api-template)

### 服务器端

设置 Yar HTTP RPC 服务器非常容易：

文件位置：`common/rpc/YarServer.php`

```php
<?php

namespace app\common\rpc;

use Exception;

/**
 * YarServer
 */
class YarServer
{

    /**
     * ip
     * @var string[]
     */
    private $ipArr = ['172.24.0.1'];

    /**
     * 密码
     * @var string
     */
    private $password = 'shershon-rpc-token';

    /**
     * 有效时间
     * @var int
     */
    private $activeTime = 1440;

    public function server($params)
    {
        try {
            $rpcToken = $params['rpc_token'] ?? '';
            $data     = $this->rpcDecode($rpcToken);
            if (!$this->auth($data)) {
                throw new Exception('认证失败');
            }
            $server = new \Yar_Server(new $data['class']());
            $server->handle();
            exit();
        } catch (Exception $e) {
            return ['code' => -1, 'msg' => $e->getMessage(), 'data' => []];
        }
    }

    /**
     * 权限认证
     *
     * @param $param
     * @return bool
     */
    public function auth($param)
    {
        if (!$param) {
            return false;
        }
        //验证IP
        /*if (!in_array(Yii::$app->request->userIP, $this->ipArr)) {
            return false;
        }*/
        //有效时间
        if ((time() - $param['time']) > $this->activeTime) {
            return false;
        }
        //验证密码
        if ($param['password'] !== $this->password) {
            return false;
        }
        if (empty($param['class'])) {
            return false;
        }
        return true;
    }

    /**
     * 解密
     *
     * @param $str
     * @return array|mixed
     */
    public function rpcDecode($str)
    {
        if ($str) {
            return json_decode(base64_decode($str), true);
        }
        return [];
    }
}
```

### 客户端

PHP 客户端调用远程 RPC 非常简单：

文件位置：`common/rpc/YarApi.php`

```php
<?php

namespace app\common\rpc;

/**
 * Yar rpc client
 */
class YarApi
{
    /**
     * 密码
     * @var string
     */
    private $password = 'shershon-rpc-token';

    public function api(array $condition)
    {
        $defult    = [
            'url'   => 'http://yii-api.shershon.top/index.php?r=yar/rpc-server', //服务器URL
            'class' => '', //class名称
        ];
        $condition = array_merge($defult, $condition);

        $data             = [];
        $data['time']     = time();
        $data['password'] = $this->password;
        $data['class']    = $condition['class'];

        return new \Yar_Client("{$condition['url']}&rpc_token={$this->rpcEncode($data)}");
    }

    /**
     * 加密
     *
     * @param array $data
     * @return string
     */
    private function rpcEncode(array $data)
    {
        return base64_encode(json_encode($data));
    }
}
```

### 添加模型方法

添加模型方法，PHP客户端可以在远程调用：

文件位置：`models/User.php`

```php
public function selAll()
{
    return self::$users;
}
```

## 简单使用

### 本地启动Yii Server

项目根目录下执行`php yii serve --port=8888`

### 创建测试路由

文件位置：`controllers/YarController.php`

```php
<?php

namespace app\controllers;

use app\common\rpc\YarServer;
use Yii;
use yii\web\Controller;
use app\common\rpc\YarApi;

class YarController extends Controller
{
    /**
     * 关闭csrf
     * @var bool
     */
    public $enableCsrfValidation = false;

    public function actionRpcCall()
    {
        $condition = ['class' => '\app\models\User'];
        $yar       = new YarApi();
        $client    = $yar->api($condition);
        $response  = [
            'code' => 200,
            'msg'  => 'success',
            'data' => $client->selAll()
        ];
        return $this->asJson($response);
    }

    public function actionRpcServer()
    {
        $params    = Yii::$app->request->get();
        $yarServer = new YarServer();
        $response  = $yarServer->server($params);
        return $this->asJson($response);
    }
}
```

### 请求实例

```bash
➜  yii-api-template git:(master) curl http://localhost:8888/index.php\?r\=yar/rpc-call
{"code":200,"msg":"success","data":{"100":{"id":"100","username":"admin","password":"admin","authKey":"test100key","accessToken":"100-token"},"101":{"id":"101","username":"demo","password":"demo","authKey":"test101key","accessToken":"101-token"}}}
```
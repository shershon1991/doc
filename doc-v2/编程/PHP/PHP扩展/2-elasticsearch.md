---
title: "php扩展(二):elasticsearch"
date: 2022-09-14
cover: false 
tags: [PHP扩展]
categories: [编程, PHP]
---

## 介绍

`PHP` 原生代码连接 `elasticsearch` 需要通过客户端进行连接。`elasticsearch` 官方提供的客户端如下（截止到2022.09.12）：

| 包 | 文档 | star数量 | 说明                |
| ---- | ---- |-----|-------------------|
| [elastic/elasticsearch-php](https://github.com/elastic/elasticsearch-php) | https://github.com/elastic/elasticsearch-php/blob/master/README.md | 5k+ | elasticsearch官方提供 |

## 安装

安装此扩展包的首选方法是通过`composer`，并保证客户端版本和服务器端版本一致。这里服务器端的 `elasticsearch` 版本为 `7.13.3`。

`composer require elasticsearch/elasticsearch:"v7.17.0"`

## 配置

[查看源码](https://github.com/shershon-php-package/php-tools)

`ClientBuilder` 安装后，使用该类连接到 `Elasticsearch` 。本地的 `Elasticsearch` 正在运行， IP和端口为：127.0.0.1:9200。可以使用以下代码创建客户端：

文件位置：`src/Client/ElasticClient.php`

```php
<?php

namespace PhpTools\Client;

use Elasticsearch\Client;
use Elasticsearch\ClientBuilder;
use Exception;

class ElasticClient
{
    /**
     * es的配置
     * @var string
     */
    private static $_config;

    /**
     * es的连接池
     * @var object
     */
    private static $_client;

    /**
     * 获取连接es的单例
     *
     * @param $config
     * @return Client
     * @throws Exception
     */
    public static function getInstance($config): Client
    {
        // 首先确认已安装composer包: elasticsearch/elasticsearch

        $instanceKey = md5(serialize($config));
        if (!isset(self::$_client[$instanceKey])) {
            self::$_config = [
                'host' => $config['host'],
                'port' => $config['port'],
            ];
            if (!empty($config)) {
                $config = array_merge(self::$_config, $config);
            } else {
                $config = self::$_config;
            }
            if (!$config['host'] || !$config['port']) {
                throw new Exception('unknown host or port');
            }

            self::$_client[$instanceKey] = ClientBuilder::create()
                ->setHosts(["{$config['host']}:{$config['port']}"])
                ->build();
        }
        return self::$_client[$instanceKey];
    }
}
```

## 集成代码

### 操作类封装

文件位置：`src/ElasticTools.php`

```php 
<?php

namespace PhpTools;

use Exception;
use PhpTools\Client\ElasticClient;

/**
 * Desc: ElasticSearch相关操作
 * Author: Shershon
 * DateTime: 2022/8/16 23:16
 */
class ElasticTools
{
    protected $indexName;

    protected $client;

    public function __construct($indexName)
    {
        $this->indexName = $indexName;
        $config          = [
            'host' => '127.0.0.1',
            'port' => '9200',
        ];
        $this->client    = ElasticClient::getInstance($config);
    }

    /**
     * 初始化索引参数
     *
     * @return array
     */
    public function initParams()
    {
        return [
            'index' => $this->indexName,
        ];
    }

    /**
     * 创建索引
     *
     * @return array
     */
    public function createIndex()
    {
        $initParams['index'] = $this->indexName;
        return $this->client->indices()->create($initParams);
    }

    /**
     * 删除索引
     *
     * @return array
     */
    public function deleteIndex()
    {
        $initParams['index'] = $this->indexName;
        return $this->client->indices()->delete($initParams);
    }

    /**
     * 添加映射
     *
     * @param $map
     * @return array
     */
    public function setMapping($map)
    {
        $initParams         = $this->initParams();
        $initParams['body'] = $map;
        return $this->client->index($initParams);
    }

    /**
     * 获取映射
     *
     * @return array
     */
    public function getMapping()
    {
        $initParams = $this->initParams();
        return $this->client->indices()->getMapping($initParams);
    }

    /**
     * 向索引中插入数据
     *
     * @param $data
     * @return bool
     */
    public function insert($data)
    {
        $params = $this->initParams();
        isset($data['id']) && $params['id'] = $data['id'];
        $params['body'] = $data['body'];
        $res            = $this->client->index($params);
        if (!isset($res['_shards']['successful']) || !$res['_shards']['successful']) {
            return false;
        }
        return true;
    }

    /**
     * 批量插入数据
     *
     * @param $data
     * @return array|callable|false
     */
    public function bulk($data)
    {
        if (empty($data['body'])) return false;
        return $this->client->bulk($data);
    }

    /**
     * 根据唯一id删除
     *
     * @param $id
     * @return bool
     */
    public function deleteById($id)
    {
        $params       = $this->initParams();
        $params['id'] = $id;
        $res          = $this->client->delete($params);
        if (!isset($res['_shards']['successful'])) {
            return false;
        }
        return true;
    }

    /**
     * 根据唯一id更新
     *
     * @param $data
     * @return bool
     */
    public function updateById($data)
    {
        $params = $this->initParams();
        isset($data['id']) && $params['id'] = $data['id'];
        $params['body'] = $data['body'];
        $res            = $this->client->update($params);
        if (!isset($res['_shards']['successful'])) {
            return false;
        }
        return true;
    }

    /**
     * 根据唯一id查询数据
     *
     * @param $id
     * @return mixed
     * @throws Exception
     */
    public function searchById($id)
    {
        $params       = $this->initParams();
        $params['id'] = $id;
        return $this->client->get($params);
    }
}
```

## 简单使用

### 创建测试用例

文件位置：`tests/Cases/ElasticTest.php`

```php 
<?php

namespace ToolsTest\Cases;

use PhpTools\Client\ElasticClient;
use PhpTools\ElasticTools;
use PHPUnit\Framework\TestCase;

class ElasticTest extends TestCase
{
    // 获取es客户端
    public function testGetClient()
    {
        $indexName = 'php-test2';
        $elastic   = new ElasticTools($indexName);
        print_r($elastic);
    }

    // 创建索引
    public function testCreateIndex()
    {
        $indexName = 'php-test2';
        $elastic   = new ElasticTools($indexName);
        var_dump($elastic->createIndex());
    }

    // 删除索引
    public function testDeleteIndex()
    {
        $indexName = 'php-test2';
        $elastic   = new ElasticTools($indexName);
        var_dump($elastic->deleteIndex());
    }

    // 单条插入数据
    public function testInsertOneData()
    {
        $indexName    = 'php-test2';
        $elastic      = new ElasticTools($indexName);
        $data['id']   = 1;
        $data['body'] = ['name' => '张三', 'age' => 20, 'height' => 170];
        var_dump($elastic->insert($data));
    }

    // 批量插入数据
    public function testInsertBatchData()
    {
        $indexName = 'php-test2';
        $elastic   = new ElasticTools($indexName);
        for ($i = 0; $i < 5; $i++) {
            $data['body'][] = [
                'index' => [
                    '_index' => $indexName,
                    '_id'    => ($i + 1),
                ],
            ];
            $data['body'][] = [
                'name'   => 'user' . ($i + 1),
                'age'    => 30,
                'height' => 180,
            ];
        }
        var_dump($elastic->bulk($data));
    }

    // 根据ID删除数据
    public function testDeleteById()
    {
        $indexName = 'php-test2';
        $elastic   = new ElasticTools($indexName);
        var_dump($elastic->deleteById('1'));
    }

    // 根据ID更新数据
    public function testUpdateById()
    {
        $indexName    = 'php-test2';
        $elastic      = new ElasticTools($indexName);
        $data['id']   = 2;
        $data['body'] = [
            'doc' => [
                'age' => '31'
            ]
        ];
        var_dump($elastic->updateById($data));
    }

    // 根据ID查询数据
    public function testGetById()
    {
        $config   = [
            'host' => '127.0.0.1',
            'port' => '9200',
        ];
        $elastic  = ElasticClient::getInstance($config);
        $params   = [
            'index' => 'php-test2',
            'id'    => '2'
        ];
        $response = $elastic->get($params);
        print_r($response);
    }
}
```

### 请求示例

#### 创建索引

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testCreateIndex
 {
      ["acknowledged"]=>
      bool(true)
      ["shards_acknowledged"]=>
      bool(true)
      ["index"]=>
      string(9) "php-test2"
 }
```

#### 删除索引

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testDeleteIndex
 {
      ["acknowledged"]=>
      bool(true)
 }
```

#### 单条插入数据

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testInsertOneData
bool(true)
```

#### 批量插入数据

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testInsertBatchData
{
  ["took"]=>
  int(9)
  ["errors"]=>
  bool(false)
  ["items"]=>
  array(5) {
    [0]=>
    array(1) {
      ["index"]=>
      array(9) {
        ["_index"]=>
        string(9) "php-test2"
        ["_type"]=>
        string(4) "_doc"
        ["_id"]=>
        string(1) "1"
        ["_version"]=>
        int(2)
        ["result"]=>
        string(7) "updated"
        ["_shards"]=>
        array(3) {
          ["total"]=>
          int(2)
          ["successful"]=>
          int(1)
          ["failed"]=>
          int(0)
        }
        ["_seq_no"]=>
        int(1)
        ["_primary_term"]=>
        int(1)
        ["status"]=>
        int(200)
      }
    }
    [1]=>
    array(1) {
      ["index"]=>
      array(9) {
        ["_index"]=>
        string(9) "php-test2"
        ["_type"]=>
        string(4) "_doc"
        ["_id"]=>
        string(1) "2"
        ["_version"]=>
        int(1)
        ["result"]=>
        string(7) "created"
        ["_shards"]=>
        array(3) {
          ["total"]=>
          int(2)
          ["successful"]=>
          int(1)
          ["failed"]=>
          int(0)
        }
        ["_seq_no"]=>
        int(2)
        ["_primary_term"]=>
        int(1)
        ["status"]=>
        int(201)
      }
    }
    [2]=>
    array(1) {
      ["index"]=>
      array(9) {
        ["_index"]=>
        string(9) "php-test2"
        ["_type"]=>
        string(4) "_doc"
        ["_id"]=>
        string(1) "3"
        ["_version"]=>
        int(1)
        ["result"]=>
        string(7) "created"
        ["_shards"]=>
        array(3) {
          ["total"]=>
          int(2)
          ["successful"]=>
          int(1)
          ["failed"]=>
          int(0)
        }
        ["_seq_no"]=>
        int(3)
        ["_primary_term"]=>
        int(1)
        ["status"]=>
        int(201)
      }
    }
    [3]=>
    array(1) {
      ["index"]=>
      array(9) {
        ["_index"]=>
        string(9) "php-test2"
        ["_type"]=>
        string(4) "_doc"
        ["_id"]=>
        string(1) "4"
        ["_version"]=>
        int(1)
        ["result"]=>
        string(7) "created"
        ["_shards"]=>
        array(3) {
          ["total"]=>
          int(2)
          ["successful"]=>
          int(1)
          ["failed"]=>
          int(0)
        }
        ["_seq_no"]=>
        int(4)
        ["_primary_term"]=>
        int(1)
        ["status"]=>
        int(201)
      }
    }
    [4]=>
    array(1) {
      ["index"]=>
      array(9) {
        ["_index"]=>
        string(9) "php-test2"
        ["_type"]=>
        string(4) "_doc"
        ["_id"]=>
        string(1) "5"
        ["_version"]=>
        int(1)
        ["result"]=>
        string(7) "created"
        ["_shards"]=>
        array(3) {
          ["total"]=>
          int(2)
          ["successful"]=>
          int(1)
          ["failed"]=>
          int(0)
        }
        ["_seq_no"]=>
        int(5)
        ["_primary_term"]=>
        int(1)
        ["status"]=>
        int(201)
      }
    }
  }
}
```

#### 根据ID删除数据

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testDeleteById
bool(true)
```

#### 根据ID更新数据

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testUpdateById
bool(true)
```

#### 根据ID查询数据

```bash
➜  php-tools git:(master) phpunit -c phpunit.xml --colors=always tests/Cases/ElasticTest.php --filter testGetById
array(8) {
  ["_index"]=>
  string(9) "php-test2"
  ["_type"]=>
  string(4) "_doc"
  ["_id"]=>
  string(1) "2"
  ["_version"]=>
  int(2)
  ["_seq_no"]=>
  int(7)
  ["_primary_term"]=>
  int(1)
  ["found"]=>
  bool(true)
  ["_source"]=>
  array(3) {
    ["name"]=>
    string(5) "user2"
    ["age"]=>
    string(2) "31"
    ["height"]=>
    int(180)
  }
}
```
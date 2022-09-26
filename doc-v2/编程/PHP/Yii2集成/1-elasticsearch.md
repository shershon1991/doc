---
title: "Yii2集成(一):elasticsearch"
date: 2022-09-12 
cover: false 
tags: [Yii2集成]
categories: [编程, PHP]
---

## 介绍

`yii2`中使用`elasticsearch`需要集成扩展包。官方提供的基于yii2框架的扩展包如下（截止到2022.09.12）：

| 包 | 文档 | star数量 | 说明 |
| ---- | ---- | ---- | ---- |
| [yiisoft/yii2-elasticsearch](https://github.com/yiisoft/yii2-elasticsearch) | https://github.com/yiisoft/yii2-elasticsearch/blob/master/README.md | 416 | yii官方提供 |

## 安装

安装此扩展包的首选方法是通过`composer`
`composer require --prefer-dist yiisoft/yii2-elasticsearch:"~2.1.0"`

## 配置

要使用此扩展，必须在应用程序配置中配置`Connection`类：

文件位置：`config/web.php`

```php
return [
    //...
    'elasticsearch7' => [
        'class'             => 'yii\elasticsearch7\Connection',
        'autodetectCluster' => false,
        'connectionTimeout' => 2,
        'dataTimeout'       => 2,
        'nodes'             => [
            [
                'http_address' => '127.0.0.1:9200',
            ],
        ],
        'dslVersion'        => 7
    ]
];
```

## 集成代码

### 基类封装

`Elasticsearch ActiveRecord` 与数据库中的 `ActiveRecord` 非常相似它。的大部分限制和差异都源自 [[yii\elasticsearch\Query]] 实现。
要定义 `Elasticsearch ActiveRecord` 类，您的记录类需要从 [[yii\elasticsearch\ActiveRecord]]
扩展并至少实现 [[yii\elasticsearch\ActiveRecord::attributes()|attributes()]] 方法来定义属性的记录。

文件位置：`common/base/ElasticsearchBase.php`

```php 
<?php

namespace app\common\base;

use yii\elasticsearch7\ActiveRecord;

abstract class ElasticsearchBase extends ActiveRecord
{

    /**
     * 定义db链接
     *
     * @return object|\yii\elasticsearch7\Connection|null
     * @throws \yii\base\InvalidConfigException
     */
    public static function getDb()
    {
        return \Yii::$app->get('elasticsearch7');
    }

    /**
     * 分片设置
     *
     * @return array
     */
    public static function indexShards()
    {
        return [
            "settings" => [
                "number_of_shards"   => 2,  //2主分片
                "number_of_replicas" => 1 //1副本
            ]
        ];
    }

    public abstract static function mapConfig();

    public function attributes()
    {
        $mapConfig = static::mapConfig();
        return array_keys($mapConfig['properties']);
    }

    /**
     * 创建索引
     *
     * @return mixed
     * @throws \yii\base\InvalidConfigException
     */
    public static function createIndex()
    {
        $db      = static::getDb();
        $command = $db->createCommand();
        return $command->createIndex(static::index(), static::indexShards());
    }

    /**
     * 删除索引
     *
     * @return mixed
     * @throws \yii\base\InvalidConfigException
     */
    public static function deleteIndex()
    {
        $db      = static::getDb();
        $command = $db->createCommand();
        return $command->deleteIndex(static::index());
    }

    /**
     * 添加配置的映射
     *
     * @return bool
     * @throws \yii\base\InvalidConfigException
     */
    public static function createMapping()
    {
        $db      = static::getDb();
        $command = $db->createCommand();
        if (!$command->indexExists(static::index())) {
            $command->createIndex(static::index(), static::indexShards());
        }
        $command->setMapping(static::index(), static::type(), static::mapConfig());
        return true;
    }

    /**
     * 更新配置的映射
     *
     * @param $properties
     * @return mixed|void
     * @throws \yii\base\InvalidConfigException
     */
    public static function updateMapping($properties)
    {
        if (empty($properties) || !is_array($properties)) {
            return;
        }
        $db      = static::getDb();
        $command = $db->createCommand();
        if (!$command->indexExists(static::index())) {
            $command->createIndex(static::index(), static::indexShards());
        }
        return $command->setMapping(static::index(), static::type(), $properties);
    }

    /**
     * 获取映射
     *
     * @return mixed
     * @throws \yii\base\InvalidConfigException
     */
    public static function getMapping()
    {
        $db      = static::getDb();
        $command = $db->createCommand();
        return $command->getMapping(static::index());
    }
}
```

### 模型类封装

模型类需要从基类继承，并实现基类的抽象方法 `mapConfig()`。

```php 
<?php

namespace app\models;

use app\common\base\ElasticsearchBase;

class TestEs extends ElasticsearchBase
{
    public static $currentIndex;

    public static function index()
    {
        return 'php-test';
    }

    public static function type()
    {
        return 'user';
    }

    public static function mapConfig()
    {
        return [
            'properties' => [
                'id'    => [
                    'type' => 'integer',
                ],
                'name'  => [
                    'type' => 'keyword',
                ],
                'age'   => [
                    'type' => 'integer',
                ],
                'birth' => [
                    'type' => 'date',
                ],
            ]
        ];
    }

    /**
     * 删除一条数据
     *
     * @param $id
     * @return mixed
     * @throws \yii\base\InvalidConfigException
     */
    public static function deleteById($id)
    {
        $db      = self::getDb();
        $command = $db->createCommand();
        return $command->delete(self::index(), self::type(), $id);
    }

    /**
     * 获取列表
     *
     * @param $where
     * @return TestEs|array|bool|mixed|\yii\elasticsearch7\ActiveRecord|null
     */
    public static function getList($where)
    {
        return self::findOne($where)->toArray();
    }
}

```

## 简单使用

### 创建测试方法

文件位置：`controllers/EsController.php`

```php 
<?php

namespace app\controllers;

use app\models\TestEs;
use yii\web\Controller;

class EsController extends Controller
{
    // 创建索引
    public function actionCreateIndex()
    {
        var_dump(TestEs::createIndex());
    }

    // 删除索引
    public function actionDeleteIndex()
    {
        var_dump(TestEs::deleteIndex());
    }

    // 添加配置的映射
    public function actionCreateMap()
    {
        var_dump(TestEs::createMapping());
    }

    // 更新配置的映射
    public function actionUpdateMap()
    {
        $properties = [];
        var_dump(TestEs::updateMapping($properties));
    }

    // 获取配置的映射
    public function actionGetMap()
    {
        var_dump(TestEs::getMapping());
    }

    // 插入数据
    public function actionInsertData()
    {
        $model = new TestEs();

        // 单条插入
        $data1 = ['id' => 1, 'name' => '小谭', 'age' => 31, 'birth' => '1991-04-14'];
        $res1  = $model->saveOne($data1);
        var_dump($res1);

        // 批量插入
        $data2 = [
            ['id' => 2, 'name' => '小张', 'age' => 20, 'birth' => '1992-05-23'],
            ['id' => 3, 'name' => '小李', 'age' => 25, 'birth' => '1993-04-20'],
        ];
        $res2  = $model->bulk($data2);
        var_dump($res2);
    }

    // 删除数据
    public function actionDelData()
    {
        var_dump(TestEs::deleteById(1));
    }

    // 查询数据
    public function actionGetData()
    {
        $where = ['=', 'id', 2];
        var_dump(TestEs::getList($where));
    }
}
```

### 请求示例

1.启动服务

```bash
1.通过docker启动elasticsearch服务
2.启动yii服务
➜  yii-api-template git:(master) php yii serve --port=8888
```

2.请求

```bash
➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/delete-index
array(1) {
  ["acknowledged"]=>
  bool(true)
}

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/create-index
array(3) {
  ["acknowledged"]=>
  bool(true)
  ["shards_acknowledged"]=>
  bool(true)
  ["index"]=>
  string(8) "php-test"
}

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/create-map
bool(true)

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/get-map
array(1) {
  ["php-test"]=>
  array(1) {
    ["mappings"]=>
    array(1) {
      ["properties"]=>
      array(4) {
        ["age"]=>
        array(1) {
          ["type"]=>
          string(7) "integer"
        }
        ["birth"]=>
        array(1) {
          ["type"]=>
          string(4) "date"
        }
        ["id"]=>
        array(1) {
          ["type"]=>
          string(7) "integer"
        }
        ["name"]=>
        array(1) {
          ["type"]=>
          string(7) "keyword"
        }
      }
    }
  }
}

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/insert-data
bool(true)
int(2)

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/del-data
array(8) {
  ["_index"]=>
  string(8) "php-test"
  ["_type"]=>
  string(4) "_doc"
  ["_id"]=>
  string(1) "1"
  ["_version"]=>
  int(2)
  ["result"]=>
  string(7) "deleted"
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
}

➜  docker-compose-server git:(master) curl -X GET http://localhost:8888\?r=es/get-data
array(4) {
  ["id"]=>
  int(2)
  ["name"]=>
  string(6) "小张"
  ["age"]=>
  int(20)
  ["birth"]=>
  string(10) "1992-05-23"
}
```
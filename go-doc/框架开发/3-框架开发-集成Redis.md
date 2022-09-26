---
title: "框架开发(三):框架开发-集成Redis"
date: 2021-06-03
draft: false
tags: [框架开发]
categories: [编程, Go]
---

### 1.客户端介绍

`redis`官网推荐使用`redigo`(`https://github.com/gomodule/redigo`)，截止到今天`Github Start是8.2k` 但`go-redis(https://github.com/go-redis/redis)`使用的人更多， 并且`go-redis`封装得更好。截止到今天`Github Start 是10.8k`。

### 2.安装

```go
go get github.com/go-redis/redis/v8
```

### 3.编写配置

#### 3.1 编写配置文件

**文件:**`app/config/*.ini`

```ini
...
[redis]
host=127.0.0.1
port=6379
# 密码
password=
# 默认DB
default_db=0
...
```

#### 3.2 编写Redis配置结构

**文件:**`app/config/config.go`

```go
/**
 * @description: Redis配置信息
 * @user: Shershon
 */
type RedisConfig struct {
	Host      string `ini:"host"`
	Port      string `ini:"port"`
	DefaultDB string `ini:"default_db"`
	Password  string `ini:"password"`
}
```

### 4.初始化客户端

#### 4.1 创建全局Redis客户端

```go
var RedisClient  *redis.Client
```

#### 4.2 建立连接

```go
/**
 * @description: 连接Redis
 * @user: Shershon
 * @date 2021-02-23 17:06:27
 */
func connectRedis() {
	RedisClient = redis.NewClient(&redis.Options{
		Addr:     RedisConfigInstance.Host + ":" + RedisConfigInstance.Port,
		Password: RedisConfigInstance.Password, // 密码
		DB:       RedisConfigInstance.DefaultDB, // 默认数据库
		PoolSize: RedisConfigInstance.PoolSize, // 连接池大小
	})
	// 设置连接超时时间
	duration, err := time.ParseDuration(RedisConfigInstance.TimeOut)
	ctx, cancelFunc := context.WithTimeout(context.Background(), duration)
	defer cancelFunc()
	result, err := RedisClient.Ping(ctx).Result()
	fmt.Println("redis: " + result)
	BusErrorInstance.ThrowError(err)
}
```

### 5.使用

**源码文件**：https://github.com/52lu/goe/blob/master/app/controllers/v1/redis.go

#### 5.1 Set & Get

```go
var ctx = context.Background()
func (r RedisController) Normal() error  {
	opType := r.GetParam("opType")
	key := r.GetParam("key")
	if opType == "1" {
		// Set
		val := r.GetParam("val")
		err := RedisClient.Set(ctx, key, val, time.Second * 60).Err()
		if err != nil {
			return r.Error("Set: " + err.Error())
		}
		return r.Success(nil)
	} else  {
		// Get
		result, err := RedisClient.Get(ctx, key).Result()
		if err == redis.Nil {
			return r.Error(key + " not exist")
		} else if err != nil {
			return r.Error("Get: " + err.Error())
		}
		return r.Success(result)
	}
}
```

#### 5.2 有序集合(Sorted Set)

```go
/**
* @description: 有序集合添加
* @user: Shershon
* @receiver r RedisController
*/
func (r RedisController) SortSet() error  {
	opType := r.GetParam("opType")
	key := r.GetParam("key")
	if opType == "1" {
		// 有序集合添加
		zs := []*redis.Z{
			{Member: "小张",Score: 88},
			{Member: "小李",Score: 90},
			{Member: "小明",Score: 80},
			{Member: "小英",Score: 70},
			{Member: "小赵",Score: 95},
			{Member: "小王",Score: 75},
			{Member: "笨蛋",Score: 40},
		}
		result, err := RedisClient.ZAdd(ctx, key, zs...).Result()
		if err != nil {
			return r.Error(err.Error())
		}
		return r.Success(result)
	} else  {
		resultMap := make(map[string]interface{})
		// 获取成员数
		val := RedisClient.ZCard(ctx, key).Val()
		resultMap["获取成员数"] = val
		// 获取指定分数区间的成员数
		resultMap["70分-90分成员数"] = RedisClient.ZCount(ctx, key, "70", "90").Val()
		// 返回有序集中指定分数区间内的成员，分数从高到低排序
		result, _ := RedisClient.ZRevRangeByScoreWithScores(ctx, key, &redis.ZRangeBy{
			Min: "0", Max: "100", Offset: 0, Count: 3,
		}).Result()
		resultMap["分数前三排名"] = result
		// 返回分数值
		f, _ := RedisClient.ZScore(ctx, key, "小张").Result()
		resultMap["小张的分数"] = f
		// 给笨蛋加60分
		f2, err := RedisClient.ZIncrBy(ctx, key, 60.0, "笨蛋").Result()
		fmt.Println(err)
		fmt.Printf("新分数:%v \n",f2)
		result2, _ := RedisClient.ZRevRangeByScoreWithScores(ctx, key, &redis.ZRangeBy{
			Min: "0", Max: "100", Offset: 0, Count: 3,
		}).Result()
		resultMap["调整分后排名"] = result2
		return r.Success(resultMap)
	}
```

#### 5.3 Hash操作

```go
/**
 * @description: 哈希类型操作
 * @user: Shershon
 * @receiver r RedisController
 * @return error
 */
func (r RedisController) Hash() error {
	//  将哈希表 key 中的字段 field 的值设为 value 。
	opType := r.GetParam("opType")
	result := make(map[string]interface{})
	if opType == "1" {
		// Hset:将哈希表 key 中的字段 field 的值设为 value 。
		err := RedisClient.HSet(ctx, "HSet-key", "field_name", "张三").Err()
		// HmSET:同时将多个 field-value (域-值)对设置到哈希表 key 中。
		err = RedisClient.HMSet(ctx, "HMSet-key", "field1","val1","field2","val2","field3","val3").Err()
		if err != nil {
			return  r.Error(err.Error())
		}
		return  r.Success(nil)
	} else {
		// HEXISTS:查看哈希表key中，指定的字段是否存在。
		res, err := RedisClient.HExists(ctx, "HSet-key", "field_name").Result()
		result["HExists"] = res
		// HGET:获取存储在哈希表中指定字段的值。
		s, err := RedisClient.HGet(ctx, "HMSet-key", "field2").Result()
		result["HGet"] = s
		//HGETALL:获取在哈希表中指定 key 的所有字段和值
		m, err := RedisClient.HGetAll(ctx, "HMSet-key").Result()
		result["HGet"] = m
		// Hkeys:获取所有哈希表中的字段
		strings, err := RedisClient.HKeys(ctx, "HMSet-key").Result()
		result["HKeys"] = strings
		// HVALS:获取哈希表中所有值。
		i, err := RedisClient.HVals(ctx, "HMSet-key").Result()
		result["HVals"] = i
		// HMGET:获取所有给定字段的值
		i2, err := RedisClient.HMGet(ctx, "HMSet-key", "field1", "field2", "field3").Result()
		result["HMGet"] = i2
		if err != nil {
			return  r.Error(err.Error())
		}
		return  r.Success(result)
	}
}
```

#### 5.4 列表操作(List)

```go
/**
 * @description: 列表类型操作
 * @user: Shershon
 * @receiver r RedisController
 * @return error
 */
func (r RedisController) List() error {
	opType := r.GetParam("opType")
	key := "List:Rows"
	result := make(map[string]interface{})
	if opType == "1" {
		// LPUSH: 将一个或多个值插入到列表头部
		err := RedisClient.LPush(ctx, key, "PHP", "C", "GO", "JAVA", "PYTHON").Err()
		// RPUSH:将一个或多个值插入到列表的尾部
		err = RedisClient.LPush(ctx, key, "C++", "HTML").Err()
		if err != nil {
			return  r.Error(err.Error())
		}
	} else if opType == "2"  {
		// BLPOP:移出并获取列表的第一个元素(阻塞)
		duration, err := time.ParseDuration("10s")
		res, err := RedisClient.BLPop(ctx, duration, key).Result()
		result["BLPOP"] = res
		//BRPOP:移出并获取列表的最后一个元素(阻塞)
		strings, err := RedisClient.BRPop(ctx, duration, key).Result()
		result["BRPop"] = strings
		// LPOP:移出并获取列表的第一个元素
		s, err := RedisClient.LPop(ctx, key).Result()
		result["LPop"] = s
		// RPOP:移除列表的最后一个元素，返回值为移除的元素。
		s2, err := RedisClient.RPop(ctx, key).Result()
		result["RPOP"] = s2
		if err != nil {
			return  r.Error(err.Error())
		}
	} else {
		//LINDEX: 通过索引获取列表中的元素
		s, err := RedisClient.LIndex(ctx, key, 0).Result()
		result["LIndex-0"] = s
		//LRANGE:获取列表指定范围内的元素
		strings, err := RedisClient.LRange(ctx, key, 0, 3).Result()
		result["LRange"] = strings
		if err != nil {
			return  r.Error(err.Error())
		}
	}
	return  r.Success(result)
}
```


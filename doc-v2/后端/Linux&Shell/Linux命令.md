---
title: "Linux命令"
date: 2022-05-10
categories: [后端, Linux]
tags: [Linux]
cover: false
---

## 压力测试相关

**参数说明**

-n：执行的请求个数，默认执行一个请求

-c：一次产生的请求个数，即并发个数

-p：模拟post请求，文件格式为`name=xiaoshan&age=30`，配合-T使用

-T：post数据使用的Content-Type头信息，如`-T 'application/x-www-form-urlencoded'`

**模拟GET请求**

1. 直接在URL后面带参数即可

```shell
ab -c 10 -n 10 [http://www.test.api.com/?gid=2](http://www.test.api.com/?gid=2)
```

**模拟POST请求**

1. 在当前目录下创建一个post.txt

2. 编辑文件post.txt，写入`name=xiaoshan&age=30`，相当于传递name，age等参数

```shell
ab -c 10 -n 100 -p post.txt -T 'application/x-www-form-urlencoded' 'http://test.api.com/ttk/auth/info/'
```

## 日志查询相关

**查询指定时间范围内的日志**

```shell
sed -n '/2021-08-27 12:00:01/, /2021-08-27 12:00:10/p' ./xxx.log
grep "2021-08-27 12:00:0[1-9]" ./xxx.log
```

**按照关键字查询日志**

```shell
grep [-i] "xxx" ./xxx.log #在文件中根据关键字查找[不区分不小写]
grep -r[i] "xxx" ./ #在当前目录下根据关键字查找[不区分大小写]
```


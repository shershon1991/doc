---
title: "RPC编程(六):gRPC中的截取器"
date: 2022-09-25T16:03:00+08:00
draft: false 
tags: [Go进阶]
categories: [编程, Go]
---

## 1. 介绍

`gRPC` 中的截取器，类似中间件( `middleware` )的功能，可以做一些前置校验的工作，比如登陆验证、日志记录、异常捕获等。

## 2. 流程梳理

`gRPC` 中的 `grpc.UnaryInterceptor` 和 `grpc.StreamInterceptor` 分别对普通方法和流方法提供了截取器的支持。这里主要编写普通方法的截取器。

- 步骤一: 编写 `proto` 文件。
- 步骤二: 生成 `Go` 代码。
- 步骤三：编写服务端代码,并为 `grpc.UnaryInterceptor` 的参数实现一个函数。
- 步骤五：编写客户端代码。
- 步骤六: 运行测试。

### 2.1 编写 `proto` 

文件：`go-advanced/grpc/4/proto/intercept.proto`

```protobuf
syntax = "proto3";
option go_package = "server/interceptservice";

message Param {
  string query = 1;
}

message Result {
  int32 code = 1;
  string msg = 2;
}

service InterceptService {
  rpc Test(Param) returns (Result);
}
```

### 2.2 生成Go代码

```bash
➜  4 protoc --go_out=. --go-grpc_out=.  proto/intercept.proto
```

### 2.3 编写服务端

文件：`go-advanced/grpc/4/server.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/09/25 16:29
 */

package main

import (
	"context"
	"fmt"
	"go-advanced/grpc/4/server/interceptservice"
	"google.golang.org/grpc"
	"net"
	"time"
)

// 实现拦截器
func filter(ctx context.Context, req interface{}, info *grpc.UnaryServerInfo, handler grpc.UnaryHandler) (interface{}, error) {
	// todo
	fmt.Println("time:", time.Now().Unix())
	return handler(ctx, req)
}

func main() {
	// 创建grpc,并实现UnaryServerInterceptor
	grpcserver := grpc.NewServer(grpc.UnaryInterceptor(filter))
	// 注册服务
	interceptservice.RegisterInterceptServiceServer(grpcserver, new(interceptservice.UnimplementedInterceptServiceServer))
	// 监听端口
	conn, err := net.Listen("tcp", ":1234")
	if err != nil {
		fmt.Println("net.Listen error ", err)
		return
	}
	// 启动服务
	fmt.Println("启动服务...")
	grpcserver.Serve(conn)
}
```

上述代码中，在 `grpc.NewServer` 中传入为 `grpc.UnaryInterceptor` 实现的一个参数函数（ `filter` ),函数的参数介绍:
- `ctx` 和 `req` 就是每个普通的RPC方法的前两个参数。
- `info` 表示当前对应的那个gRPC方法.
- `handler` 对应当前的 `gRPC` 函数。上面的函数中首先是打印时间，然后调用 `handler` 对应的 `gRPC` 函数。

### 2.4 编写客户端

文件：`go-advanced/grpc/4/client.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/09/25 16:38
 */

package main

import (
	"context"
	"fmt"
	"go-advanced/grpc/4/server/interceptservice"
	"google.golang.org/grpc"
)

func main() {
	conn, err := grpc.Dial(":1234", grpc.WithInsecure())
	if err != nil {
		fmt.Println("Dial err ", err)
		return
	}
	defer conn.Close()
	// 实例化服务
	client := interceptservice.NewInterceptServiceClient(conn)
	p := interceptservice.Param{
		Query: "name=xiaoming",
	}
	test, err := client.Test(context.TODO(), &p)
	if err != nil {
		fmt.Println("call test err ", err)
		return
	}
	fmt.Println(test.String())
}
```

### 2.5 运行 & 测试

```bash
# 启动服务
➜  4 go run server.go
启动服务...

# 启动客户端
➜  4 go run client.go
code:200  msg:"name=xiaoming"

# 服务打印
time: 1664095692
```
---
title: "RPC编程(五):gRPC中的token认证"
date: 2022-09-23T18:44:07+08:00
draft: false 
tags: [Go进阶]
categories: [编程, Go]
---

## 1.介绍

`gRPC` 为每个 `gRPC` 方法调用提供了 `token` 认证支持，可以基于用户传入的 `token` 判断用户是否登录、以及权限...，实现 `token` 认证的前提是，需要定义一个结构体，并实现 `grpc.PerRPCCredentials` 接口。

### 1.1 grpc.PerRPCCredentials

```go
type PerRPCCredentials interface {
	// 返回需要认证的必要信息
	GetRequestMetadata(ctx context.Context, uri ...string) (map[string]string, error)
    // 是否使用安全链接(TLS)
	RequireTransportSecurity() bool
}
```

## 2.步骤梳理

- 步骤一: 编写 `proto` 文件。
- 步骤二: 生成 `go` 代码。
- 步骤三: 实现 `grpc.PerRPCCredentials` 接口。
- 步骤四: 编写验证 `token` 方法。
- 步骤五: 实现被调用的方法 `Test` 。
- 步骤六: 编写服务端代码。
- 步骤七: 编写客户端代码。
- 步骤八: 启动服务 & 发起请求。

## 3.代码实现

3.1 编写 `proto` 文件

文件: `go-advanced/grpc/3/proto/token.proto`

```protobuf
syntax = "proto3";

package tokenservice;
option go_package = "server/tokenservice";

// 验证参数
message TokenValidateParam {
  string token = 1;
  int32 uid = 2;
}

// 请求参数
message Request {
  string name = 1;
}

// 请求返回
message Response {
  int32 uid = 1;
  string name = 2;
}

// 服务
service TokenService {
  rpc Test(Request) returns (Response);
}
```

3.2 生成 `Go` 代码

```bash
➜  3 protoc --go_out=. --go-grpc_out=. proto/token.proto
```

3.3 实现 `grpc.PerRPCCredentials`

文件：`go-advanced/grpc/3/server/tokenservice/token_grpc.pb.go`

```go
...
/**
 * GetRequestMetadata
 * @Description: 返回token信息
 * @Author: Shershon
 * @Receiver x
 * @Param ctx
 * @Param uri
 * @Return map[string]string
 * @Return error
 * @Date 2022-09-23 17:58:55
 **/
func (x *TokenValidateParam) GetRequestMetadata(ctx context.Context, uri ...string) (map[string]string, error) {
	return map[string]string{
		"uid":   strconv.FormatInt(int64(x.GetUid()), 10),
		"token": x.GetToken(),
	}, nil
}

/**
 * RequireTransportSecurity
 * @Description: 自定义认证是否开启TLS
 * @Author: Shershon
 * @Receiver x
 * @Return bool
 * @Date 2022-09-23 18:00:02
 **/
func (x *TokenValidateParam) RequireTransportSecurity() bool {
	return false
}
...
```

3.4 编写验证 `token` 方法

文件：`go-advanced/grpc/3/server/tokenservice/token.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/09/23 18:03
 */

package tokenservice

import (
	"context"
	"crypto/md5"
	"fmt"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/metadata"
	"google.golang.org/grpc/status"
)

// 定义token
type TokenAuth struct{}

func (t TokenAuth) CheckToken(ctx context.Context) (*Response, error) {
	// 验证token
	md, b := metadata.FromIncomingContext(ctx)
	if !b {
		return nil, status.Error(codes.InvalidArgument, "token信息不存在")
	}
	var token, uid string
	// 取出token
	tokenInfo, ok := md["token"]
	if !ok {
		return nil, status.Error(codes.InvalidArgument, "token不存在")
	}
	token = tokenInfo[0]
	// 取出uid
	uidInfo, ok := md["uid"]
	if !ok {
		return nil, status.Error(codes.InvalidArgument, "uid不存在")
	}
	uid = uidInfo[0]
	// 验证
	sum := md5.Sum([]byte(uid))
	md5Str := fmt.Sprintf("%x", sum)
	if md5Str != token {
		fmt.Println("md5Str:", md5Str)
		fmt.Println("password:", token)
		return nil, status.Error(codes.InvalidArgument, "token验证失败")
	}
	return nil, nil
}
```

3.5 实现被调用的方法 `Test`

文件：`go-advanced/grpc/3/server/tokenservice/token_grpc.pb.go`

```go
...
// 匿名TokenAuth，可以直接调用验证token方法
type UnimplementedTokenServiceServer struct {
	TokenAuth
}

/**
 * Test
 * @Description: 实现Test方法(生成的代码，默认不实现具体逻辑)
 * @Author: Shershon
 * @Receiver u
 * @Param ctx
 * @Param r
 * @Return *Response
 * @Return error
 * @Date 2022-09-23 18:19:26
 **/
func (u UnimplementedTokenServiceServer) Test(ctx context.Context, r *Request) (*Response, error) {
	//return nil, status.Errorf(codes.Unimplemented, "method Test not implemented")
	// 验证token
	_, err := u.CheckToken(ctx)
	if err != nil {
		return nil, err
	}
	return &Response{Name: r.GetName()}, nil
}
...
```

3.6 服务端代码

文件：`go-advanced/grpc/3/server.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/09/23 18:20
 */

package main

import (
	"fmt"
	"go-advanced/grpc/3/server/tokenservice"
	"google.golang.org/grpc"
	"net"
)

func main() {
	// 创建grpc服务
	grpcServer := grpc.NewServer()
	// 注册服务
	tokenservice.RegisterTokenServiceServer(grpcServer, new(tokenservice.UnimplementedTokenServiceServer))
	// 监听端口
	listen, err := net.Listen("tcp", ":1234")
	if err != nil {
		fmt.Println("start error:", err)
		return
	}
	fmt.Println("服务启动成功....")
	grpcServer.Serve(listen)
}
```

3.7 实现客户端代码

文件：`go-advanced/grpc/3/client.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/09/23 18:23
 */

package main

import (
	"context"
	"fmt"
	"go-advanced/grpc/3/server/tokenservice"
	"google.golang.org/grpc"
)

func main() {
	// token信息
	auth := tokenservice.TokenValidateParam{
		Token: "11223",
		Uid:   10000,
	}
	conn, err := grpc.Dial("127.0.0.1:1234", grpc.WithInsecure(), grpc.WithPerRPCCredentials(&auth))
	if err != nil {
		fmt.Println("grpc.Dial error ", err)
		return
	}
	defer conn.Close()
	// 实例化客户端
	client := tokenservice.NewTokenServiceClient(conn)
	// 调用具体方法
	test, err := client.Test(context.TODO(), &tokenservice.Request{Name: "张三"})
	fmt.Println("return err:", err)
	fmt.Println("return result:", test)
}
```

3.8 启动 & 请求

```bash
# 启动服务
➜  3 go run server.go
服务启动成功....

# 发起请求
➜  3 go run client.go   
return err: rpc error: code = InvalidArgument desc = token验证失败
return result: <nil>
```
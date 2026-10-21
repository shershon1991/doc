---
title: "Go扩展包(十九):rocketmq"
date: 2022-10-05
cover: false
tags: [Go扩展包]
categories: [编程, Go]
---

# 介绍

本文将会介绍两种rocketmq扩展包，如下（截止到2022.10.04）：

| 包                                                                 |文档| Star 数量 | 说明          |
|-------------------------------------------------------------------|----------|---------|-------------|
| [apache/rocketmq-client-go](https://github.com/apache/rocketmq-client-go)             |https://github.com/apache/rocketmq-client-go| 979     | apache官方提供  |
| [aliyunmq/mq-http-go-sdk](https://github.com/aliyunmq/mq-http-go-sdk) |https://github.com/aliyunmq/mq-http-go-sdk| 50      | aliyun.mq提供 |

# 下载

```go
// rocketmq-client-go
go get -u github.com/apache/rocketmq-client-go/v2@v2.1.0

// 阿里云mq-http-go-sdk
go get -u github.com/aliyunmq/mq-http-go-sdk@v1.0.3
```

# 封装代码

## 基于 `rocketmq-client-go` 的生产者封装

文件位置：`app/rocketmqpkg/produce.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/10/02 14:03
 */

package rocketmqpkg

import (
	"context"
	"fmt"
	"github.com/apache/rocketmq-client-go/v2"
	"github.com/apache/rocketmq-client-go/v2/primitive"
	"github.com/apache/rocketmq-client-go/v2/producer"
	"os"
	"time"
)

// 发送普通消息
func Simple() {
	// 初始化生产者
	newProducer, err := rocketmq.NewProducer(
		producer.WithNameServer([]string{"127.0.0.1:9876"}),
		producer.WithRetry(1),
	)

	defer func(newProducer rocketmq.Producer) {
		err := newProducer.Shutdown()
		if err != nil {
			fmt.Printf("关闭producer失败 err:%s ", err)
			os.Exit(1)
		}
	}(newProducer)
	if err != nil {
		fmt.Printf("生成producer失败 err:%s ", err)
		os.Exit(1)
	}

	err = newProducer.Start()
	if err != nil {
		fmt.Printf("启动producer失败 err:%s ", err)
		os.Exit(1)
	}

	res, err := newProducer.SendSync(context.Background(), primitive.NewMessage("SimpleTopic", []byte("一条简单消息")))
	if err != nil {
		fmt.Printf("消息发送失败 err:%s ", err)
		os.Exit(1)
	}
	nowStr := time.Now().Format("2006-01-02 15:04:05")
	fmt.Printf("%s: 消息: %s发送成功 \n", nowStr, res.String())
}

// 发送延时消息
func Delay() {
	// 初始化生产者
	newProducer, err := rocketmq.NewProducer(
		producer.WithNameServer([]string{"127.0.0.1:9876"}),
		producer.WithRetry(1),
	)

	defer func(newProducer rocketmq.Producer) {
		err := newProducer.Shutdown()
		if err != nil {
			fmt.Printf("关闭producer失败 err:%s ", err)
			os.Exit(1)
		}
	}(newProducer)
	if err != nil {
		fmt.Printf("生成producer失败 err:%s ", err)
		os.Exit(1)
	}

	err = newProducer.Start()
	if err != nil {
		fmt.Printf("启动producer失败 err:%s ", err)
		os.Exit(1)
	}

	message := primitive.NewMessage("DelayTopic", []byte("一条延时消息"))
	// WithDelayTimeLevel 设置要消耗的消息延迟时间。参考延迟等级定义：1s 5s 10s 30s 1m 2m 3m 4m 5m 6m 7m 8m 9m 10m 20m 30m 1h 2h
	// 延迟等级从1开始，例如设置param level=1，则延迟时间为1s。
	// 这里使用的是延时30s发送
	message.WithDelayTimeLevel(4)

	res, err := newProducer.SendSync(context.Background(), message)
	if err != nil {
		fmt.Printf("消息发送失败 err:%s ", err)
		os.Exit(1)
	}
	nowStr := time.Now().Format("2006-01-02 15:04:05")
	fmt.Printf("%s: 消息: %s发送成功 \n", nowStr, res.String())
}

type TestListener struct{}

// ExecuteLocalTransaction 执行本地事务
// primitive.CommitMessageState : 提交
// primitive.RollbackMessageState : 回滚
// primitive.UnknowState : 触发回查函数 CheckLocalTransaction
func (t TestListener) ExecuteLocalTransaction(message *primitive.Message) primitive.LocalTransactionState {
	fmt.Println("执行本地事务")
	return primitive.UnknowState
}

// CheckLocalTransaction 回查函数
// primitive.CommitMessageState : 提交
// primitive.RollbackMessageState : 回滚
// primitive.UnknowState : 触发会查函数 CheckLocalTransaction
func (t TestListener) CheckLocalTransaction(ext *primitive.MessageExt) primitive.LocalTransactionState {
	fmt.Println("执行回查函数")
	return primitive.CommitMessageState
}

// 发送事务消息
func Transaction() {
	newTransactionProducer, err := rocketmq.NewTransactionProducer(
		&TestListener{},
		producer.WithNameServer([]string{"127.0.0.1:9876"}),
	)
	defer func(newProducer rocketmq.TransactionProducer) {
		err := newProducer.Shutdown()
		if err != nil {
			fmt.Printf("关闭producer失败 err:%s ", err)
			os.Exit(1)
		}
	}(newTransactionProducer)
	if err != nil {
		fmt.Printf("生成producer失败 err:%s ", err)
		os.Exit(1)
	}
	if err = newTransactionProducer.Start(); err != nil {
		fmt.Printf("启动producer失败 err:%s ", err)
		os.Exit(1)
	}
	res, err := newTransactionProducer.SendMessageInTransaction(context.Background(), primitive.NewMessage("TransactionTopic", []byte("这是一条事务消息2")))
	if err != nil {
		fmt.Printf("消息发送失败 err:%s ", err)
		os.Exit(1)
	}
	nowStr := time.Now().Format("2006-01-02 15:04:05")
	fmt.Printf("%s: 消息: %s发送成功 \n", nowStr, res.String())
	time.Sleep(time.Hour)
}
```

## 基于 `rocketmq-client-go` 的消费者封装

文件位置：`app/rocketmqpkg/consume.go`

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/10/02 14:03
 */

package rocketmqpkg

import (
	"context"
	"fmt"
	"github.com/apache/rocketmq-client-go/v2"
	"github.com/apache/rocketmq-client-go/v2/consumer"
	"github.com/apache/rocketmq-client-go/v2/primitive"
	"os"
	"time"
)

// 消费普通消息
func ConsumeSimple() {
	newPushConsumer, err := rocketmq.NewPushConsumer(
		consumer.WithGroupName("test"),
		consumer.WithNameServer([]string{"127.0.0.1:9876"}),
	)

	defer func(newPushConsumer rocketmq.PushConsumer) {
		err := newPushConsumer.Shutdown()
		if err != nil {
			fmt.Printf("关闭consumer失败 err:%s \n", err)
			os.Exit(1)
		}
	}(newPushConsumer)

	if err != nil {
		fmt.Printf("生成consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Subscribe("SimpleTopic", consumer.MessageSelector{},
		func(ctx context.Context, msgs ...*primitive.MessageExt) (consumer.ConsumeResult, error) {
			for _, msg := range msgs {
				nowStr := time.Now().Format("2006-01-02 15:04:05")
				fmt.Printf("%s 读取到一条消息,消息内容: %s \n", nowStr, string(msg.Body))
			}
			return consumer.ConsumeSuccess, nil
		},
	)

	if err != nil {
		fmt.Printf("读取消息失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Start()
	if err != nil {
		fmt.Printf("启动consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	time.Sleep(time.Hour)
}

// 消费延时消息
func ConsumeDelay() {
	newPushConsumer, err := rocketmq.NewPushConsumer(
		consumer.WithGroupName("test"),
		consumer.WithNameServer([]string{"127.0.0.1:9876"}),
	)

	defer func(newPushConsumer rocketmq.PushConsumer) {
		err := newPushConsumer.Shutdown()
		if err != nil {
			fmt.Printf("关闭consumer失败 err:%s \n", err)
			os.Exit(1)
		}
	}(newPushConsumer)

	if err != nil {
		fmt.Printf("生成consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Subscribe("DelayTopic", consumer.MessageSelector{},
		func(ctx context.Context, msgs ...*primitive.MessageExt) (consumer.ConsumeResult, error) {
			for _, msg := range msgs {
				nowStr := time.Now().Format("2006-01-02 15:04:05")
				fmt.Printf("%s 读取到一条消息,消息内容: %s \n", nowStr, string(msg.Body))
			}
			return consumer.ConsumeSuccess, nil
		},
	)

	if err != nil {
		fmt.Printf("读取消息失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Start()
	if err != nil {
		fmt.Printf("启动consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	time.Sleep(time.Hour)
}

// 消费事务消息
func ConsumeTransaction() {
	newPushConsumer, err := rocketmq.NewPushConsumer(
		consumer.WithGroupName("test"),
		consumer.WithNameServer([]string{"127.0.0.1:9876"}),
	)

	defer func(newPushConsumer rocketmq.PushConsumer) {
		err := newPushConsumer.Shutdown()
		if err != nil {
			fmt.Printf("关闭consumer失败 err:%s \n", err)
			os.Exit(1)
		}
	}(newPushConsumer)

	if err != nil {
		fmt.Printf("生成consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Subscribe("TransactionTopic", consumer.MessageSelector{},
		func(ctx context.Context, msgs ...*primitive.MessageExt) (consumer.ConsumeResult, error) {
			for _, msg := range msgs {
				nowStr := time.Now().Format("2006-01-02 15:04:05")
				fmt.Printf("%s 读取到一条消息,消息内容: %s \n", nowStr, string(msg.Body))
			}
			return consumer.ConsumeSuccess, nil
		},
	)

	if err != nil {
		fmt.Printf("读取消息失败 err:%s \n", err)
		os.Exit(1)
	}

	err = newPushConsumer.Start()
	if err != nil {
		fmt.Printf("启动consumer失败 err:%s \n", err)
		os.Exit(1)
	}

	time.Sleep(time.Hour)
}
```

## 基于 `阿里云mq-http-go-sdk` 的生产者封装

```go
package aliyunmq

import (
	"fmt"
	"strconv"
	"time"

	"github.com/aliyunmq/mq-http-go-sdk"
)

func Simple() {
	// 设置HTTP接入域名（此处以公共云生产环境为例）
	endpoint := "******"
	// AccessKey 阿里云身份验证，在阿里云服务器管理控制台创建
	accessKey := "******"
	// SecretKey 阿里云身份验证，在阿里云服务器管理控制台创建
	secretKey := "******"
	// 所属的 Topic
	topic := "go-simple-topic"
	// Topic所属实例ID，默认实例为空
	instanceId := "MQ_INST_1050827944341157_BYOHEv6c"

	client := mq_http_sdk.NewAliyunMQClient(endpoint, accessKey, secretKey, "")

	mqProducer := client.GetProducer(instanceId, topic)
	// 循环发送4条消息
	for i := 0; i < 4; i++ {
		var msg mq_http_sdk.PublishMessageRequest
		if i%2 == 0 {
			msg = mq_http_sdk.PublishMessageRequest{
				MessageBody: "hello mq!",         //消息内容
				MessageTag:  "",                  // 消息标签
				Properties:  map[string]string{}, // 消息属性
			}
			// 设置KEY
			msg.MessageKey = "MessageKey"
			// 设置属性
			msg.Properties["a"] = strconv.Itoa(i)
		} else {
			msg = mq_http_sdk.PublishMessageRequest{
				MessageBody: "hello mq timer!",   //消息内容
				MessageTag:  "",                  // 消息标签
				Properties:  map[string]string{}, // 消息属性
			}
			// 设置属性
			msg.Properties["a"] = strconv.Itoa(i)
			// 定时消息, 定时时间为10s后, 值为毫秒级别的Unix时间戳
			msg.StartDeliverTime = time.Now().UTC().Unix()*1000 + 10*1000
		}
		ret, err := mqProducer.PublishMessage(msg)

		if err != nil {
			fmt.Println(err)
			return
		} else {
			fmt.Printf("Publish ---->\n\tMessageId:%s, BodyMD5:%s, \n", ret.MessageId, ret.MessageBodyMD5)
		}
		time.Sleep(time.Duration(100) * time.Millisecond)
	}
}
```

## 基于 `阿里云mq-http-go-sdk` 的消费者封装

```go
/**
 * @Author: shershon
 * @Description:
 * @Date: 2022/10/02 14:03
 */

package aliyunmq

import (
	"fmt"
	mq_http_sdk "github.com/aliyunmq/mq-http-go-sdk"
	"github.com/gogap/errors"
	"strings"
	"time"
)

func ConsumeSimple() {
	// 设置HTTP接入域名（此处以公共云生产环境为例）
	endpoint := "******"
	// AccessKey 阿里云身份验证，在阿里云服务器管理控制台创建
	accessKey := "******"
	// SecretKey 阿里云身份验证，在阿里云服务器管理控制台创建
	secretKey := "******"
	// 所属的 Topic
	topic := "go-simple-topic"
	// Topic所属实例ID，默认实例为空
	instanceId := "MQ_INST_1050827944341157_BYOHEv6c"
	// 您在控制台创建的 Consumer ID(Group ID)
	groupId := "GID_GO_TEST"

	client := mq_http_sdk.NewAliyunMQClient(endpoint, accessKey, secretKey, "")

	mqConsumer := client.GetConsumer(instanceId, topic, groupId, "")

	for {
		endChan := make(chan int)
		respChan := make(chan mq_http_sdk.ConsumeMessageResponse)
		errChan := make(chan error)
		go func() {
			select {
			case resp := <-respChan:
				{
					// 处理业务逻辑
					var handles []string
					fmt.Printf("Consume %d messages---->\n", len(resp.Messages))
					for _, v := range resp.Messages {
						handles = append(handles, v.ReceiptHandle)
						fmt.Printf("\tMessageID: %s, PublishTime: %d, MessageTag: %s\n"+
							"\tConsumedTimes: %d, FirstConsumeTime: %d, NextConsumeTime: %d\n"+
							"\tBody: %s\n"+
							"\tProps: %s\n",
							v.MessageId, v.PublishTime, v.MessageTag, v.ConsumedTimes,
							v.FirstConsumeTime, v.NextConsumeTime, v.MessageBody, v.Properties)
					}

					// NextConsumeTime前若不确认消息消费成功，则消息会重复消费
					// 消息句柄有时间戳，同一条消息每次消费拿到的都不一样
					ackerr := mqConsumer.AckMessage(handles)
					if ackerr != nil {
						// 某些消息的句柄可能超时了会导致确认不成功
						fmt.Println(ackerr)
						for _, errAckItem := range ackerr.(errors.ErrCode).Context()["Detail"].([]mq_http_sdk.ErrAckItem) {
							fmt.Printf("\tErrorHandle:%s, ErrorCode:%s, ErrorMsg:%s\n",
								errAckItem.ErrorHandle, errAckItem.ErrorCode, errAckItem.ErrorMsg)
						}
						time.Sleep(time.Duration(3) * time.Second)
					} else {
						fmt.Printf("Ack ---->\n\t%s\n", handles)
					}

					endChan <- 1
				}
			case err := <-errChan:
				{
					// 没有消息
					if strings.Contains(err.(errors.ErrCode).Error(), "MessageNotExist") {
						fmt.Println("\nNo new message, continue!")
					} else {
						fmt.Println(err)
						time.Sleep(time.Duration(3) * time.Second)
					}
					endChan <- 1
				}
			case <-time.After(35 * time.Second):
				{
					fmt.Println("Timeout of consumer message ??")
					endChan <- 1
				}
			}
		}()

		// 长轮询消费消息
		// 长轮询表示如果topic没有消息则请求会在服务端挂住3s，3s内如果有消息可以消费则立即返回
		mqConsumer.ConsumeMessage(respChan, errChan,
			3, // 一次最多消费3条(最多可设置为16条)
			3, // 长轮询时间3秒（最多可设置为30秒）
		)
		<-endChan
	}
}
```

# 简单使用

## 发送普通消息（基于 `rocketmq-client-go`）

```go
// 发送普通消息
func TestSimpleProducer(t *testing.T) {
	rocketmqpkg.Simple()
}
/**输出
=== RUN   TestSimpleProducer
2022-10-05 11:17:39: 消息: SendResult [sendStatus=0, msgIds=C0A80009FECC000000001705d8380001, offsetMsgId=C0A8000900002A9F0000000000000000, queueOffset=0, messageQueue=MessageQueue [topic=SimpleTopic, brokerName=broker-a, queueId=1]]发送成功 
--- PASS: TestSimpleProducer (0.05s)
 */
```

## 消费普通消息（基于 `rocketmq-client-go`）

```go
// 消费普通消息
func TestSimpleConsumer(t *testing.T) {
	rocketmqpkg.ConsumeSimple()
}
/**输出
=== RUN   TestSimpleConsumer
2022-10-05 11:19:42 读取到一条消息,消息内容: 一条简单消息 
 */
```

## 发送延时消息（基于 `rocketmq-client-go`）

```go
// 发送延时消息
func TestDelayProducer(t *testing.T) {
	rocketmqpkg.Delay()
}
/**输出
=== RUN   TestDelayProducer
2022-10-05 11:22:12: 消息: SendResult [sendStatus=0, msgIds=C0A80009FF2900000000170a02a00001, offsetMsgId=C0A8000900002A9F00000000000000A2, queueOffset=0, messageQueue=MessageQueue [topic=DelayTopic, brokerName=broker-a, queueId=1]]发送成功 
--- PASS: TestDelayProducer (0.03s)
PASS
 */
```

## 消费延时消息（基于 `rocketmq-client-go`）

```go
// 消费延时消息
func TestDelayConsumer(t *testing.T) {
	rocketmqpkg.ConsumeDelay()
}
/**输出
=== RUN   TestDelayConsumer
2022-10-05 11:24:02 读取到一条消息,消息内容: 一条延时消息 
 */
```

## 发送事务消息（基于 `rocketmq-client-go`）

```go
// 发送事务消息
func TestTransactionProducer(t *testing.T) {
	rocketmqpkg.Transaction()
}
/**输出
=== RUN   TestTransactionProducer
2022-10-05 11:24:58: 消息: SendResult [sendStatus=0, msgIds=C0A80009FF7900000000170c8b100001, offsetMsgId=C0A8000900002A9F000000000000023F, queueOffset=0, messageQueue=MessageQueue [topic=TransactionTopic, brokerName=broker-a, queueId=1]]发送成功 
 */
```

## 消费事务消息（基于 `rocketmq-client-go`）

```go
// 消费事务消息
func TestTransactionConsumer(t *testing.T) {
	rocketmqpkg.ConsumeTransaction()
}
/**输出
=== RUN   TestTransactionConsumer
2022-10-05 11:26:48 读取到一条消息,消息内容: 这是一条事务消息2 
 */
```

## 发送普通消息（基于 `阿里云mq-http-go-sdk`）

```go
// aliyun-发送普通消息
func TestAliSimpleProducer(t *testing.T) {
	aliyunmq.Simple()
}
/**输出
=== RUN   TestAliSimpleProducer
Publish ---->
	MessageId:6F3C3DB6000E681A951516F039C8A5B7, BodyMD5:95A269CF8D5A5D22CF8A0F8ACF64AB66, 
Publish ---->
	MessageId:6F3C3DB6000E681A951516F03A5CA6F7, BodyMD5:C0FF9ACB51988C7BCC7A0C62397282D7, 
Publish ---->
	MessageId:6F3C3DB6000E681A951516F03AECA7DB, BodyMD5:95A269CF8D5A5D22CF8A0F8ACF64AB66, 
Publish ---->
	MessageId:6F3C3DB6000E681A951516F03B7DA8F3, BodyMD5:C0FF9ACB51988C7BCC7A0C62397282D7, 
--- PASS: TestAliSimpleProducer (0.72s)
PASS
 */
```

## 消费普通消息（基于 `阿里云mq-http-go-sdk`）

```go
// aliyun-消费普通消息
func TestAliSimpleConsumer(t *testing.T) {
	aliyunmq.ConsumeSimple()
}
/**输出
=== RUN   TestAliSimpleConsumer
Consume 3 messages---->
	MessageID: 6F3C3DB6000E681A951516F039C8A5B7, PublishTime: 1664938442184, MessageTag: 
	ConsumedTimes: 1, FirstConsumeTime: 1664938606594, NextConsumeTime: 1664938906594
	Body: hello mq!
	Props: map[__BORNHOST:111.60.61.182 a:0]
	MessageID: 6F3C3DB6000E681A951516F03A5CA6F7, PublishTime: 1664938442332, MessageTag: 
	ConsumedTimes: 1, FirstConsumeTime: 1664938606594, NextConsumeTime: 1664938906594
	Body: hello mq timer!
	Props: map[__BORNHOST:111.60.61.182 a:1]
	MessageID: 6F3C3DB6000E681A951516F03AECA7DB, PublishTime: 1664938442476, MessageTag: 
	ConsumedTimes: 1, FirstConsumeTime: 1664938606594, NextConsumeTime: 1664938906594
	Body: hello mq!
	Props: map[__BORNHOST:111.60.61.182 a:2]
Ack ---->
	[6F3C3DB6000E681A951516F039C8A5B7-MCAxNjY0OTM4NjA2NTk0IDMwMDAwMCA2IDAgY24temhhbmdqaWFrb3Utc2hhcmUtMDEtMyAxIDA= 6F3C3DB6000E681A951516F03A5CA6F7-MCAxNjY0OTM4NjA2NTk0IDMwMDAwMCA2IDAgY24temhhbmdqaWFrb3Utc2hhcmUtMDEtMyAyIDA= 6F3C3DB6000E681A951516F03AECA7DB-MCAxNjY0OTM4NjA2NTk0IDMwMDAwMCA2IDAgY24temhhbmdqaWFrb3Utc2hhcmUtMDEtMyAzIDA=]
Consume 1 messages---->
	MessageID: 6F3C3DB6000E681A951516F03B7DA8F3, PublishTime: 1664938442621, MessageTag: 
	ConsumedTimes: 1, FirstConsumeTime: 1664938606724, NextConsumeTime: 1664938906724
	Body: hello mq timer!
	Props: map[__BORNHOST:111.60.61.182 a:3]
Ack ---->
	[6F3C3DB6000E681A951516F03B7DA8F3-MCAxNjY0OTM4NjA2NzI0IDMwMDAwMCAyIDAgY24temhhbmdqaWFrb3Utc2hhcmUtMDEtMyA0IDA=]
 */
```

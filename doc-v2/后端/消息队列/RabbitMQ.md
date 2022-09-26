---
title: "RabbitMQ"
date: 2022-05-10 
tags: [RabbitMQ]
categories: [后端, 消息队列]
cover: false
---

## 简介

RabbirMQ是一个高可用的消息中间件，有以下作用：

l 异步消息传递

l 支持多种开发语言

l 可插拔的身份验证、授权

l RabbitMQ-Manager可用于管理和监视

## 使用

RabbitMQ作为生产者和消费者时，基本上有2种使用场景：

l 一个/多个生产者，多个共享消费者

l 一个/多个生产者，多个独立消费者

共享的消费者可以同时消费一个队列的数据，增加吞吐量；独立的消费者不共享队列，每个消费者都有自己的队列，可以定义规则从exchange中pull数据到自己的queue中。

### 基础概念

**queue**

数据队列，数据可以推送到queue，也可以从queue中消费

**exchange**

交换机，将数据推送到交换机中，队列可以绑定交换机，交换机的类型不同，所支持的绑定规则也不同。

l fanout：没有规则，所有exchange中的数据

l direct：精确匹配，只绑定routingKey指定值的数据

l topic：更加灵活的规则，routingKey必须是一个由 . 分隔开的词语，* 用来表示一个单词，# 用来表示任意数量（0个或多个）单词

**常用操作封装**

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpszKEsH2.jpg)

## 多个共享消费者

多个共享消费者可以增加消费速度，提升系统吞吐量。

### 生产者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wps6q6VYx.jpg)

### 消费者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpsiZ80oV.jpg)

命令行运行消费者两次

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpskCgh0K.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpsQ9Qiri.jpg)

可以看到二个消费者不会重复消费。

## 多个独立的消费者

rabbitmq生产者将message推送到exchange，通过将多个queue与exchange进行绑定，来实现多个独立的消费者。

### 生产者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpsdh53yx.jpg)

### 消费者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpsqe0Tx6.jpg)

## 延时队列

### 概念

延时队列的作用不再累述 本文使用rabbitmq的queue可以设置ttl时间，将到期的message设为死信，message会被push到delay_queue，消费delay_queue即可实现延时队列功能。

### 场景

先假设这样一个场景： 小明在外卖平台下个一个订单，如果超过10分钟未支付，则系统自动取消订单，并推送给用户“订单已取消”信息。

开发思路： 下订单时就将订单orderId
push到订单队列order_queue，并设置次条message的有效期为10分钟，当10分钟后此条message到期，会将此条message转化为死信push到exchange，将exchange和queue进行绑定，开一个/多个消费者消费queue，并判断queue中message订单是否已支付，若未支付则推送通知，取消订单。

流程图，未考虑消费失败的情况。

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpslBIRjO.jpg)

### 核心代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpstMa3N3.jpg)

### 生产者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpsxL8YRV.jpg)

### 消费者代码

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mq/wpssSC9MK.jpg) 
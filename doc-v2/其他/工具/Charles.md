---
title: "Charles"
date: 2022-08-11 
tags: [Charles]
categories: [其他, 工具]
cover: false
---

## 1.什么是Charles

`Charles` 是一个HTTP代理/HTTP监视器/反向代理，它使开发人员能够查看他们的机器和Internet之间的所有HTTP和SSL/HTTPS流量。这包括请求、响应和HTTP标头（其中包含cookie和缓存信息）。

## 2.安装Charles

> [下载地址：https://www.charlesproxy.com/download/](https://www.charlesproxy.com/download/)

## 3.使用Charles

### 3.1 Charles监听手机流量示例

- 输入 `ifconfig`, 查看本地IP

  ![image-20201113095444058](https://raw.githubusercontent.com/shershon1991/picImgBed/master/charles/ifconfig.png)

- 手机设置代理为电脑IP，配置端口为8888

- 下载证书，下载地址为：http://chls.pro/ssl

- 手机设置-通用-描述文件，安装证书

- 手机设置-通用-关于本机-证书信任设置，信任证书

- charles: proxy ssl-proxy-setting-location添加：`**:**` 、`*`


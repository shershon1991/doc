---
title: "PHP-web和框架(一):web"
date: 2022-05-05
tags: [PHP-web和框架]
categories: [编程, PHP]
cover: false
---

### session与cookie的区别是什么？

**session**

PHP的会话也称为`session`。PHP在操作`session`时，当用户登陆或访问一些初始页面时，服务器会为客户端分配一个`sessionID`。`sessionID`是一个加密的随机数字，在`session`的生命周期中保存在客户端。它可以保存在用户机器的`cookie`中，也可以通过URL在网络中进行传输。

用户通过`sessionID`可以注册一些特殊的变量，称为会话变量，这些变量的数据保存在服务器端。在一次特定的网站连接中，若客户端通过`cookie`或URL找到`sessionID`，那么服务器就可以根据客户端传来的`sessionID`访问会话保存在服务器端的会话变量。

`session`的生命周期只在一次特定的网站连接中有效，当关闭浏览器后，`session`会自动失效，之前注册的会话变量也不能再使用。具体的使用步骤如下：

1. 初始化会话。在实现会话功能之前必须要初始化会话，初始化会话使用`session_start()`函数：

`bool session_start(void)`

该函数将检查`sessionID`是否存在，若不存在，则创建一个，并且能够使用预定义数组`$_session`进行访问。若启动会话成功，则函数返回true，否则返回false。会话启动后就可以载入该会话已经注册的会话变量以便使用。

2. 注册会话变量。自PHP4.1以后，会话变量保存在预定义数组`$_session`中，所以可以通过直接定义数组单元的方式来定义一个会话变量。会话变量定义后保存在服务器端，并对该变量的值进行跟踪，直到会话结束或手动注销该变量。

3. 访问会话变量。要在一个脚本中访问会话变量，首先要使用`session_start()`函数启动一个会话。之后就可以使用预定义数组`$_session`访问该变量了。

4. 销毁会话变量。会话变量使用完后，删除已经注册的会话变量以减少对服务器资源的占用。删除会话变量使用`unset()`函数。要一次销毁所有的会话变量且不清除`session`文件，使用`session_unset()`。

5. 销毁会话。使用完一个会话后，要注销对应的会话变量。调用`session_destroy()`函数销毁会话，该函数将删除会话的所有数据并清除session文件，关闭该会话。

引申1：共享`session`的方式主要有以下几种：

1. 基于NFS的`session`共享。NFS（Network File System）最早由sun公司为解决Unix网络主机间的目录共享而研发。仅需将共享目录服务器mount到其他服务器的本地session目录即可。

2. 基于数据库的`session`共享

3. 基于`cookie`的`session`共享

4. 基于缓存（`Memcache、Redis`）的`session`共享

引申2：如何修改`session`的生存时间？

1. 将`php.ini`中的`session.gc_maxlifetime`设置为9999，重启Apache

2. `session`提供了一个函数`session_set_cookie_params()`来设置`session`的生存期，该函数必须在`session_start()`之前调用，示例代码如下：

```php
$savePath = "./session_save_dir/";
$liftTime = 3600;
session_save_path($savePath);
session_set_cookie_params($liftTime);
session_start();
```

3. 使用`setcookie()`;

**cookie**

`cookie`可以用来存储用户名、密码、访问该站点的次数等信息。在访问某个网站时，`cookie`将HTML网页发送到浏览器的小段信息以脚本的形式保存在客户端的计算机上。

一般来说，`cookie`通过`HTTP Headers`从服务器端返回到浏览器。首先，服务器端在响应中利用`Set cookie Header`来创建一个`cookie`。其次浏览器在请求中通过`cookie Header`包含这个已经创建的`cookie`，并且将它返回至服务器，从而完成浏览器的验证。

`cookie`技术也有很多局限性，如：

1. 多人共用一台计算机，`cookie`信息容易泄漏

2. 一个站点存储的`cookie`信息有限

3. 有些浏览器不支持`cookie`

4. 用户可以通过设置浏览器选项来禁用`cookie`

cookie的使用步骤如下：

1. 创建`cookie`

使用`setcookie()`函数，语法格式如下：

```php
/**
 * $name: 表示cookie名
 * $value: 表示cookie值
 * $expire: 表示cookie的过期时间。若设置，一般通过当前时间戳+相应的秒数来决定，若不设置则cookie将在浏览器关闭之后失效。
 * $path: 表示cookie在服务器上的有效路径，默认值为设置cookie的当前目录
 * $domain: 表示cookie在服务器上的有效域名。例如：要是cookie在example.com域名下的所有子域名都有效，该参数应设置为                    ".example.com"
 */
setcookie(
    string $name,
    string $value = "",
    int $expires_or_options = 0,
    string $path = "",
    string $domain = "",
    bool $secure = false,
    bool $httponly = false
): bool
```

2. 访问`cookie`

3. 删除`cookie`

注意：HTTP协议是无状态的，要想追踪一个用户在一个网站不同页面之间的状态，我们需要一种机制，这种机制就是会话机制。

`session`和`cookie`的区别如下：

| 角度               | 描述                                                         |
| ------------------ | ------------------------------------------------------------ |
| 保存位置           | cookie保存在客户端，session保存在服务器端                    |
| 安全性角度         | session的安全性更高                                          |
| 保存内容的类型角度 | cookie只保存字符串（即能够自动转换成字符串），session可以保存所有的数据类型 |
| 保存内容的大小角度 | cookie保存的内容是有限的，session基本无限制                  |
| 性能角度           | session对服务器压力会更大一些                                |

### GET和POST有什么区别？

用户在页面上填写的表单信息都可以通过`GET`和`POST`这两种方法将数据传递到服务器上，当使用`GET`方法时，所有的信息都会出现在URL地址中，并且使用`GET`方法最多只能传递1KB字节的数据，所以在传输量小或者安全性不高的情况下可以使用`GET`方法。对于`POST`而言，最多可以传输2MB字节的数据，而且可以根据需要调节。

GET请求

POST请求

### 如何预防各类安全性问题？

SQL注入/XSS攻击/CSRF攻击

- Cross-Site Scripting, XSS - 跨站脚本攻击

- Cross-Site Request Forgery, CSRF - 跨站请求伪造

数据库操作安全问题

没有验证用户HTTP请求方式

没有验证表单来源的唯一性

### HTTP状态码的含义是什么？

```text
1XX: Informational（信息性状态码） 接受的请求正在处理

2XX: Success（成功状态码） 请求正常处理完毕
200 OK：处理成功
201 Created：服务器已经创建了资源
202 Accepted：已经接受请求，但处理尚未完成
203 Non-Authoritative Information：文档已经正常地返回，但一些应答头可能不正确
204 No Content：没有新文档，浏览器应该继续显示原来的文档
205 Reset Content：没有新的内容，但浏览器应该重置它所显示的内容。用来强制浏览器清除表单输入内容
206 Partial Content：客户端发送了一个带有Range头的GET请求，服务器完成了它

3XX: Redirection（重定向状态码） 需要进行附加操作以完成请求
300 Multiple Choices：服务器根据请求可以执行多种操作
301 Moved Permanently：请求的网页已被永久移动到新位置。永久性重定向
302 Moved Temporarily：服务器目前正从不同位置的网页响应请求，但请求者应继续 使用原有位置来进行以后的请求。临时性重定向
303 See Other：当请求者对不同的位置进行单独的GET请求来检索响应时，服务器会返回此代码
304 Not Modified：自动上一次请求后，被请求的网页未被修改过。服务器返回此响应时，不会返回网页内容。305（使用代理）请求者只能使用代理访问请求的网页。如果服务器返回此响应，那么服务器还会指明请求者应当使用的代理
305 Use Proxy：被请求的资源必须通过指定的代理才能被访问
307 Temporary Redirect：服务器目前正从不同位置的网页响应请求，但请求者应继续使用原有位置来进行以后的请求，会自动将请求者转到不同的位置。但由于搜索引擎会继续抓取原有位置并将其编入索引，因此不应使用此代码来告诉搜索引擎某个页面或网站已被移动

4XX: Client Error（客户端错误状态码） 服务器无法处理请求
400 Bad Request：服务器端无法理解客户端发送的请求
401 Unauthorized：访问被拒绝，客户试图未经授权访问受密码保护的页面
403 Forbidden：资源不可用。服务器理解客户的请求，但拒绝处理它，通常由于服务器上的文件或目录的权限设置所致
404 Not Found：所请求的页面不存在。通常由于用户请求的页面不存在所致

5XX: Server Error（服务器错误状态码） 服务器处理请求出错
500 Internal Server Error：服务器遇到了意料不到的情况，不能完成客户的请求
501 Not Implemented：服务器不支持实现请求所需要的功能，页眉值指定了未实现的配置
502 Bad Gateway：服务器作为网关或代理时，为了完成请求访问下一个服务器，但该服务器返回了非法的应答
503 Service Unavailable：服务不可用，服务器由于维护或负载过重未能应答
504 Gateway Timeout：网关超时，由作为代理或网关的服务器使用，表示不能及时地从远程服务器获得应答
```

引申：用户在浏览器中输入一个网址，按下回车后后台的执行流程是怎么样的？

最基本的页面请求与响应的流程：

1. 用户通过浏览器输入地址来请求所需的资源

2. 浏览器接受用户的请求，并把该请求组装成指定的格式（HTTP协议的格式）发送给服务器，客户端与服务器之间通过HTTP协议来完成具体的交互。其中请求的数据流中主要包括HTTP（建立在TCP/IP协议基础上的一个协议）、请求方法（GET或POST）、请求的网址（URL）以及请求的一些参数信息（当然在把数据发送给服务器之前，首先需要根据网页地址获取服务器的IP地址，这就需要通过访问DNS服务器来完成）。

3. 服务器接收到客户端发来的请求，并查找用户所需要的资源

4. 服务器查找到用户请求的资源后，把该资源返回给客户端

5. 服务器通过把响应消息组装成特定的信息格式后返回给客户端，这个过程通过HTTP协议来完成。响应的数据主要包含状态码、Content-Type、响应消息的内容

6. 浏览器对HTML进行解析后并把响应结果呈现给用户

### utf-8编码需要注意哪些问题？

若网站的编码为utf-8，那么相关的文件和数据库都必须使用utf-8编码，否则网站就会出现乱码。

具体需要注意utf-8编码的文件有：

1. 数据库需要用utf-8编码，包括数据库和表

2. PHP连接数据库的时候，需要指定所使用的编码为utf-8

3. 网站中所有的文件都使用utf-8

### 如何进行网站的优化？

1. 确认服务器硬件是否足够支持当前的流量

2. 优化数据库访问

3. 防盗链

4. 控制大文件的下载和控制文件下载的数量

5. 使用不同主机分流主要流量

6. 使用流量统计软件，针对流量的访问情况进行系统优化

### SSO

### OAuth
---
title: "Nginx"
date: 2022-05-05 
tags: [Nginx]
categories: [后端, Nginx]
cover: false
---

## HTTP 原理及 Nginx 基础特性

### Web 服务

Nginx: web server(static contents), web reverse proxy (http), cache

Varnish, squid: cache, http headers

Haproxy: tcp reverse proxy, http reverse proxy

Keepalived: HA

Ats: apache traffic server

mogileFS(分布式文件系统), NoSQL(MongoDB)

### Nginx

Apache: MPM(prefork, event)

c10k(concurrency), lighttpd, nginx

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsp09tKW.jpg)

#### http protocol

Request => Response

请求报文：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpswnuPeM.jpg)

响应报文：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsIzXsIf.jpg)

响应码：

1XX: Informational（信息性状态码） 接受的请求正在处理

2XX: Success（成功状态码） 请求正常处理完毕

200 OK：处理成功

201 Created：服务器已经创建了资源

202 Accepted：已经接受请求，但处理尚未完成

203 Non-Authoritative Information：文档已经正常地返回，但一些应答头可能不正 确

204 No Content：没有新文档，浏览器应该继续显示原来的文档

205 Reset Content：没有新的内容，但浏览器应该重置它所显示的内容。用来强制浏 览器清除表单输入内容

206 Partial Content：客户端发送了一个带有 Range 头的 GET 请求，服务器完成了 它

3XX: Redirection（重定向状态码） 需要进行附加操作以完成请求

300 Multiple Choices：服务器根据请求可以执行多种操作

301 Moved Permanently：请求的网页已被永久移动到新位置。永久性重定向

302 Moved temporarily：服务器目前正从不同位置的网页响应请求，但请求者应继 续使用原有位置来进行以后的请求。临时性重定向

303 See Other：当请求者对不同的位置进行单独的 GET 请求来检索响应时，服务器 会返回此代码

304 Not Modified：自从上一次请求后，被请求的网页未被修改过。服务器返回此响 应时，不会返回网页内容。305（使用代理）请求者只能使用代理访问请求的网页。 如果服务器返回此响应，那么服务器还会指明请求者应当使用的代理

305 Use Proxy：被请求的资源必须通过指定的代理才能被访问

307 Temporary Redirect：服务器目前正从不同位置的网页响应请求，但请求者应继 续使用原有位置来进行以后的请求，会自动将请求者转到不同的位置。但由于搜索
引擎会继续抓取原有位置并将其编入索引，因此不应使用此代码来告诉搜索引擎某 个页面或网站已被移动

4XX: Client Error（客户端错误状态码） 服务器无法处理请求

400 Bad Request：服务器端无法理解客户端发送的请求

401 Unauthorized：访问被拒绝，客户端试图未经授权访问受密码保护的页面

403 Forbidden：资源不可用。服务器理解客户的请求，但拒绝处理它，通常是由于服 务器上的文件或目录的权限设置导致

404 Not Found：所请求的页面不存在。通常是由于用户请求的页面不存在导致

5XX: Server Error（服务器错误状态码） 服务器处理请求出错

500 Internal Server Error：服务器遇到了意料不到的情况，不能处理客户的请求

501 Not Implemented：服务器不支持实现请求所需要的功能，页眉值指定了未实现 的配置

502 Bad Gateway：服务器作为网关或代理时，为了完成请求访问下一个服务器，但 该服务器返回了非法的应答

503 Service Unavailable：服务不可用，服务器由于维护或负载过重未能应答

504 Gateway Timeout：网关超时，由作为代理或网关的服务器使用，表示不能及时 地从远程服务器获得应答

Stateless: 无状态

http: 80/tcp

Tcp 三次握手，四次挥手

Keep-alive:

时间：timeout

数量：

Cookie 技术：

Session 保持

Session 绑定

反均衡

Session 不可用

Session 复制

服务器资源消耗过大

网络资源

Session 服务器

服务器自身的 HA

Lvs session 绑定：

Sh 算法：基于源 IP 做绑定

Persistent connection: 基于源 IP 做绑定

Cookie: Tengine

#### IO 模型

同步阻塞

同步非阻塞

IO 复用

Select()/poll()

Prefork: select()

事件通知

异步非阻塞(基于 epoll)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsktrdYH.jpg)

Reactor 模型还可以与多进程、多线程结合起来用，既实现异步非阻塞 IO，又利用到多核。目前流行的异步服务器程序都是这样的方式：如

- Nginx：多进程 Reactor

- Nginx+Lua：多进程 Reactor+协程

- Golang：单线程 Reactor+多线程协程

- Swoole：多线程 Reactor+多进程 Worker

mmap: 数据由磁盘直接以页面形式映射到内存中

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsPEsYhP.jpg)

(并发编程)处理并发用户请求：

单进程模型：串行方式响应

多进程模型：prefork， 一个进程响应一个用户请求，并发使用多个进程实现

多线程模型：worker， 一个进程生成多个线程，一个线程响应一个用户请求， 并发使用多个线程实现：n 进程，n*m 线程

事件模型：event，一个线程响应多个用户请求，基于事件驱动机制来维持多 个用户请求

#### Nginx 特性

基本功能：

静态资源的 web 服务器，能缓存打开的文件描述符

代理服务器(正向和反向)、缓存、负载均衡

支持 FastCGI

模块化，非 DSO 机制，过滤器 gzip，SSI 和图像大小调整等

支持 SSL

扩展功能：

基于名称和 IP 做虚拟主机

支持 keep-alive

支持平滑配置更新或程序版本升级

定制访问日志，支持使用日志缓存以提高性能

支持 URL rewrite

支持路径别名

支持基于 IP 及用户的认证

支持速率限制，并发限制等

Nginx 的基本架构：

一个 master，生成一个或多个 worker

事件驱动：kqueue, epoll, /dev/poll

消息通知：select, poll, rt signals(实时信号)

支持 sendfile, sendfile64

支持 AIO

支持 mmap

Nginx: 非阻塞、事件驱动、一个 master 多个 worker，一个 worker 响应多个用户请 求

#### Nginx 的模块类别

核心模块

标准 HTTP 模块

可选的 HTTP 模块

邮件模块

第三方模块

## Nginx 安装及配置

### 安装方法

编译安装

RPM 包安装

Yum/apt/brew 源

### Nginx 的配置文件

Main 配置段

```nginx
http {
}
```

配置参数以分号结尾，语法格式：

```nginx
参数名 值 1 [值 2 ...];
```

还支持使用变量：

模块内置变量

用户自定义变量

```nginx
set var_name value
```

### Nginx 基本核心配置的类别：

1. 用于调试、定位问题

2. 正常运行的必备配置

3. 优化性能的配置

4. 事件类的配置

### worker 进程应该以普通用户身份运行

nginx 用户、nginx 组

HTTP 的方法：GET/POST/PUT/DELETE/OPTIONS/TRACE/HEAD

### Nginx 的配置

**正常运行的必备配置**

1. `user username [groupname];`

指定运行 worker 进程的用户和组

2. `pid /path/to/pidfile_name;`

指定 nginx 的 pid 文件

3. `worker_rlimit_nofile #;`

指定一个 worker 进程所能够打开的最大文件句柄数、

4. `worker_rlimit_sigpending #;`

设定每个用户能够发往 worker 进程的信号的数量

**优化性能相关的配置**

1. `worker_processes #;`

2. CPU 的亲和性` worker_cpu_affinity cpumask ...;`

3. `ssl_engine device;`

在存在 ssl 硬件加速器的服务器上，指定所使用的 ssl 硬件加速设备

4. `timer_resolution t;`

每次内核事件调用返回时，都会使用 gettimeofday()来更新 nginx 缓存时钟；timer_resolution 用于定义每隔多久才会由 gettimeofday()更新一次缓存时钟

5. `worker_priority nice;`

[-20,20]之间的值

**事件相关的配置**

1. `accept_mutex [on|off]`

是否打开 nginx 的负载均衡锁：此锁能够让多个 worker 进程轮流地、序列化的 与新的客户端建立连接，而通常一个 worker 进程的负载均衡达到其上限的 7/8，master 就尽可能的不再将请求调度此 worker

2. `lock_file /path/to/lock_file;`

lock 文件

3. `accept_mutex_delay #ms;`

Accept 锁模式中，一个 worker 进程为取得 accept 锁的等待时长，如果某 worker 进程在某次试图取得锁时失败了，至少需要等待#ms 才能再一次请求锁。

4. `multi_accept [on|off]`

是否一次性地响应多个用户请求，默认为 off

5. `use [epoll|rtsig|select|poll];`

定义使用的事件模型，建议让 nginx 自动选择

6. `worker_connections #;`

每个 worker 能够并发响应的最大请求数

**用于调试、定位问题：只调试 nginx 使用**

1. `Daemon [on|off];`

是否让 nginx 运行于后台，默认为 on，调试时可以设置为 off，使得所有信息输出 至控制台

2. `Master_process [on|off]`

是否以 master/worker 的模式运行 nginx，默认为 on，调试时可设置为 off，方 便追踪

3. `Error_log /path/to/error_log error;`

错误日志文件及其级别，默认为 error 级别，调试时可以使用 debug 级别，但要求在编译时必须使用--with-debug 启用 debug 功能

## Nginx 的 HTTP 功能

必须使用虚拟主机来配置站点，每个虚拟主机使用一个 server{}端配置

非虚拟主机的配置或公共配置，需要定义在 server 之外，http 之内

### 虚拟主机相关的配置

1. `server{ }`

定义一个虚拟主机：Nginx 支持使用基于主机名或 IP 的虚拟主机

2. `listen`

```nginx
listen address[:port];
listen  port;
```

default_server: 定义此 server 为 HTTP 中默认的 server，如果所有的 server 中没 有任何一个 listen 使用此参数，那么第一个 server 即为默认的 server

rcvbuf=size: 接收缓冲大小

sndbuf=size: 发送缓冲大小

ssl: https server

3. `server_name [...];`

server_name 可以跟多个主机名，名称中可以使用通配符和正则表达式（通常以~开头），当 nginx 收到一个请求时，会取出其首部的 host 的值，而后跟 server_name 进行比较，比较方式：

- 先做精确匹配: www.magedu.com

- 左侧通配符匹配: *.magedu.com

- 右侧通配符匹配: [www.abc.com,](http://www.abc.com,) www.*

- 正则表达式匹配: ~^.*\.magedu\.com$

4. `server_names_hash_bucket_size 32|64|128;`

为了实现快速主机查找，nginx 使用 hash 表来保存主机名

5. ` location [ = | ~ | ~* | ^~ ] uri {...}`

```nginx
location @name{...}
```

功能：允许根据用户请求的 URI 来匹配指定的各 location 以进行访问配置，匹配到时， 将被 location 块中的配置所处理，例如： http://www.magedu.com/images/logo.gif

=: 精确匹配

~: 正则表达式模式匹配，匹配时区分字符大小写

~*: 正则表达式模式匹配，匹配时忽略字符大小写

^~:  URI 前半部分匹配，不检查正则表达式

匹配优先级：

字符字面量最精确匹配、正则表达式检索（由第一个匹配到的处理）、按字符字面量

### 文件路径定义

1. `root path`

设置 web 资源路径，用于指定请求的根文档目录

```nginx
location / {

root /www/htdocs;

}

location ^~ /images/ {

root /web;

}
```

2. `alias path`

只能用于 location 中，用于路径别名

3. `index file ...;`

定义默认页面，可跟多个值

4. `error_page ... [=[response]] uri;`

当对于每个请求返回错误时，如果匹配上了 error_page 指令中设定的 code，则重定 向到新的 URI 中，错误页面重定向

5. `try_files path1 [path2 ...] uri;`

尝试读取由 path 指定的路径，在第一次找到即停止并返回，如果所有 path 均不存在， 则返回最后一个 URI

```nginx
location ~* ^/documents/(.*)$ {

root /www/htdocs;

try_files $uri /docu/$1 /temp.html;

}
```

[http://www.magedu.com/documents/a.html](http://www.magedu.com/documents/a.html)

[http://www.magedu.com/docu/a.html](http://www.magedu.com/documents/a.html)

[http://www.magedu.com/temp.html](http://www.magedu.com/temp.html)

### 网络连接相关的设置

1. `keepalive_timeout time;`

保持连接的超时时长，默认为 75 秒

2. `keepalive_requests n;`

在一次长连接上允许承载的最大请求数

3. `keepalive_disable [msie6 | safari | none]`

对指定的浏览器禁止使用长连接

4. `tcp_nodelay on|off`

对 keepalive 连接是否使用 TCP_NODELAY 选项

5. `client_header_timeout time;`

读取 HTTP 请求首部的超时时间

6. `client_body_timeout time;`

读取 HTTP 请求包体的超时时长

7. `send_timeout time;`

发送响应的超时时长

### 对客户端请求的限制

1. ` limit_except method ... {...}`

指定对范围之外的其他方法的访问控制：

```nginx
limit_except GET {

allow 39.96.0.0/16;

deny all;

}
```

2. `client_max_body_size size;`

http 请求包体的最大值: 常用于限定客户端所能请求的最大包体(根据请求首部中的 Content-Length 来检测,以避免无用的传输)

3. ` limit_rate speed;`

限制客户端每秒钟传输的字节数，默认为 0，表示没有限制

4. `limit_rate_after time;`

Nginx 向客户端发送响应报文时，如果超出了此处指定的时长，则后续发送的过程开始 限速

### 文件操作的优化

1. `sendfile on|off`

是否启用 sendfile 功能

on: 使用零拷贝技术来传输文件，系统调用函数是sendfile()

off: 使用传统文件传输技术来传输文件，系统调用函数是read()+write()

2. `aio on|off`

是否启用 aio 功能

3. `open_file_cache max=N [inactive=time]|off`

是否启用文件缓存功能

max: 缓存条目的最大值，当满了以后将根据 LRU 算法进行置换

inactive: 某缓存条目在指定时长内没有被访问过时，将自动被删除，默认为 60s

缓存的信息包括：

文件句柄、文件大小和上次修改时间

已经打开的目录结构

没有找到或没有访问权限的信息

4. `open_file_cache_errors on|off`

是否缓存文件找不到或没有权限访问等相关信息

5. `open_file_cache_valid time;`

多长时间检查一次缓存的条目是否超出非活跃时长，默认为 60s

6. `open_file_cache_min_uses number;`

在 inactive 指定的时长内被访问超出此处指定的次数时，才不会被删除

### 对客户端请求的特殊处理

1. `ignore_invalid_headers on|off`

是否忽略不合法的 HTTP 首部，默认为 on，off 意味着请求首部中出现不合规的首部 将拒绝响应

2. `log_not_found on|off`

是否将文件找不到的信息也记录到错误日志中

3. `resolver address;`

指定 nginx 使用的 dns 服务器地址

4. `resolver_timeout time;`

指定 DNS 解析超时时长，默认为 30s

5. `server_tokens on|off`

是否在错误页面中显示 nginx 版本号

### HTTP 核心模块的内置变量

$uri: 当前请求的 uri，不带参数

$request_uri: 请求的 URI，带完整参数

$host: HTTP 请求报文中 host 首部，如果请求中没有 host 首部，则以处理此请求的虚拟 主机的主机名代替

$hostname: nginx 服务运行在的主机的主机名

$remote_addr: 客户端 IP

$remote_port: 客户端 port

$remote_user: 使用用户认证时客户端用户输入的用户名

$request_filename: 用户请求中的 URI 经过本地 root 或 alias 转换后映射到本地的文件

路径

$request_method: 请求方法

$server_addr: 服务器地址

$server_name: 服务器名称

$server_port: 服务器端口

$server_protocol: 服务器向客户端发送响应时的协议，如 HTTP/1.1, HTTP/1.0

$scheme: 在请求中使用 scheme，如[ https://www.magedu.com/]( https://www.magedu.com/)中的 https

$http_HEADER: 匹配请求报文中指定的 HEADER，$http_host 匹配请求报文中的 host 首部

$send_http_HEADER: 匹配响应报文中指定的 HEADER，如$send_http_content_type

匹配响应报文中的 content-type 首部

$document_root: 当前请求映射到的 root 配置

## 配置使用 Nginx

### 虚拟主机

```nginx
server {

listen

server_name

root

}
```

### 访问控制 access 模块

```nginx
allow
deny
```

### 用户认证

```nginx
location /admin/ {
   root /www/b.org;
   auth_basic "admin area";
   auth_basic_user_file /etc/nginx/.htpasswd;
}
```

### 建立下载站点时 autoindex 模块

### 防盗链

#### 定义合法的引用

```nginx
valid_referers none | blocked | server_names | string ...;
```

#### 拒绝不合法的引用

```nginx
if($invalid_referer) {

rewrite

}
```

#### URL rewrite

```nginx
rewrite regex replacement [flag];

location / {

root /www/b.org;

rewrite ^/images/(.*)$ /imgs/$1 last;

rewrite ^/imgs/(.*)$ /images/$1;

}
```

last: 一旦被当前规则匹配并重写后立即停止检查后续的其他 rewrite 规则，而后 通过重写后的规则重新发起请求

break: 一旦被当前规则匹配并重写后立即停止检查后续的其他 rewrite 规则，而 后继续由 nginx 进行后续操作

redirect: 返回 302 临时性重定向

permanent: 返回 301 永久性重定向

```nginx
location /download/ {

rewrite (/download/.*)/meida/(.*)\..*$ $1/media/$2.mp3 last;

}
```

Nginx 最多循环 10 次，超出之后将返回 500 错误

注意：一般将 rewrite 写在 location 中时都使用 break 标志，或者将 rewrite 写 在 if 上下文中

```nginx
rewrite_log on|off
```

是否把重写过程记录在错误日志中，默认为 notice 级别，默认为 off

```nginx
return code
```

用于结束 rewrite 规则，并且为客户端返回状态码

```nginx
if (condition) {

}
```

## 基于 Nginx 的中间件架构

### 静态资源类型

非服务器动态运行生成的文件

| 类型         | 种类                 |
| ------------ | -------------------- |
| 浏览器端渲染 | HTML、CSS、JS        |
| 图片         | JPEG、GIF、PNG       |
| 视频         | FLV、MPEG、MP4、M3U8 |
| 文件         | TXT 等任意下载文件   |

### 静态资源服务场景-CDN

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wps1Qpof2.jpg)

#### 配置语法

```nginx
sendfile   

Syntax: sendfile on|off;

Default: sendfile off;

Context: http, server, location, if in location

tcp_nopush

Syntax: tcp_nopush on|off;

Default: tcp_nopush off;

Context: http, server, location
```

作用：sendfile 开启的情况下，提高网络包的传输效率

```nginx
tcp_nodelay

Syntax: tcp_nodelay on|off;

Default: tcp_nodelay on;

Context: http, server, location
```

作用：keepalive 连接下，提高网络包的传输实时性

压缩

```nginx
Syntax: gzip on|off;

Default: gzip off;

Context: http, server, location,if in location
```

作用：压缩传输

 ```nginx
 Syntax: gzip_comp_level level;
 
 Default: gzip_comp_level 1;
 
 Context: http, server, location
 
  
 
 Syntax: gzip_http_version 1.0|1.1;
 
 Default: gzip_http_version 1.1;
 
 Context: http, server, location
 ```

### 浏览器缓存（web 缓存）

HTTP 协议定义的缓存机制（如：Expires, Cache-Control 等）

#### 校验过期机制

| 校验是否过期             | Expires, Cache-Control(max-age) |
| ------------------------ | ------------------------------- |
| 协议中 Etag 头信息校验   | Etag                            |
| Last-Modified 头信息校验 | Last-Modified                   |

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsd8BQY9.jpg)

#### 配置语法-expires

添加 Cache-Control, Expires 头

```nginx
Syntax: expires [modified] time;

  Expires epoch | max | off;

Default: expires off;

Context: http, server, location, if in location
```

### 跨域访问

Nginx 怎么做

```nginx
Syntax: add_header name value [always];

Default: --

Context: http, server, location, if in location

Access-Control-Allow-Origin 
```

### 防盗链

防盗链设置思路

首要方式：区别哪些请求是非正常的用户请求

#### 基于 http_referer 防盗链配置模块

```nginx
Syntax: valid_referers none|blocked|server_names|string ...;

Default: --

Context: server, location
```

### 代理服务

代理-代为办理（代理理财，代理收货等等）

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsn5ZD6a.jpg)

#### 正向代理

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpstyp8WW.jpg)

#### 反向代理

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsN6ifJx.jpg)

#### 代理区别

正向代理代理的对象是客户端

反向代理代理的对象是服务器端

#### 配置语法

反向代理

```nginx
Syntax: proxy_pass URL;

Default:--

Context: location, if in location, limit_except
```

http://localhost:8000/uri/ ;

https://localhost:8000/uri/ ;

http://unix:/tmp/backend.socket:/uri/;

缓冲区

```nginx
Syntax: proxy_buffering on|off;

Default: proxy_buffering on;

Context: http, server, location
```

扩展：proxy_buffer_size, proxy_buffers, proxy_busy_buffers_size

跳转重定向

```nginx
Syntax: proxy_redirect default; proxy_redirect off; proxy_redirect redirect   replacement;

Default: proxy_redirect default;

Context: http, server, location
```

头信息

```nginx
Syntax: proxy_set_header field value;

Default: proxy_set_header Host $proxy_host; proxy_set_header Connection  close;

Context: http, server, location
```

扩展：proxy_hide_header, proxy_set_body

超时

```nginx
Syntax: proxy_connect_timeout time;

Default: proxy_connect_timeout 60s;

Context: http, server, location
```

扩展：proxy_read_timeout, proxy_send_timeout

### 负载均衡

#### GSLB

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wps5sZiWC.jpg)

#### SLB

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsttjVVC.jpg)

#### 分为四层负载均衡和七层负载均衡

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wps1Kh40P.jpg)

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsPx4gn4.jpg)

#### 配置语法

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsx8TYy7.jpg)

```nginx
Syntax: upstream name {...};

Default: --

Context: http
```

Upstream 举例

```nginx
Upstream backend{

Server backend1.example.com weight=5;

Server backend2.example.com:8080;

Server unix:/tmp/backend3;

Server backend1.example.com:8080 backup;

Server backend2.example.com:8080 backup;

}
```

后端服务器在负载均衡调度中的状态

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsguvVZa.jpg)

#### 调度算法

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsaIMMFV.jpg)

url_hash:

```nginx
Syntax: hash key [consistent];

Default: --

Context: upstream;
```

This directive appeared in version 1.7.2.

### 缓存服务

客户端：客户端缓存（浏览器缓存）

Nginx：代理缓存（代理或者中间件）

服务器端：服务器端缓存（Memcache、Redis 等）

#### 代理缓存

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsyMZEDi.jpg)

#### 配置语法

proxy_cache_path

```nginx
Syntax: proxy_cache_path path [levels=levels]

[use_temp_path=on|off] [keys_zone=name:size] [inactive=time]

[max_size=size] [manager_files=number] [manager_sleep=time]

[manager_threshold=time] [loader_files=number]

[loader_sleep=time] [loader_threshold=time] [purger=on|off]

[purger_files=number] [purger_sleep=time]

[purger_threshold=time];

Default:--

Context: http
```

proxy_cache

```nginx
Syntax: proxy_cache zone|off;

Default: proxy_cache off;

Context: http, server, location
```

缓存过期周期

```nginx
Syntax: proxy_cache_valid [code...] time;

Default: --

Context: http, server, location
```

缓存的维度

```nginx
Syntax: proxy_cache_key string;

Default: proxy_cache_key $scheme$proxy_host$request_uri;

Context: http, server, location
```

#### 如何清理指定缓存

方式一：rm -rf 缓存目录内容

方式二：第三方扩展模块 ngx_cache_purge

#### 如何让部分页面不缓存

```nginx
Syntax: proxy_no_cache string;

Default: --

Context: http, server, location
```

#### 大文件的分片请求

```nginx
Syntax: slice size;

Default: slice 0;

Context: http, server, location 
```

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/nginx/wpsHas9m7.jpg)

优势：每个子请求收到的数据都会形成一个独立的文件，一个请求断了，其他请求不受影响。

缺点：当文件很大或者 slice 很小的时候，可能会导致文件描述符耗尽等情况。

## Nginx 实践和扩展

### LNMP 架构

### OpenResty

#### 作用及环境搭建

大多数时候通过合理的参数配置以及内核优化等方案就可以满足我们的业务场景，但是有些时候我们可能要扩展 Nginx 的某些功能，或者更大限度的榨取``Nginx 的性能，这时候我们可以通过编写 Nginx 扩展 Module 来实现。Nginx
扩展可以充分的利用 Nginx 异步事件机制，拥有非常高的性能。但是要用 C 语言实现的，并且要透彻的理解 Nginx 的各个处理过程，难度比较高。

OpenResty 给我们提供了另外一种方式，我们可以通过 Lua 代码来实现我们的功能。

**OR 简介**

OpenResty 又称 Ngx_Openresty，简称 OR，由国人章亦春(江湖人称春哥)开发和维护。这是一个基于 Nginx 和 Lua 的高性能 web 平台。它的内部集成了大量优秀的 Lua
库，第三方模块等。这样开发人员就可以使用 Lua 脚本调用 Nginx 支持的各种 C 以及 Lua 模块。快速构造出足以胜任 C10K 乃至 C1000K 以上单机并发连接的高性能 Web 应用系统。

在实际的工作中，使用到 OpenResty 最多的场景就是网关的开发。Lua 的脚本特性，加上 Nginx 的高效性，二者有效的融合在了一起，极大的加速了网关的开发。

**安装**

**测试**

#### 开发入门
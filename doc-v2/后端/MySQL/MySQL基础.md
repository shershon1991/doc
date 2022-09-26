---
title: "MySQL基础"
date: 2022-05-05
categories: [后端, MySQL]
tags: [MySQL]
cover: false
---

## MySQL基础

### MySQL 工作原理

大体来说，MySQL 分为 server 层和存储引擎层两部分。

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/mysql/wpsAC69HC.jpg)

连接器：负责跟客户端建立连接、获取权限、维持和管理连接

查询缓存：查询请求先访问缓存（key 是查询的语句，value 是查询的结果），命中 则直接返回；不推荐使用缓存，更新会把缓存清除（关闭缓存，参数 query_cache_type 设置为 demand）

分析器：对 SQL 语句做解析，判断SQL是否正确

优化器：确定使用哪个索引，多表关联（join）的时候，决定各个表的连接顺序

执行器：执行语句，先判断用户有无查询权限，使用表定义的存储引擎

### SQL语言/锁/事物及隔离级别

SQL 是结构化查询语句（Structured Query Language）的缩写，其功能包括数据查询语句、数据操纵语句（Data Manipulation Language, DML）、数据定义语句（Data Definition
Language, DDL）和数据控制语句（Data Control Language, DCL）四个部分。

#### 1.SQL 语言的功能

数据查询

```mysql
select *
from table
where 条件语句
```

数据操纵语句(DML)

```mysql
a. insert into table(字段 1, 字段 2, .
.., 字段 n) values(值1, 值2, .
.., 值 n)

b. delete from table where 条件语句

c. update table
set 字段 1 = 值 1, 字段 2=值 2,..., 字段 n=值 n where 条件语句
```

数据定义语句(DDL)

```mysql
a. create table table_name(字段 1, 字段 2, .
.., 字段 n)

b. drop table table_name
```

DCL

```mysql
a. grant 权限 on 数据库.数据表 to 用户名@登录主机 identified by "密码" [with
grant option]

b. revoke 权限 on 数据库.数据表 from 用户名@登录主机

c. show grants for 用户名@登录主机
```

insert 插入数据

第一种：

 ```mysql
  insert into tbl_name[(col1, col2, ...)] {
  values | value}(val1, val2, ...)[, (val21, val22, ...), ...]
 ```

第二种：

 ```mysql
 insert into tbl_name
 set col1=val1,
     col2=val2, ...
 ```

第三种(将一个表中的数据插入到另外一张表中)：

  ```mysql
  insert into tbl_name
  select clause
  ```

replace 替换表中数据，用法同 insert，除了在新插入的数据与表中的主键或唯一索引定义的数据相同会替换老的行

update 更新数据

```mysql
update [LOW_PRIORITY] [IGNORE] tbl_name

set col1 = val1[, col2 = val2] ...

  [where condition]

  [order by ...]

  [limit row_count]
```

update 通常情况下，必须要使用 where 字句，或者使用 limit 限制要修改的行数

--safe-updates：启动时应该带选项

delete：删除数据

```mysql
 delete [LOW_PRIORITY] [QUICK] [IGNORE]
 from tbl_name

     [
 where condition]

     [
 order by...]

  [
 limit row_count]
```

truncate tbl_name 重置表的所有内容

引申：delete 和 truncate 命令有哪些区别？

相同点：都可以用来删除一个表中的数据

不同点：

1. truncate 是一个 DDL，它会被隐式地提交，一旦被提交后将不能回滚。delete 执行的过程是每次从表中删除一行数据，同时将删除的操作以日志的形式进行保存以便以后进行回滚操作

2. 使用 delete 操作后，被删除的数据占用的存储空间还在，还可以恢复。而使用 truncate 操作后，被删除的数据会立即释放占用的存储空间，被删除的数据是不能被恢复的

3. truncate 执行的速度比delete快

其他术语

连接池：与用户请求建立连接

核心功能层： 查询解析，分析，优化，内置函数 跨存储引擎的功能

存储引擎层： 数据的写入和读取

协议：文本或者二进制，二进制的协议高效一些，MySQL 的发送默认为明文，可以 使用 ssl 加密数据

parser 的功能：词法，语法，语意分析，优化

explain：分析工具

query cache：缓存，只保存 select 查询

并发访问控制：基于锁来实现

#### 2.MySQL 锁

MySQL 锁可以分为读锁（别人可以读，不可以写，也称为共享锁）、写锁（别人不可以读，也不可以写，也称为独占锁/排它锁）

锁粒度

表锁：table lock 锁定了整张表

行锁：row lock 锁定了需要的行

粒度越小，开销越大，但是并发性越好。

锁的实现位置

MySQL 锁：可以手动设置（显式锁）

存储引擎锁：自动进行（隐式锁）

显式锁（表级锁）：

```mysql
LOCK
TABLE/UNLOCK
TABLE

LOCK
TABLE

tbl_name lock_type

[, tbl_name lock_type] .
..
```

lock_type(锁类型)：READ|WRITE

InnoDB 存储引擎也支持另外一种显式锁（锁定挑选出的部分行，行级锁）：

```mysql
SELECT... LOCK IN SHARE MODE

SELECT... FOR
UPDATE
```

#### 3.事物（transaction）

事务就是一组原子性的 SQL 查询，或者说一个独立的工作单元。

ACID 测试：能满足 ACID 测试就是表示其支持事物或者兼容事物。

A：Atomicity，原子性：一个事物必须被视为一个独立的工作单元，所有语句要 么都执行，要么都不执行

C：Consistency，一致性：数据库总是从一个一致性状态转移为另一个一致性状 态，而不会导致数据损失

I：Isolation，隔离性：一个事物所做的操作在提交之前对其他事物是不可见的

D：Durability，持久性：一旦事物得到提交，其所做的修改会永久有效

#### 4.隔离级别

| 隔离级别                     | 脏读 | 不可重复读 | 幻读 |
| ---------------------------- | ---- | ---------- | ---- |
| READ UNCOMMITTED（读未提交） | 是   | 是         | 是   |
| READ COMMITTED（读已提交）   | 否   | 是         | 是   |
| REPEATABLE READ（可重复读）  | 否   | 否         | 是   |
| SERIALIZABLE（可串行化）     | 否   | 否         | 否   |

启动事物：`START TRANSACTION`

事物提交：`COMMIT`

事物回滚：`ROLLBACK`

savepoint 控制回滚的位置

```mysql
SAVEPOINT identifier

ROLLBACK [WORK] TO [SAVEPOINT] identifier
```

注意：如果没有显式地启动事物，每条语句都会被当做一个独立的事物，其执行完成之后会自动提交。

```mysql
SELECT @@global.autocommit;

SET GLOBAL autocommit = 0;
```

查看 MySQL 的事物隔离级别

```mysql
SHOW GLOBAL VARIABLES LIKE 'tx_isolation';

SELECT @@global.tx_isolation;

SET GLOBAL tx_isolation = 'READ_UNCOMMITTED';
```

建议：对事物要求不特别严格的场景下，可以使用读已提交。

MVCC：Multi-Version Concurrency Control，多版本并发控制

每个事物启动时，InnoDB 会为每个启动的事物提供一个当下时刻的快照，为了实现此功能，InnoDB 会为每个表提供两个隐藏的字段，一个用于保存行的创建时间，一个用于保存行的失效时间，里面存储的是系统版本号（system version
number），只在两个隔离级别下有效：RC、RR

### MySQL 存储引擎对比

存储引擎通常被称为“表类型”

MySQL > show engines;

MySQL > show table status;

SHOW TABLE STATUS [{FROM | IN} db_name]

[LIKE 'pattern' | where expr]

MySQL > show table status in hellodb where name=’class’G

Name： 表名

Engine： 存储引擎

Version：版本

Row_format：行格式

{DEFAULT|DYNAMIC|FIXED|COMMPRESSED|REDUNDANT|COMPACT}

Rows：表中的行数

Avg_row_length：平均每行包含的字节数

Data_length：表中数据总体大小，单位为字节

Max_data_length：表能够占用的最大空间，单位为字节，0 表示没有上限

Index_length：索引的大小，单位为字节

Data_free：对于 MyISAM 表，表示已经分配但尚未使用的空间，其中包含此前删除 行之后腾出来的空间

Auto_increment：下一个 AUTO_INCREMENT 的值

Create_time：表的创建时间

Update_time：表数据的最后一次修改时间

Check_time：使用 CHECK TABLE 或 myisamchk 最近一次检查表的时间

Collation：排序规则

Checksum：如果启动，则为表的 checksum

Create_options：创建表时指定使用的其他选项

Comment：表的注释信息

#### 1.InnoDB

两种格式：

1. Innodb_file_per_table=OFF，即使用共享表空间

每个表有一个独有的格式定义文件：tbl_name.frm

还有一个默认位于数据目录下的共享的表空间文件：ibdata#

2. Innodb_file_per_table=ON，即使用独立表空间

每个表在数据库目录下存储两个文件：

tbl_name.frm

tbl_name.ibd

#### 2.MyISAM

每个表在数据库目录下存储三个文件：

tbl_name.frm

tbl_name.MYD

tbl_name.MYI

#### 3.表空间

Table space，由 InnoDB 管理的特有的格式数据文件，内部可同时存储数据和索引

#### 4.各存储引擎的特性

如何修改默认的存储引擎，通过 default_storage_engine 服务变量来实现

1. InnoDB

a. 支持事物，有事物日志 ib_logfile0, ib_logfile1

b. 支持外键约束

c. 支持 MVCC

d. 支持聚簇索引（聚簇索引之外的索引，通常称之为辅助索引）

e. 行级锁：间隙锁

f. 支持使用辅助索引

g. 支持自使用 hash 索引

h. 支持热备份

2. MyISAM

a. 优点

i. 全文索引

ii. 支持表压缩存放：做数据仓库，能节约存储空间并提升性能

iii. 支持空间索引

iv. 表级锁

v. 延迟更新索引

b. 缺点

i. 不支持事物、外键和行级锁

ii. 崩溃后无法安全恢复数据

c. 使用场景：只读数据，表较小，能够忍受崩溃后的修复操作和数据丢失

3. ARCHIVE

a. 仅支持 INSERT 和 SELECT，支持很好的压缩功能

b. 应用于存储日志信息，或其他按照时间序列实现的数据采集类的应用

4. CSV

a. 将数据存储为 CSV 格式，不支持索引，仅使用于与数据交换的场景

5. BLACKHOLE

a. 没有存储机制，任何发往此引擎的数据都会丢弃，其会记录二进制日志，因此，常用于多级复制架构中作中转服务器

6. MEMORY

a. 保存数据在内存中，内存表；常用于保存中间数据，如周期性的聚合数据等，也用于实现临时表

b. 支持 hash 索引，使用表级锁，不支持 BLOB 和 TEXT 数据类型

7. MRG_MYISAM

a. 是 MYISAM 的一个变种，能够将多个 MyISAM 表合并成一个虚表

8. NDB

a. 是 MySQL CLUSTER 中专用的存储引擎

9. 第三方的存储引擎

OLPT：

XtraDB：增强的 InnoDB，有 Percona 提供

​ 编译安装时，下载 XtraDB 的源码替代 MySQL 存储引擎中的 InnoDB 的 源码

PBXT：MariaDB 自带此存储引擎

​ 支持引擎级别的复制、外键约束，对 SSD 磁盘提供适当支持

​ 支持事务、MVCC

TokuDB：使用 Fractal Trees 索引，适用存储大数据，拥有很好的压缩比，已 经被引入 MariaDB

列式数据存储引擎：

Infobright：目前较有名的列式引擎，适用于海量数据存储场景，如 PB 级别， 专为数据分析和数据仓库设计

InfiniDB

MonetDB

LucidDB

开源社区存储引擎：

Aria：前身为 Maria，是增强版的 MyISAM（支持崩溃后安全恢复，支持数据 缓存）

Groona：全文索引引擎

Mroonga：是基于 Groona 的二次开发版

OQGraph：由 open query 研发，支持图（网状 ）结构的存储引擎

SphinxSE：为 Sphinx 全文搜索服务器提供了 SQL 接口

Spider：能将数据切分成不同的分片，比较高效透明的实现了分片 （shared），并支持在分片上支持并行查询

如何选择存储引擎？

l 是否需要事务

l 备份的类型的支持

l 崩溃后的恢复

l 特有的特性

#### 5.索引类型

聚簇索引

辅助索引

B-Tree 索引

R-Tree 索引

Hash 索引

全文索引

### MySQL 用户管理

用户账号：username@hostname

用户账号管理：

```mysql
Create user
    CREATE USER username@hostname [IDENTIFIED BY 	‘PASSWORD’]

Drop user
    Rename user

Set password
```

权限管理：

```mysql
Grant

Revoke
```

主机也可以使用通配符： mailto:testuser@’196.168.110.1__'

表示可以使用 110.100-110.199

查看用户能够使用的权限：

```mysql
show grants for 'username'@'hostname'
```

rename user

```mysql
RENAME USER old_user TO new_user[, old_user TO new_user] ...

RENAME USER 'jeffrey'@'localhost' TO mailto:'jeff'@'127.0.0.1';
```

grant

MySQL 的权限类型：

​ 库级别

​ 表级别

​ 字段级别

​ 管理类

​ 程序类

管理类权限

​ create temporary tables 临时表

​ create user

​ file 允许用户读或者写某些文件

​ lock tables 添加显式锁

​ process 查看用户的线程

​ reload 相当于执行 flush 和 reset

​ replication client 查询有哪些复制客户端

​ replication slave 赋予用户复制权限

​ show databases

​ shutdown

​ super

数据库访问权限

​ alter

​ alter routine 存储过程

​ create

​ create routine 存储过程，存储函数

​ create view

​ delete

​ drop

​ execute

​ grant option 将自己的权限复制给别的用户

​ index 索引

​ show view

数据操作类权限（表级别）：

​ select

​ insert

​ update

​ delete

字段级别：

​ select (col1, ...)

​ update (col1, ...)

​ insert (col1, ...)

GRANT

priv_type [(column_list)]

[, priv_type [(column_list)]] ...

ON [object_type] priv_level

TO user_specification [, user_specification] ...

[REQUIRE {NONE | ssl_option [[AND] ssl_option] ...}]

[WITH with_option ...]

GRANT PROXY ON user_specification

TO user_specification [, user_specification] ...

[WITH GRANT OPTION]

object_type:

TABLE

| FUNCTION

| PROCEDURE

priv_level:

*

| *.*

| db_name.*

| db_name.tbl_name

| tbl_name

| db_name.routine_name

user_specification:

user

[

​ IDENTIFIED BY [PASSWORD] 'password'

​ | IDENTIFIED WITH auth_plugin [AS 'auth_string']

]

ssl_option:

SSL

with_option:

GRANT OPTION 转赠给别人

| MAX_QUERIES_PER_HOUR count 每小时允许执行的最大查询次数

| MAX_UPDATES_PER_HOUR count 每小时允许执行的最大更新次数

| MAX_CONNECTIONS_PER_HOUR count 每小时允许执行的最大连接次数

| MAX_USER_CONNECTIONS count 使用同一个账号可以同时连接的次数

要想创建库应该对所有表都有权限

REVOKE 收回授权

priv_type [(column_list)]

[, priv_type [(column_list)]] ...

ON [object_type] priv_level

FROM user [, user] ...

REVOKE ALL PRIVILEGES, GRANT OPTION

FROM user [, user] ...

REVOKE PROXY ON user

FROM user [, user] ...

几个跟用户授权相关的表：

db：库级别的权限

host：主机级别权限，已废弃

tables_priv：表级别权限

columns_priv：字段级别的权限

procs_priv：存储过程和存储函数相关的权限

proxies_priv：代理用户权限

练习：

1、授权 testuser 能够通过 172.16.0.0/16 网络内的任意主机访问当前 MySQL 服务 器的权限

grant alter on *.* to 'testuser'@'172.16.%.%' identified by 'password'

2、让此用户能够创建和删除 testdb 数据库，及库中的表

grant create,drop on testdb.* to 'testuser'@'172.16.%.%';

3、让此用户能够在 testdb 库中的 t1 表中执行查询、删除、更新和插入操作

grant select,update,insert,delete on testdb.t1 to 'testuser'@'172.16.%.%'

4、让此用户能够在 testdb 库上创建和删除索引

grant index,drop index on testdb to 'testuser'@'172.16.%.%';

5、让此用户能够在 testdb.t2 表上查询 id 和 name 字段，并允许其将此权限授予其 他用户

grant select(id,name) on testdb.t2 to 'testuser'@'172.16.%.%'

grant grant option on testdb.t2 to 'testuser'@'172.16.%.%'

### MySQL 查询缓存

用于保存 MySQL 查询语句返回的完整结果，被命中时，MySQL 会立即返回结果，省去解析、优化和执行等操作。

如何检查缓存？

MySQL 保存结果于缓存中，把 select 语句本身做 hash 计算，计算的结果作为 key，查询结果作为 value

什么样的语句不会被缓存？

查询语句中有一些不确定数据时，不会缓存；例如 now()，current_time()；一般来说，如果查询中包含用户自定义函数、存储函数、用户变量、临时表、MySQL 库中系统表、或者任何包含权限的表，一般都不会缓存

缓存会带来额外开销

1、每个查询都会先检查是否命中

2、查询结果要先缓存

MySQL> show global variables like 'query_cache%';

+------------------------------+----------+

| Variable_name | Value |

+------------------------------+----------+

| query_cache_limit | 1048576 |

| query_cache_min_res_ungit | 4096 |

| query_cache_size | 16777216 |

| query_cache_type | ON |

| query_cache_wlock_invalidate | OFF |

+------------------------------+----------+

query_cache_type: 查询缓存类型；是否开启缓存功能，开启方式有三种

{ON|OFF|DEMAND}。DEMAND：意味着 select 语句明确使用 SQL_cache 选项才会缓存

query_cache_size：总空间。单位为字节，大小必须为 1024 的整数倍。MySQL 启 动时，会一次分配并立即初始化这里指定大小的内存空间；这意味着，如果修改 此大小，会清空缓存并重新初始化

query_cache_min_res_unit：存储缓存的最小内存块(query_cache_size- Qcache_free_memory)/Qcache_queries_in_cache 能够获得一个理想的值

query_cache_limit：单个缓存对象的最大值，超出时则不予缓存；手动使用 SQL_NO_CACHE: 可以人为的避免尝试缓存返回超出此参数限定值的语句

query_cache_wlock_invalidate：如果某个表被其他用户连接锁住了，是否仍然从缓 存中返回结果，OFF 表示返回

如何判断命中率

分为次数和字节命中率

MySQL> show global status like 'Qcache%';

+-------------------------+----------+

| Variable_name | Value |

+-------------------------+----------+

| Qcache_free_blocks（空闲块数） | 1 |

| Qcache_free_memory（空闲空间） | 16759688 |

| Qcache_hits（命中次数） | 0 |

| Qcache_inserts（向缓存空间中插入的缓存的次数） | 0 |

| Qcache_lowmem_prunes（内存太小，修剪内存的次数） | 0 |

| Qcache_not_cached（没被缓存的个数） | 8 |

| Qcache_queries_in_cache（缓存中缓存的查询个数） | 0 |

| Qcache_total_blocks（总块数） | 1 |

+-------------------------+----------+

碎片整理 flush query_cache

清空缓存 reset query_cache

计算命中率

show global status where variable_name='Qcache_hits' OR

variable_name='Com_Select';

Qcache_hits/(Qcache_hits + Com_Select)

也可以参考另外一个指标，命中和写入的比率，即 Qcache_hits/Qcache_inserts 的值，此比值如果能大于 3:1. 则表明缓存也是有效的，能达到 10:1，为比较理想的情况

缓存优化思路

1.批量写入，而非多次单个写入

2.缓存空间不宜过大，因为大量缓存同时失效时会导致服务器假死

3.必要时，使用 SQL_CACHE 和 SQL_no_cache 手动控制缓存。

4.对写密集型的应用场景来说，禁用缓存反而提高性能。

### MySQL 日志

查询日志：默认为关闭

慢查询日志：查询执行时长超过指定时长的查询，即为慢查询

错误日志：

二进制日志：记录修改相关的操作，用来实现复制的凭据

中继日志：从服务器上的二进制日志

事务日志：将随机 I/O 转换为顺序 I/O

日志文件组：至少要存在两个，实现轮询

注意：尽可能使用小事务来替代大事务来提升事务引擎的性能

查询日志

log：{ON|OFF}：是否记录所有语句的日志信息于一般查询日志文件（general_log）

log_output={TABLE|FILE|NONE}

table 和 file 可以同时出现，用逗号分隔即可

general_log：是否启用查询日志

general_log_file：定义了一般查询日志保存的文件

慢查询日志

slow_query_log={ON|OFF}

是否启用慢查询日志，它的输出位置也取决于

log_output={table|file|none}

slow_query_log_file：www-slow.log

定义慢查询日志的文件

long_query_time : 10.00000 慢查询的时间

错误日志

服务器启动和关闭过程中的信息

服务器运行过程中的错误信息

事件调度器运行一个事件时产生的信息

在复制架构中的从服务器上启动从服务器线程时产生的信息

log_error = /path/to/error_log_file

log_warnings = {1|0}

是否记录警告信息保存至错误日志中

二进制日志

时间点恢复

复制 










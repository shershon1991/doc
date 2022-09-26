---
title: "SQL 优化"
date: 2022-05-05
categories: [后端, MySQL]
tags: [MySQL]
cover: false
---

### SQL 优化

#### 1.快速学会分析SQL执行效率

定位慢 SQL

1.通过慢查询日志确定已经执行完的慢查询

a. 何为慢查询日志？

​ i. 响应时间 >= 参数 long_query_time(单位秒，默认 10)

​ ii. 扫描记录数 >= 参数 min_examined_row_limit(默认值 0)

b. 使用慢查询日志，一般分为四步：

​ i. 开启慢查询日志(set global slow_query_log = on;)

​ ii. 设置慢查询的阈值(set global long_query_time = 1;)

​ iii. 确定慢查询日志路径(show global variables like “datadir”;)

​ iv. 确定慢查询日志的文件名(show global variables like “slow_query_log_file”;)

2.show processlist 查看正在执行的慢查询

#### 2.分析慢查询

我们可以通过 explain、show profile 和 trace 等诊断工具来分析慢查询。

1. **使用 explain 分析慢查询**

可以获取 MySQL 中 SQL 语句的执行计划。

2. **show profile 分析慢查询**

2.1. 确定是否支持 profile

select @@have_profiling;

2.2. 查看 profiling 是否关闭着的

select @@profiling;

2.3. 通过 set 开启 profiling

set profiling=1; (ps: 没加 global，只对当前 session 有效)

2.4. 执行 SQL 语句

2.5. 确定 SQL 的 query id

通过 show profiles 确定执行过的 SQL 的 query_id

2.6. 查询 SQL 执行详情

通过 show profile for query No. 可以看到执行过的 SQL 的每个状态和消耗时间

3. **trace 分析 SQL 优化器**

通过 trace，能够进一步了解为什么优化器选择 A 执行计划而不是选择 B 执行计划，或者知道某个排序使用的排序模式，帮助我们更好地理解优化器行为。

3.1开启 trace，设置输出格式为 json

set session optimizer_trace="enabled=on",end_markers_in_json=on;

3.2执行 SQL 语句

3.3查询

select * from infor库将改页读入mation_schema.OPTIMIZER_TRACEG

#### 3.条件字段有索引，为什么查询还这么慢

有索引但是查询不走索引导致查询慢的几种场景：

- 函数操作

1. 验证对条件字段做函数操作是否能走索引

2. 对条件字段做函数操作不走索引的原因

索引树中存储的是列的实际值和主键值，如果拿'2020-05-21'去匹配'2020-05-21 00:00:00'，将无法定位到索引树中的值，因此放弃走索引，选择全表扫描。

3. 函数操作的 SQL 优化

类似于求某一天或某一个月的需求，建议写成范围查询，可以让查询走索引。

- 隐式转换

1. 认识隐式转换

何为隐式转换？

当操作符与不同类型的操作对象一起使用时，就会发生类型转换以使操作兼容。

2. 验证隐式转换是否能走索引

3. 不走索引的原因

对索引字段做函数操作（隐式操作）时，优化器会放弃使用索引。

4. 隐式转换的 SQL 优化

建议在写 SQL 时，先看字段类型，然后根据字段类型再写 SQL。

- 模糊查询

1. 分析模糊查询

通配符在前面不走索引。如：select * from t1 where a like '%1111%';

2. 模糊查询优化建议

a. 修改业务，让模糊查询必须包含条件字段前面的值。如：select * from t1 where a like '1111%';

b. 如果条件只知道中间的值，需要模糊查询，建议使用 ES 或其他搜索服务器。

- 范围查询

1. 构造不能使用索引的范围查询

不能走索引的原因。如：select * from t1 where b>=1 and b<=5000;

优化器会根据检索比例、表大小、I/O 块大小等进行评估是否使用索引，比如单 次查询的数据量过大，优化器将不走索引。

2. 优化范围查询

降低单次查询范围，分多次查询。如将：

select * from t1 where b>=1 and b<=5000 改写成

select * from t1 where b>=1 and b<=2500;

select * from t1 where b>=2501 and b<=5000;

实际上这种范围查询导致使用不了索引的场景经常出现，比如按照时间段抽取全量数据，每条 SQL 抽取一个月的；或者某张业务表历史数据的删除。遇到此类操作时，应该在执行之前对 SQL 对 explain
分析，确定能走索引，再进行操作，否则不但可能导致操作缓慢，在做更新或者删除时，甚至会导致表所有记录锁住，十分危险！

- 运算操作

1. 查询条件有运算操作的 SQL 不走索引（运算操作在“=”前）

原因：对索引字段做运算将使用不了索引。

2. 运算操作的 SQL 优化

a. 将运算操作放到等号后面。

b. 一般需要对条件字段做运算时，建议通过程序代码实现，而不是通过 MySQL 实现。如果在 MySQL 中运算的情况避免不了，那必须把运算操作放到等号后面。

3. 如何优化数据导入

一次插入多行的值

插入行所需的时间由以下因素决定(参考 MySQL5.7 参考手册)

l 连接：30%

l 向服务器发送查询：20%

l 解析查询：20%

l 插入行：10% * 行的大小

l 插入索引：10% * 索引数

l 结束：10%

可以发现大部分时间耗费在客户端和服务器端通信的时间，因此可以使用 insert 包含多个值来减少客户端和服务器端之间的通信。

关闭自动提交

与一次插入多行能提高批量插入速度一样，因为批量导入大部分时间耗费在客户端和服务器端通信的时间，所以多条 insert 语句合并提交可以减少客户端和服务器端通信的时间，并且合并提交还可以减少数据落盘的次数。

参数调整

innodb_flush_log_at_trx_commit、sync_binlog

1. 让 order by、group by 查询更快

order by 原理

1. MySQL 的排序方式

按照排序原理分，分为两种：

l 通过有序索引直接返回有序数据

Extra 中显示：Using index

l 通过 Filesort 进行的排序

Extra 中显示：Using filesort

2. Filesort 是在内存中还是在磁盘中完成排序的？

内存排序还是磁盘排序取决于排序的数据大小和 sort_buffer_size 配置的大小

l 若 排序的数据大小 < sort_buffer_size: 内存排序

l 若 排序的数据大小 > sort_buffer_size: 磁盘排序

1. Filesort 下的排序模式

a. 排序模式

i. <sort_key, rowid> 双路排序

ii. <sort_key, additional_fields> 单路排序

iii. <sort_key, packed_additional_fields> 打包数据排序，单路排序的升级模式

b. 使用哪种排序模式？

i. 若 max_length_for_sort_data > 查询字段的总长度: 单路排序

ii. 若 max_length_for_sort_data < 查询字段的总长度: 双路排序

order by 优化

1. 添加合适索引

a. 排序字段添加索引

b. 多个字段排序: 可以在多个字段上添加联合索引来优化排序语句

c. 先等值查询再排序: 可以通过在条件字段和排序字段添加联合索引来优化排序语句

2. 去掉不必要的返回字段

a. 有时，查询所有字段的 SQL 是 filesort 排序，只查部分字段的 SQL 是 index 排序。这是因为: 扫描整个索引并查找到没索引的行的成本比扫描全表的成本更高，所以优化器放弃使用索引

3. 修改参数

4. 几种无法使用索引排序的情况

a. 使用范围查询再排序

b. asc 和 desc 混合使用将无法使用索引

group by 优化

默认情况，会对 group by 字段排序，因此优化方式与 order by 基本一致，如果目的只是分组而不用排序，可以指定 order by null 禁止排序。

5. 换种思路写分页查询

根据自增且连续的主键排序的分页查询

根据非主键字段排序的分页查询

1. join 语句可以这样优化

关联查询的算法

1. Nested-Loop Join 算法

2. Block Nested-Loop Join 算法

3. Batched Key Access 算法

优化关联查询

1. 关联字段添加索引

2. 小表做驱动表

3. 临时表

为什么 count(*)这么慢

重新认识 count()

1. count(a)和 count(*)的区别

a. count(a)，a 表示列名，是不统计 null 的

b. count(*)，无论是否包含空值，都会统计

2. MyISAM 和 InnoDB 引擎 count(*)的区别

a. 对于 MyISAM 引擎，如果没有 where 子句，也没有检索其他列，count(*)非常快，因为 MyISAM 引擎会把表的总行数存在磁盘上

b. InnoDB 并不会保留表中的行数，因为并发事务可能同时读取到不同的行数，所以执行 count(*)都是临时去计算的，比 MyISAM 引擎慢得多

3. MySQL5.7.18 前后 count(*)的区别

在 MySQL 5.7.18 之前，InnoDB 通过扫描聚簇索引来处理 count(*) 语句。

从 MySQL 5.7.18 开始，通过遍历最小的可用二级索引来处理 count(*) 语句。 如果不存在二级索引，则扫描聚簇索引。但是，如果索引记录不完全在缓存池中 的话，处理count(*) 也是比较久的。

新版本为什么会使用二级索引来处理 count(*) 语句呢？

原因是 InnoDB 二级索引树的叶子节点上存放的是主键，而主键索引树的叶子节 点上存放的是整行数据，所以二级索引树比主键索引树小。因此优化器基于成本 的考虑，优先选择的是二级索引。所以 count(主键) 其实没 count (*) 快。

count(1)比 count(*)速度快吗？

count(*)会统计所有结果

count(1)中 1 是恒真表达式，因此也会统计所有结果

所以 count(1)和 count(*)没有差别。

哪些方法可以加快 count()?

1. show table status

2. 用 Redis 做计数器

3. 增加计数表
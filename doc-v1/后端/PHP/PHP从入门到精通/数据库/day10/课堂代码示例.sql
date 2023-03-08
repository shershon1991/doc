//演示主键的作用：保证每一行数据具有唯一性：
create table tab_zhujian1(
	id int,
	name varchar(10)
);
insert into tab_zhujian1 values(1, 'aa');
insert into tab_zhujian1 values(1, 'aa');
//以下为对比表（及对比数据）
create table tab_zhujian2(
	id int,
	name varchar(10),
	primary key (id)
);	
insert into tab_zhujian2 values(1, 'aa');
insert into tab_zhujian2 values(1, 'aa');

//下面演示replace into语句：
insert into tab_zhujian2 values(1, 'bb');//这行不行，报错

//下面演示insert into ... select ...  语句：
insert into tab_zhujian1 select * from tab_zhujian2;


演示load data语法：
先看要“载入”的数据：

1  罗弟华  男  江西   1
2  韩顺平  男  四川   2
3  昊英雷  男  黑龙江 1
4  王玉虹  女  河北   3
5  赵玉川  男  河北   3
6  刘招英  女  江西   1

然后创建一个符合该数据结构的表：
create table tab_load_data(
	id int auto_increment primary key,
	name varchar(10),
	sex enum('男', '女'),
	jiguan varchar(10),
	f5 int
);
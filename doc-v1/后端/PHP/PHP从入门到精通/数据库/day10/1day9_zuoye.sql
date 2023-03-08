 1.建一个innodb类型且字符集为ytf8的表，其中包括以下类型的字段：
 int, float, char, varchar, datetime, date, text, enum, set.
 并且在自增长的int类型字段上有主见，varchar类型字段上有普通索引
 create table day9_zuoye(
 	id int auto_increment,
 	salary float comment '工资',
 	postcode char(6) comment '邮编',
 	name varchar(10),
 	reg_time datetime comment '注册时间',
 	birthday date comment '生日',
 	intro text comment '自我介绍',
 	sex enum('男', '女'),
 	aihao set('篮球', '排球', '足球', '羽毛球'),
 	primary key(id),
 	key(name) 
 ) engine = InnoDB, charset = utf8;

 2.给该表添加一个int字段，默认值是18；
 	alter table day9_zuoye add age int default 18;

 3.修改表中的char类型字段设定的长度；
 	alter table day9_zuoye change postcode postcode char(8) comment '邮编';

 4.修改表名。
 	alter table day9_zuoye rename to day9_zuoye2;
 	
 5.再创建跟前面那个同样的表，表的名字在前一个名字的基础上加一个“2”，但其表类型是myisam，观察/date目录下的表文件跟前一个表的异同。
 	create table day9_zuoye22 like day9_zuoye2;
 	alter table day9_zuoye22 engine = MyIsam;	
#演示varchar, char的使用：
create table tab_char_varchar(
	postcode char(6), /*中国邮政编码*/
	name varchar(10) /*姓名*/
);

#演示enum,set的使用：
create table enum_set(
	id int auto_increment primary key,
	sex enum('男', '女'),
	fav set('篮球', '排球', '足球', '中国足球', '台球')
);

#插入数据演示：
insert into enum_set(id, sex, fav) values(null, '男', '篮球');
insert into enum_set(id, sex, fav) values(null, 1, 1);
#下面演示多选项的数据输入情形：
insert into enum_set(id, sex, fav) values(null, '男', '篮球,排球,台球');
insert into enum_set(id, sex, fav) values(null, '女', 19);
#这里，19=1+2+16，也就是对应篮球，排球和台球
#这里，19不可能解释为：15+4或其他。。。

#演示时间日期类型的字段使用：
create table tab_time(
	dt datetime,
	d2 date,
	t2 time,
	y  year,
	ts timestamp
);
insert into tab_time(dt, d2, t2, y) values('2016-9-14 10:12:30', '2015/7/8', '13:12:12', '2014');

#演示字段属性的使用：
create table tab_shuxing(
	id int auto_increment primary key,
	user_name varchar(20) not null unique key,
	password varchar(48) not null,
	age tinyint default 18,
	email varchar(50) comment '电子邮箱'
);

insert into tab_shuxing(id, user_name, password, age, email) values(1, 'user1', '1234', 20, 'admin@qq.com');
insert into tab_shuxing(id, user_name, password, age, email) values(null, 'user2', md5('1234'), null, 'ldh@qq.com');
insert into tab_shuxing(user_name, password, email) values('user3', md5('123456'), 'ldh@qq.com');

#演示索引创建语法：
create table tab_suoyin(
	id int auto_increment,
	user_name varchar(20),
	email varchar(50),
	age int,				/*没有索引*/
	key (email),			/*这是普通索引*/
	primary key(id), 		/*这是主键索引*/
	unique key(user_name)	/*这就是唯一索引*/
); 

#演示外键索引：
create table banji(
	id int auto_increment primary key,
	banjihao varchar(10) unique key comment '班级号',
	banzhuren varchar(10) comment '班主任',
	open_date date comment '开班日期'
);

create table xuesheng(
	stu_id int auto_increment primary key,
	name varchar(10),
	age tinyint,
	banji_id int comment '班级id',
	foreign key (banji_id) references banji(id)
);

#演示表选项语法：
create table tab_xuanxiang(
	id int auto_increment primary key,
	name varchar(10),
	age tinyint
);
charset = utf8,  /*当前数据库的字符编码是utf8*/
engine = MyIsam,
auto_increment = 1000,
comment = '说明文字'
;
insert into tab_xuanxiang (id, name, age) values(null, '张三', 11);

#下面演示修改表：
alter table tab_xuanxiang add column email varchar(50);
alter table tab_xuanxiang add key (age); /*添加一个普通索引*/

#创建一个视图：

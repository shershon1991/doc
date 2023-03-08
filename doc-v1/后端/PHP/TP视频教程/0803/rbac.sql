#创建管理员表
create table ci_manager(
	mg_id int(11) not null auto_increment,
	mg_name varchar(32) not null,
	mg_pwd varchar(32) not null,
	mg_time int(10) unsigned not null comment '时间',
	mg_role_id tinyint(3) unsigned not null default 0 comment '角色id',
	primary key(mg_id)
)engine=InnoDB auto_increment=1 default charset=utf8

#创建权限表
create table ci_auth(
	auth_id smallint(6) unsigned not null auto_increment,
	auth_name varchar(20) not null comment '权限名称',
	auth_pid smallint(6) unsigned not null comment '父id',
	auth_c varchar(32) not null  default '' comment '控制器',
	auth_a varchar(32) not null comment '操作方法',
	auth_path varchar(32) not null comment '全路径',
	auth_level tinyint(4) not null default 0 comment '级别',
	primary key(auth_id)
)engine=InnoDB auto_increment=1 default charset=utf8
	① 顶级权限：全路径等于当前记录的主键ID值
	② 非顶级权限：全路径等于“父级全路径-本身ID值”
		id  name      pid    path
		101 新闻中心  0      101
		124 公司新闻  101    101-124

#创建角色表
create table ci_role(
	role_id smallint(6) unsigned not null auto_increment,
	role_name varchar(20) not null comment '角色名称',
	role_auth_ids varchar(128) not null default '' comment '权限ids,1,2,5',
	role_auth_ac text comment '控制器-操作，控制器-操作，控制器-操作',
	primary key(role_id)
)engine=InnoDB auto_increment=1 default charset=utf8

角色：
	董事长
	总监
	高级经理
	经理
	项目经理
	主管
	客服
	技术支持
	美工
	员工

数据模拟：
① 权限数据
商品管理（商品列表、添加商品、商品分类）
订单管理（订单列表、订单查询、订单打印）
权限管理（管理员列表、角色管理、权限列表）

id 		name  		pid 	c 		a 		path 		level
insert into ci_auth values(100,'商品管理',0,'','','100',0);
insert into ci_auth values(101,'订单管理',0,'','','101',0);
insert into ci_auth values(102,'权限管理',0,'','','102',0);

insert into ci_auth values(103,'商品列表',100,'Goods','showlist','100-103',1);
insert into ci_auth values(104,'添加商品',100,'Goods','tianjia','100-104',1);
insert into ci_auth values(105,'商品分类',100,'Goods','category','100-105',1);

insert into ci_auth values(106,'订单列表',101,'Order','showlist','101-106',1);
insert into ci_auth values(107,'订单查询',101,'Order','look','101-107',1);
insert into ci_auth values(108,'订单打印',101,'Order','dayin','101-108',1);

insert into ci_auth values(109,'管理员列表',102,'Manager','showlist','102-109',1);
insert into ci_auth values(110,'角色管理',102,'Role','showlist','102-110',1);
insert into ci_auth values(111,'权限列表',102,'Auth','showlist','102-111',1);

②角色模拟
主管：商品管理、商品列表、添加商品、订单管理、订单列表、订单查询
经理：订单管理、订单列表、订单查询、订单打印
id 	name 	ids 	ac
insert into ci_role values(10,'主管','100,101,103,104,106,107','Goods-showlist,Goods-tianjia,Order-showlist,Order-look');
insert into ci_role values(11,'经理','101,106,107,108','Order-showlist,Order-look,Order-dayin');



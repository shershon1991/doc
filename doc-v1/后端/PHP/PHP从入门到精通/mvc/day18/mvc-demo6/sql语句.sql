#创建product数据表
create table product(
	pro_id int(11) not null primary key auto_increment,
	pro_name varchar(100) not null,
	protype_id int(11) not null,
	price decimal(10,2) not null,
	pinpai varchar(25) not null,
	chandi varchar(25) not null
);

#插入数据到product
insert into product(pro_id, pro_name, protype_id, price, pinpai, chandi) values(null, '康佳 42英寸全高清液晶电视', 1, '1999.00', '康佳', '深圳');
insert into product(pro_id, pro_name, protype_id, price, pinpai, chandi) values(null, '索尼 4G手机（黑色）', 2, '1909.00', '索尼', '深圳');
insert into product(pro_id, pro_name, protype_id, price, pinpai, chandi) values(null, '联想 14英寸笔记本电脑', 3, '5499.00', '联想', '北京');
insert into product(pro_id, pro_name, protype_id, price, pinpai, chandi) values(null, '联想 双卡双待3G手机', 2, '999.00', '联想', '北京');
insert into product(pro_id, pro_name, protype_id, price, pinpai, chandi) values(null, '惠普 黑白激光打印机', 3, '1169.00', '惠普', '天津');

#创建数据表product_type
create table product_type(
	protype_id int(11) not null primary key auto_increment,
	protypa_name varchar(50) not null
);	

#插入数据到product_type中
insert into product_type(protype_id, protypa_name) values(null, '家用电器');
insert into product_type(protype_id, protypa_name) values(null, '电子产品');
insert into product_type(protype_id, protypa_name) values(null, '办公用品');
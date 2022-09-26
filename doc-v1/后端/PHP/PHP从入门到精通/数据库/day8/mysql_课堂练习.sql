//演示Int类型的使用：
create table tab_int(f1 int, f2 tinyint, f3 bigint);

//创建表：
create table tab_int2(
	f1 int unsigned, 
	f2 tinyint zerofill, 
	f3 bigint(10) zerofill
);

//插入数据：
insert into tab_int2 (f1, f2, f3)
	values(12, 12, 12);

select * from tab_int2;


//演示小数类型的使用：
create table table_xiaoshu(
	f1 float,
	f2 double,
	f3 decimal(10, 3)/*表示总位数为10，小数位数为3*/
);

insert into table_xiaoshu (f1, f2, f3)
	values(123.456, 123.456, 123.456);

insert into table_xiaoshu (f1, f2, f3)
	values(123.456789, 123.456789, 123.456789);

insert into table_xiaoshu (f1, f2, f3)
	values(123456789, 123456789, 1234567);
	
//创建用户：
create user 'user1'@'localhost' identified by '123';

//授予权限：
grant select on php.* to 'user1'@'localhost';	
grant insert on php.* to 'user1'@'localhost';//给2次权限，其实只是“添加”权限。	

#创建一个函数：
#函数的目标：取得3个数中的最大值；
create function getMaxValue(p1 int, p2 float, p3 float)
returns float  #返回float类型
begin
    declare result float;#声明变量，没有默认值
    if(p1 >= p2 and p1 >= p3) then
    begin
        set result = p1; #赋值语句
    end;
    elseif(p2 >= p2 and p2 >= p3) then
    begin
        set result = p2; #赋值语句
    end;
    else
    begin
        set result = p3; #赋值语句
    end;
    end if;
    return result;
end;
//不过，注意：在cmd中执行该代码，需要更换“语句结束符”：
delimiter ///


#创建一个存储过程：
#存储过程的目标：将3个数据写入到表tab_int；
#并返回该表的第一个字段的前3大值的行
create procedure insert_get_Data(p1 int, p2 tinyint, p3 bigint)
begin
    insert into tab_int(f1,f2,f3)values(p1, p2, p3);
    select * from tab_int order by f1 desc limit 0, 3;
end;


#创建一个存储过程,其中使用in,out,inout：
#存储过程的目标：将3个数据写入到表tab_int；
#并返回该表的第一个字段的前3大值的行
create procedure pro1(in p1 int, out p2 tinyint, inout p3 bigint)
begin
    set p2 = p1*2; 
    set p3 = p3 + p1*3;
    insert into tab_int(f1,f2,f3)values(p1, p2, p3);
end;


#定义一个触发器：
#在表tab_int插入一行数据的时候能够同时将这个表中的第一个字段的最大值的行
#写入到另一个表中（tab_int_max1)
#其中表tab_int的结构为：
 CREATE TABLE `tab_int` (
 `f1` int(11) DEFAULT NULL,
 `f2` tinyint(4) DEFAULT NULL,
 `f3` bigint(20) DEFAULT NULL
)
#然后，其中表tab_int_max3的结构跟其一样：
#但其中永远只存tan_int中的最大值的行
 CREATE TABLE `tab_int_max1` (
 `f1` int(11) DEFAULT NULL,
 `f2` tinyint(4) DEFAULT NULL,
 `f3` bigint(20) DEFAULT NULL
)
#然后，在tab_int上写触发器：
create trigger tri1 after insert on tab_int for each row 
begin
	delete from tab_int_max1; #先删除tab_int_max中的所有数据；
	#取得tab_int中的f1字段的最大值，并存入变量@maxf1	
	select max(f1) into @maxf1 from tab_int;
	#然后根据该得到的f1字段的最大值作为条件，取出3各字段的值：
	select f2 into @v2 from tab_int where f1 = @maxf1;	
	select f3 into @v3 from tab_int where f1 = @maxf1;	

	#然后，将@maxf1,@v2,@v3插入到表tab_int_max1
	insert into tab_int_max1 (f1, f2, f3) values(@maxf1,@v2,@v3);
end;

#再建一个触发器，在表Tab_int进行Insert之前，就改行数据
#也同时插入到一个跟其类似结构的表中tab_int_some中：
 CREATE TABLE `tab_int_some` (
 `id` int(11) DEFAULT NULL,
 `age` tinyint(4) DEFAULT NULL
);
create trigger copy_data before insert on tab_int for each row
begin
	set @v1 = new.f1;#获得新行的字段f1的值；
	set @v2 = new.f2;#获得新行的字段f2的值；
	insert into tab_int_some(id,age)values(@v1,@v2);
end;



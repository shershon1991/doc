//2表查询：
1.查询“计算机系”的所有学生信息
//方法1：
select * from 学生表 where 院系ID = (
	select 院系ID from 院系 where 院系名称 = '计算机系'
);
//方法2：
select  学生表.* from 学生表 inner join 院系 on 学生表.院系ID = 院系.院系ID where 院系名称 = '计算机系';

2.查询“韩顺平”所在的院系信息。
//方法1：
select * from 院系 where 院系ID = (
	select 院系ID from 学生表 where 学生 = '韩顺平'
)
//方法2：
select  学生表.* from 学生表 inner join 院系 on 学生表.院系ID = 院系.院系ID where 学生 = '韩顺平';

3.查出在“行政楼”办公的院系名称。
select 院系名称 from 院系 where 系办地址 like '%行政楼%';

4.查出男生女生各多少人。
select 性别, count(*) as 人数 from 学生表 group by 性别;

5.查出人数最多的院系信息。
select * from 院系 where 院系ID = (
	select 院系ID from 学生表 group by 院系ID having count(*)=(
		select count(*) from 学生表 group by 院系ID
			order by count(*) desc limit 0,1
	)
);

6.查出人数最多的院系的男女各多少人。
select 性别, count(*) as 人数 from 学生表 where 院系ID=(
	select 院系ID from 学生表 group by 院系ID having count(*)=(
		select count(*) from 学生表 group by 院系ID
			order by count(*) desc limit 0,1
	)
);

7.查出跟“罗弟华”同籍贯的所有人。
select * from 学生表 where 籍贯=(
	select 籍贯 from 学生表 where 学生 = '罗弟华'
);
//如果要排除该人本身，则：
select * from 学生表 where 籍贯=(
	select 籍贯 from 学生表 where 学生 = '罗弟华'
)
and 学生 <> '罗弟华'
;

8.查出有“河北”人就读的院系信息。
select * from 院系 where 院系ID in (
	select 院系ID from 学生表 where 籍贯='河北'
);

9.查出跟“河北女生”同院系的所有学生的信息。
select * from 学生表 where 院系ID in (
	select 院系ID from 学生表 where 籍贯='河北' and 性别='女'
);
//如果要排除“河北女生”本身，则：
select * from 学生表 where 院系ID in (
	select 院系ID from 学生表 where 籍贯='河北' and 性别='女'
)
and not (籍贯='河北' and 性别='女');

/////////////////////////////////////////////////////////////////
//3表查询：
/////////////////////////////////////////////////////////////////////
//方法1：
1.查询选修了mysql的学生姓名；
select name from stu where id in(
	select stu_id from stu_kecheng where kecheng_id = (
		select id from kecheng where kecheng_name = 'mysql'
	)
);
//方法2:
select name from stu 
	inner join stu_kecheng as sk on sk.stu_id = stu.id
	inner join kecheng as kc on kc.id = sk.kecheng_id
	where kecheng_name = 'mysql';

2.查询张三同学选修了的课程名字；
//方法1：
select kecheng_name from kecheng where id in(
	select kecheng_id from stu_kecheng where stu_id = (
		select id from stu where name = '张三'
	)
);
//方法2:
select kecheng_name from stu 
	inner join stu_kecheng as sk on sk.stu_id = stu.id
	inner join kecheng as kc on kc.id = sk.kecheng_id
	where name = '张三';、

3.查询只选修了1门课程的学生学号和姓名；
select id, name from stu where id in(
	select stu_id from stu_kecheng group by stu_id having count(*) = 1
);

4.查询选修了至少3门课程的学生信息；
select * from stu where id in(
	select stu_id from stu_kecheng group by stu_id having count(*) >= 3
);

5.查询选修了所有课程的学生；
select * from stu where id in(
	select stu_id from stu_kecheng group by stu_id having count(*) = (
		select count(*) from kecheng
	)
);

6.查询选修了课程的总人数；
//第一步：以stu_id为条件进行分组，找出所有选修课程的学生id
select stu_id from stu_kecheng group by stu_id;
//第二步：以上述结果作为数据源，统计其行数，就是选修课程的学生数量。
select count(*) from (select stu_id from stu_kecheng group by stu_id) as t

7.查询所学课程至少有一门跟张三所学课程相同的学生信息；
#第4步：最后根据这些学生Id,找出他们的信息
select * from stu where id in(
	#第3步：根据这些Id,找出学了这些课程的学生id
	select stu_id from stu_kecheng where kecheng_id in(
		#第2步：找出张三所学课程的Id
		select kecheng_id from stu_kecheng where stu_id = (
			#第1步：找出张三的id		
			select id from stu where name = '张三'
		)
	)
)


8.查询两门即两门以上不及格同学的平均分
#第1步:找出所有不及格的分数信息
select * from stu_kecheng where score < 60;
#第2步：在对该所有不及格的结果数据进行分组，并取得大于等于2的组；
select stu_id from stu_kecheng as sk
	where score < 60
	group by stu_id having count(*) >= 2
#第3步：根据这些学生id，找出它们的所有成绩，并进行统计平均分
select stu_id, name, avg(score) from stu_kecheng as sk
	inner join stu on stu.id = sk.stu_id
	where stu_id in(
	select stu_id from stu_kecheng where score < 60
	group by stu_id having count(*) >= 2
)
group by stu_id, name
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class Student{
	public $name = '';  //实例属性
	static $count = 0;  //静态属性
}
$s1 = new Student();
$s1->name = '杜建';//使用普通属性们这里是复制；
Student::$count++;//使用静态属性，统计学生对象数量

$s2 = new Student();
$s2->name = '王维';//使用普通属性们这里是复制；
Student::$count++;//使用静态属性，统计学生对象数量

echo "<br />当前的学生对象总数为：" . Student::$count;

?>
</body>
</html>
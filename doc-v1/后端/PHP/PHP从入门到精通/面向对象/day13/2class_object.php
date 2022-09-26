<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//定义一个人类
class Person {
    var $name;  //特征，其实就是“变量”
    var $age;   //特征，其实就是“变量”
    var $edu;   //特征，其实就是“变量”
}
//创建一个新的Person类的对象，并“放入”变量$obj1中（其实就是赋值）
$obj1 = new Person();
$obj1->name = '张三';  //符号“->”就是表示指代对象中的某个“特征”，这里就是给该特征赋值；
$obj1->age = '18';    //“->”相当于js中的“.”。
$obj1->edu = '大学';
echo "<pre>";
var_dump($obj1);
echo "</pre>";
//又创建了一个对象：
$obj2 = new Person();
$obj2->name = '李四';
$obj2->age = '22';   
$obj2->edu = '高中';
echo "<pre>";
var_dump($obj2);
echo "</pre>";
?>
</body>
</html>
<!DOCTYPE HTML>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
$s1 = "abc";      //这是一个变量，里面存储的是字符串“abc” 
$abc = 10;        
echo $$s1;         

//以下演示“可变变量”的灵活性
//所谓的可变变量，其实就是变量的名字可以“动态变化”以获取不同的数据值
$v1 = 1;
$v2 = 22;
$v3 = 13;
$v4 = 44;
$v5 = 55;
//求这5个变量的和
//其他语言，只能“一个一个”的加起来
$sum = 0; //用于存储总和
for($i=1; $i<=5; $i++) {
	$v = "v" . $i;  //这里，结果其实是一个“字符串”，比如"v1","v2"...
	$sum += $$v;
}
echo "<br /> sum = $sum";
?>
</body>
</html>
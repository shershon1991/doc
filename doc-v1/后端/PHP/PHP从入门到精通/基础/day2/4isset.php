<!DOCTYPE HTML>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
$v1 = isset($s1);  //判断$s1是否存在，结果是false
var_dump($v1);

$s2 = 2;
$v2 = isset($s2);  //true
var_dump($v2);

$s3 = false;
$v3 = isset($s3);  //true
var_dump($v3);

$s4 = "";
$v4 = isset($s4); //true
var_dump($v4);


$s5 = null; //特别注意:null这个“值”（数据）的含义就是“没有数据”
$v5 = isset($s5);  //false
var_dump($v5);

$s6 = 0;
$v6 = isset($s6); //true
var_dump($v6);

$s7 = "0";
$v7 = isset($s7); //true
var_dump($v7);

$s8 = array();
$v8 = isset($s8); //true
var_dump($v8);
?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
const PP1 = 1;//定义普通常量1；
define("PP2",2);//定义普通常量2；
class C1{
	//定义类常量：
	const PI = 3.14;
	const G = 9.8;
}
//使用类常量：
$v1 = C1::PI *3*3;
echo "<br />v1 = $v1";

echo "<br />C1::G = " . C1::G;
?>
</body>
</html>
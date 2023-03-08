<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
$v1 = 1;
$v2 = $v1;  //值传递
$v1 = 10;
echo "<br />v1 = $v1";//10
echo "<br />v2 = $v2";//1
unset($v1);  //断开$v1跟其数据的关系
$r1 = isset($v2);
echo "<br />";var_dump($r1);//true
echo "<hr />";

$m1 = 1;
$m2 = & $m1;  //引用传值方式
$m1 = 10;
echo "<br />m1 = $m1";//10
echo "<br />m2 = $m2";//10
unset($m1);  //断开$v1跟其数据的关系
$r2 = isset($m2);
echo "<br />";var_dump($r2);//true
?>
</body>
</html>
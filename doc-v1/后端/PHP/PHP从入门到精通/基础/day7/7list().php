<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//这是一个数组：其中有整数数字下标：
$c = array(0=>0, 1=>11, 3=>33, 2=>22);
list($v1) = $c;				//将数组c的下标为0的项赋值给v1
list($s1, $s2) = $c;		//将数组c的下标为0和1的项赋值给s1,s2
list($m1, $m2, $m3) = $c;	//将数组c的下标为0和1和2的项赋值给m1,m2,m3
echo "<br />v1 = $v1";
echo "<br />s1 = $s1, s2 = $s2";
echo "<br />m1 = $m1, m2 = $m2, m3 = $m3";

$arr1 = array(
		1=>5, 
		'value'=>5,
		0=>1,
		'key'=>1
	);
list($key, $value) = $arr1;//分别取得下标为0和1的数据
echo "<hr />key = $key, value = $value";
?>
</body>
</html>
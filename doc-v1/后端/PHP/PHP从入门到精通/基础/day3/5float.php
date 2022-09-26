<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$v1 = 8.1; //浮点数
if($v1/3 == 2.7) {
	echo $v1 . "/3等于2.7";
}
else {
	echo $v1 . "/3不等于2.7";
}

echo "<hr />";
//以下为正确的浮点数比较方法：
//考虑精度要求为4位时：
if(round($v1/3 * 10000) == round(2.7 * 10000)) {
	echo $v1 . "/3等于2.7";
}
else {
	echo $v1 . "/3不等于2.7";
}

echo "<hr />";

echo "<br />php中输出8.1/3的结果为：" . (8.1/3);

echo "<hr />";
$n1 = 10000;
$s1 = $n1 * $n1; //两个整数相乘
$s2 = $n1 * $n1* $n1; //三个整数相乘
echo "<br />整数的最大值为：" . PHP_INT_MAX;
echo "<br />";var_dump($s1);
echo "<br />";var_dump($s2);
echo "<hr />";
?>
</body>
</html>
<script>
	document.write("<br />但是js中输出8.1/3的结果为：" + (8.1/3));
</script>
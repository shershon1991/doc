<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
//最基本for循环
for($i = 1; $i <= 9; ++$i) {
	echo $i;
	echo "<br />"; 
}

echo "<hr />";
//嵌套循环语句
for($i = 1; $i <= 9; ++$i) {
	//这里，可以看作是“输出一行”
	//一行输出若干个“*”
	for($k = 1; $k <= $i; ++$k) {
	echo "*";
	}
	echo "<br />";  //一行结束（换行）
}

echo "<hr />";
//嵌套循环语句小应用：99乘法表
echo "<pre>";
for($i = 1; $i <= 9; ++$i) {
	//这里，可以看作是“输出一行”
	//一行输出若干个“*”
	for($k = 1; $k <= $i; ++$k) {
	echo "$k x $i = " . ($i*$k) . "\t";
	}
	echo "<br />";  //一行结束（换行）
}
echo "</pre>";
?>
</body>
</html>
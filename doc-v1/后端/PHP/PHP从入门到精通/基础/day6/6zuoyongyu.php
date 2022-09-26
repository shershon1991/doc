<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//这里演示局部访问全局变量，出错：
$v1 = 1;
function f1() {
	echo "<br />在函数内部访问外部：v1 = $v1";
}
f1();

//这里演示全局访问局部变量，出错：
function f2() {
	$v2 = 1;
}
f2();
echo "<br />在函数外部访问内部：v2 = $v2";

echo "<hr />";
function f3() {
	static $c = 0;//静态局部变量，它的值会保留
				//而且，此行的赋初值，只会执行第一次
	$c++;
	$d = 0;//此行，每次进入函数，都会执行
	$d++;
	echo "<br />c = $c, d = $d(此函数调用次数为：$c)";
	//此行之后，函数结束，其中的$d变量就被销毁了！
}
f3();
f3();
f3();
f3();

echo "<hr />";
$v4 = 4;
function f4() {
	//在函数中，使用global来声明一个要使用的全局变量的同名局部变量。
	global $v4; //这里，$v4第局部变量，只是跟全局变量的v4同名
				//实际情况是：此时外部v4变量跟内部的v4变量，共同
				//指向一个数据区——引用关系！
	echo "<br />在局部访问全局变量v4 = $v4";
	$v4 = 44; //修改其值；
}
f4();
echo "<br />在全局变量再次访问v4 = $v4";

echo "<hr />";
$v5 = 5;//全局变量
function f5() {
	//$GLOBALS可以认为是全局变量的另一种使用形式！
	echo "<br />在局部访问全局变量v5 = " . $GLOBALS['v5'];
	$GLOBALS['v5'] = 55;//修改其值；
}
f5();
echo "<br />在全局变量再次访问v5 = " . $v5;
echo "<br />在全局变量再次访问v5 = " . $GLOBALS['v5'];


echo "<hr />";
$v6 = 6;//全局变量
function f6() {
	//$GLOBALS可以认为是全局变量的另一种使用形式！
	echo "<br />在局部访问全局变量v6 = " . $GLOBALS['v6'];
	$GLOBALS['v6'] = 66;//修改其值；
	unset($GLOBALS['v6']);
}
f6();
echo "<br />在全局变量再次访问v6 = " . $v6;


?>
</body>
</html>
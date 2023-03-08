<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function f1($x = 3, $y = 4) {
	$s = $x * $x + $y * $y;
	$result = sqrt($s);
	return $result;
}
$v1 = f1(30, 40);	//传过去2个数据分别给予x和y
$v2 = f1(30);		//传过1个数据，给予x。y自动获得默认值4
$v3 = f1();			//没有传过去值，x自动获得3，y自动获得4


function f2($a, $b = 3, $c = 'abc') {
	echo "<br />这只是演示多个形参，部分有默认值的情况";
	echo "<br />a = $a, b = $b, c = $c";
}
f2(1);
f2(1, 2);
f2(1, 2, 'xyz');
f2(); //这种做法是错误的！

//演示形参的引用传递问题
function f3($a, & $b) {
	$a = $a * $a;
	$b = $b * $b;
	return $a + $b;
}
//$v1 = f3(3, 4);//这里报“致命错误”，因为4不能当做对应引用传递的形参的对应实参
				//这里，$b这个形参对应的实参，必须是一个“变量”，如下一行调用：
$s1 = 3;
$s2 = 4;
$v2 = f3($s1, $s2);
echo "<br /><br />v2 = $v2";
echo "<br />此时: s1 = $s1, s2 = $s2";

//定义一个没有形参的函数
//但其可以接受任意个数的实参
function f4() {
	//系统函数func_get_args()可以获取函数调用时传递过来的
	//所有实参数据，并且都放入一个数组中！
	$arr = func_get_args();
	echo "<p>函数f4被调用，其实参为：";
	foreach($arr as $key => $value) {
	echo $value . " ";
	}
}
f4(1, 2, 3);
f4('aa', 'bb');
?>
</body>
</html>
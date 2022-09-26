<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//将一个匿名函数，赋值给一个变量f1
$f1 = function() {
	echo "<br />这是一个匿名函数！";
};
$f1(); //调用该匿名函数，就是用该变量
	   	//可见其形式跟调用可变函数一样！

//再演示一个带参数的匿名函数：
$f2 = function($p1, $p2) {
	$result = $p1 + $p2;
	return $result;
};
$re1 = $f2(3, 4);//将函数的返回值给$re1;
echo "<br />$re1";

function func1($x, $y, $z) {
	$s1 = $x + $y;
	$s2 = $x - $y;
	$z($s1, $s2);
}

func1(3, 4,
			function($m1, $m2) {
				$n = $m1 * $m2;
				echo "<br />两个数的和乘以两个数的差的结果为：$n";
			}
	);
	

func1(3, 4,
			function($m1, $m2) {
				echo"<br />m1 = $m1, m2 = $m2";
			}
	);

?>
</body>
</html>
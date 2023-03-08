<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//现在，假设有一个函数，该函数“能够”计算n的阶乘。
function jiecheng($n) {
	echo "<br />开始：有人要求{$n}的阶乘";
	if($n == 1) {
	echo "<br />结束：终于求到了{$n}的阶乘：:1";
	return 1;
	}
	$jieguo = $n * jiecheng($n-1);
	echo "<br />结束：终于求到了{$n}的阶乘：：$jieguo";
	return $jieguo;
}
$v2 = jiecheng(5); //结果应该是5的阶乘
/*
演示调用过程：
$v2 = jiecheng(5) ==>>
$v2 = 5 * jiecheng(4) ==>>
$v2 = 5 * (4 * jiecheng(3)) ==>>
$v2 = 5 * (4 * (3 * jiecheng(2))) ==>>
$v2 = 5 * (4 * (3 *(2 * jiecheng(1)))) ==>>
$v2 = 5 * (4 * (3 *(2 * 1))) ==>>
$v2 = 5 * (4 * (3 * 2)) ==>>
$v2 = 5 * (4 * 6) ==>>
$v2 = 5 * 24 ==>>
$v2 = 120
*/
echo "<br />v2 = $v2";
?>
</body>
</html>
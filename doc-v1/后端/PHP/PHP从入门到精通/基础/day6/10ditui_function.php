<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//演示递推思想
//目标：要求5的阶乘；
$qian = 1; //表示“前一个已知的答案”：这里是第一个，就是1的阶乘
for($i = 2; $i <= 5; ++$i) {//意图求得从2开始到5的“每一个阶乘数”
	//次循环会从2的阶乘开始，一次次求得
	//“更大”一个数的阶乘，直到5的阶乘
	$jieguo = $qian * $i;//要求得结果是由“前一个结果”经过简单乘法运算而得到
	echo "<br />{$i}的阶乘是$jieguo";
	$qian = $jieguo;//将当前求得的“结果”，又当成“前一个”，以供下一次使用！
}
echo "<br />结果为：" . $jieguo;

/*
下面用地推思想来完成刚才的数列题：
以下数列：1, 1, 2, 3, 5, 8, 13，。。。
求第20项：
*/
$qian1 = 1;
$qian2 = 1;
for($i = 3; $i <= 20; ++$i) {
	$jieguo = $qian1 + $qian2;//第3项
	$qian1 = $qian2;
	$qian2 = $jieguo;
}
echo "<br />数列的第20项为：" . $jieguo;

?>
</body>
</html>
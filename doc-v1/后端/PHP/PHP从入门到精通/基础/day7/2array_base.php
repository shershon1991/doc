<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//求一个一维数组的平均值：
$a = array(1, 11, 111, 1111);
$len = count($a); //长度
$sum = 0;  //用于存储总和
$c = 0;  //用于存储数组的个数
for($i = 0; $i < $len; ++$i) {
	$sum += $a[$i]; // 累加思想
	++$c;			//计数思想

}
echo "<br />平均值为：" . ($sum/$c);

//求一个二维数组的平均值：
$d = array(
	array(1, 11, 111),
	array(2, 22, 222, 2222),
	array(3, 33, 333, 3333, 33333),
	);
$len = count($d); //长度
$sum = 0;  //用于存储总和
$c = 0;  //用于存储数组的个数
for($i = 0; $i < $len; ++$i) {
	$temp = $d[$i]; //这是一个一维数组
	$len2 = count($temp);//该一维数组的长度
	for($k = 0; $k < $len2; ++$k) {
		$sum += $temp[$k];//累加
		++$c;			//计数
	}
}
echo "<br />平均值为：" . ($sum/$c);

//求一个一维数组的最大值，及其对应下标：
$arr3 = array(12, 1, 44, 45, 123, 77);
$max = $arr3[0];//将第一项放入$max中，
				//并试图使用该变量来存储最终的“最大值”
$pos = 0;//第一个下标，并试图使用该变量来存储最终的“最大值所在下标”
$len = count($arr3); //长度
for($i = 0; $i < $len; ++$i) {
	if($arr3[$i] > $max) {
	$max = $arr3[$i];
	$pos = $i;
	}
}
echo "<br />最大值为：$max" . "，其下标为：$pos";

echo "<hr />";
//求交换一个一维数组的最大值和最小值的位置：
//先看交换原理：
/*
$a = 3;
$b = 4;
$temp = $a;
$a = $b;
$b = $temp;
*/
//然后才进行数组最大值和最小值的交换
//其它前提是：知道最大值最小值在哪里
$arr4 = array(12, 1, 44, 45, 123, 77);
echo "<br />交换之前："; print_r($arr4);
$max = $arr4[0];//将第一项放入$max中，
				//并试图使用该变量来存储最终的“最大值”
$pos = 0;//第一个下标，并试图使用该变量来存储最终的“最大值所在下标”
$min = $arr4[0];//同理
$pos2 = 0;      //同理
$len = count($arr4); //长度
for($i = 0; $i < $len; ++$i) {
	if($arr4[$i] > $max) {
	$max = $arr4[$i];
	$pos = $i;
	}
	if($arr4[$i] < $min) {
	$min = $arr4[$i];
	$pos2 = $i;
 	}
}
echo "<br />最大值为：$max" . "，其下标为：$pos";
echo "<br />最小值为：$min" . "，其下标为：$pos2";

//然后才开始交换：
$temp = $arr4[$pos];
$arr4[$pos] = $arr4[$pos2];
$arr4[$pos2] = $temp;
echo "<br />交换之后：";print_r($arr4);
?>
</body>
</html>
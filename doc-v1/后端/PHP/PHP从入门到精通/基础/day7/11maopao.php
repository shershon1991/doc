<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$a = array(9, 3, 5, 8, 2, 7);   //下标为0,1,2,3,4,5
/*
规律描述：
1.	假设数组的数据有n个。
2.	要进行比较的“趟数”为n-1;
3.	每一趟要比较的数据个数都比前一趟少一个，第一趟要比n个（即比较n-1次）
4.	每一次比较，如果发现“左边数据”大于“右边数据”，就对这两者进行交换位置。
*/
echo "<br />排序之前："; print_r($a);
//一顿排序
$n = count($a);//个数
for($i = 0; $i < $n-1; ++$i) {//这就是n-1趟
	for($k = 0; $k < $n-$i-1; ++$k) {//该趟要比较的次数
	//这里，也可以把$k当做下标来使用
		if($a[$k] > $a[$k+1]) {
			$t = $a[$k];
			$a[$k] = $a[$k+1];
			$a[$k+1] = $t;
		}
	}	
}
echo "<br />排序之后："; print_r($a);
?>
</body>
</html>
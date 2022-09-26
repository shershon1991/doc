<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//需求，使用for循环和next()函数，遍历以下数组（输出其下标和对应值）：
$arr4 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
$len = count($arr4);	//取得数组长度
for($i = 0; $i < $len; ++$i) {	//控制循环的次数
	$key = key($arr4);		 //取得“当前项”的键
	$value = current($arr4);	//取得“当前项”的值
	echo "<br />$key => $value";
	next($arr4);	//当对“当前项”的数据处理完毕，就将指针后移一位
}
?>
</body>
</html>
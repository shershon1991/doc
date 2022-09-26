<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//使用该数组来演示each()含义和使用方法：
$arr4 = array(
	1=>3,
	'a1'=>11,
	3=>5,
);
$result1 = each($arr4); //此时取得“1=>3”这项，并结果为数组
echo "<br />result1为：<pre>"; print_r($result1);
$result2 = each($arr4); //此时取得“‘a1’=>3”这项，并结果为数组
echo "<br />result2为：<pre>"; print_r($result2);
?>
</body>
</html>
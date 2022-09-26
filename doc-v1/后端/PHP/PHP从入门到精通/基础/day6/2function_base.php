<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function f1($x, $y) {
	$s = $x * $x + $y * $y;
	$result = sqrt($s); //求其开方
	return $result;//返回该数据值
}
$v1 = f1(3,4);
echo "v1 = $v1";
echo "f1(5,6) = " . f1(5,6);
?>
</body>
</html>
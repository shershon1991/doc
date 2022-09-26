<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function shulie($n) {
	if($n == 1 || $n == 2) {
		return 1;
	}
	$jieguo = shulie($n-1) + shulie($n-2);
	return $jieguo;
}
$v = shulie(20);
echo "<br />v = $v";
?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function runnian($n) {
	if($n % 4 == 0 && $n % 100 != 0 || $n % 400 == 0) {
		//echo "{$n}是闰年";//这种写法不符合题意
		return  true;
	}
	else {
		//echo "{$n}不是闰年";//这种写法不符合题意
		return  false;
	}
}
$v = runnian(2016);
var_dump($v);

?>
</body>
</html>
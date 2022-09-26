<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
function GetBInStr($e) {
	$s = decbin($e);//这是一个二进制数字字符串
	//str_pad($str1, 长度n, $str2, 位置w)函数的作用是：
	//将字符串$str1,用字符串$str2填充到指定的长度n,
	//而且可以指定填充的位置w:左边填充还是右边填充
	$s1 = str_pad($s, 16, "0", STR_PAD_LEFT);
	return $s1;
}
echo "<pre>";
echo "<br />E_ERROR=" . E_ERROR . ",\t\t其对应二进制值为：" . GetBInStr(E_ERROR);
echo "<br />E_ERROR=" . E_WARNING . ",\t\t其对应二进制值为：" . GetBInStr(E_WARNING);
echo "<br />E_ERROR=" . E_NOTICE . ",\t\t其对应二进制值为：" . GetBInStr(E_NOTICE);
echo "<br />E_USER_NOTICE=" . E_USER_NOTICE . ",\t其对应二进制值为：" . GetBInStr(E_USER_NOTICE);
echo "<br />E_ALL=" . E_ALL . ",\t\t其对应二进制值为：" . GetBInStr(E_ALL);
echo "</p>";
?>
</body>
</html>
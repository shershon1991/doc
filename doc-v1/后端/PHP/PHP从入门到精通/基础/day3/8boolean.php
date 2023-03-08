<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$v1 = 123;
if($v1) {  //这就是一个对变量进行直接判断的语法！
	echo "<br />可见{$v1}当做“真”！";
}
else {
	echo "<br />可见{$v1}当做“假”";
}
?>
</body>
</html>
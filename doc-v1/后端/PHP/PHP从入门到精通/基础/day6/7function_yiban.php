<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
if(function_exists("f1") == false) {
	function f1() {
		echo "<br />这个函数我自己定义了！";
	}
}
f1(); //这里就可以放心使用该函数了！
?>
</body>
</html>
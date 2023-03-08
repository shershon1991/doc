<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function f1() {
	echo "<br />这就是一个普通的函数而已！";
}
$v1 = "f1";
$v1(); //这就是可变函数！
//可变函数其实就是在调用函数的时候，使用一个变量名而已。
//该变量的内部，就是该函数名！


function jpg() {echo "<br />处理jpg图片";}
function png() {echo "<br />处理png图片";}
function gif() {echo "<br />处理gif图片";}
$file = "abc.png";//代表用户上传的图片，其后缀能是png,jpg,gif等
$houzhui = strrchr("$file", ".");
	//strrchr($s1,$s2)函数用于获取字符串$s1中最后一次
	//出现的字符$s2之后的所有字符内容（含$s2本身）
//echo "<br />$houzhui";
$houzhui = substr($houzhui,1);//获得该字符串从位置1开始之后的所有字符
//echo "<br />$houzhui";
$houzhui();//可变函数！
?>
</body>
</html>
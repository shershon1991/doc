<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//我们准备自己定义错误处理器：
//第1步：设定要作为错误处理的函数名：
set_error_handler("my_error_handler");
//第2步：
//该函数需要定义4个形参，分别代表：
//$errCode:代表错误代号（级别）
//$errMsg:代表错误信息内容
//$errFile:代表发生错误的文件名
//$errLine:代表发生错误的行号
//注意：该函数我们不要在程序中调用，而是一发生错误就会被自动调用
//而且会传入该4个实参数据
function my_error_handler($errCode, $errMsg, $errFile, $errLine) {
	$str = "";
	$str .= "<p><font color='red'>大事不好，发生错误：</font>";
	$str .= "<br />错误代号为：" . $errCode;
	$str .= "<br />错误内容为：" . $errMsg;
	$str .= "<br />错误文件为：" . $errFile;
	$str .= "<br />错误行号为：" . $errLine;
	$str .= "<br />发生时间为：" . date("Y-m-d H:i:s");
	$str .= "</p>";
	echo $str; //输出该构建的错误完整处理结果
	//也可以将该内容写入到某个文件中去，也就是记录错误日志！
	//单，今天不做——这涉及到文件操作你！
}

//以下是由错误的代码：
echo "<br >aaa";
echo $v1;	//使用不存在的变量
echo C1;	//使用不存在的常量
echo "<br >bbb";
include './no_this_file.php';
echo "<br >ccc";
?>
</body>
</html>
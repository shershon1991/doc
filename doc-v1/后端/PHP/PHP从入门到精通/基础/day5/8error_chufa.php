<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
echo "<br >aaa";
echo $v1;	//使用不存在的变量
echo C1;	//使用不存在的常量
echo "<br >bbb";

include './no_this_file.php';

echo "<br >ccc";

//下面演示“自定义错误”（也就是所谓的用户错误）：
//这里所谓的用户错误，就是我们程序员作为php语言的用户
//来通过程序“主动”创建出来的错误！
echo "<br />ccc1";
$age = 880; //代表网页用户提交的年龄！
			//但我们系统要求年龄在0-127之间
if($age > 127 || $age < 0) { //异常数据处理！
	trigger_error("年龄不符合要求！", E_USER_ERROR);
}
else {
	echo "你的年龄为：$age"; //正常数据处理！
}
echo "<br />ccc2";

$s1 = no_this_function(1,2);

echo "<br >ddd";
?>
</body>
</html>
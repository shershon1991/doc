<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
ini_set("display_errors", 1); //不显示错误报告

//ini_set("error_log", "my_error.txt"); //记录到该文件
ini_set("error_log", "syslog"); //记录到系统日志中

echo "<br >aaa";
echo $v1;	//使用不存在的变量
echo C1;	//使用不存在的常量
echo "<br >bbb";
include './no_this_file.php';
echo "<br >ccc";
?>
</body>
</html>
<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
//通常，php网页中完成有关数据库的操作，首先，需要如下代码： 
$link = mysql_connect("localhost", "root", "");		//连接数据库系统
//mysql_query("set names utf8");						//设定“连接编码”;
mysql_set_charset("utf8");			
//mysql_query("use php"); 							//选定要使用的数据库	
mysql_select_db("php");
//然后，才开始正式执行要完成的数据库操作系统任务（语句）：
$num = rand(0, 255);	//随机生成0-255之间的数字
$sql = "insert into tab_int2(f1, f2, f3) values(123, $num, 123)";
$result = mysql_query($sql);
if($result === false) {
	echo "执行失败，请参考：" . mysql_error();
}
else {
	echo "执行成功！";
}
?>
</body>
</html>
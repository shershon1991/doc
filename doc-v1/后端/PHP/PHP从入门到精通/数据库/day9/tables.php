<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
if(!empty($_GET['db'])) 
{
	$db = $_GET['db'];
}
else {
	die("非法请求！");
}
$link = mysql_connect("localhost:3306", "root", "");
mysql_query("set names utf8");
mysql_query("use $db");

$sql = "show tables";
$result = mysql_query($sql);
while($rec = mysql_fetch_array($result)) {
	echo "<br />" . $rec[0];//也可以写：$rec['Database'];
	echo " <a href='table_struct.php?db=$db&tab={$rec[0]}'>查看结构</a> ";
	echo " <a href='table_data.php?db=$db&tab={$rec[0]}'>查看数据</a> ";
} 
?>
</body>
</html>
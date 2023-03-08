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
if(!empty($_GET['tab'])) 
{
	$tab = $_GET['tab'];
}
else {
	die("非法请求！");
}
$link = mysql_connect("localhost:3306", "root", "");
mysql_query("set names utf8");
mysql_query("use $db");

$sql = "desc $tab";
$result = mysql_query($sql);

while($rec = mysql_fetch_array($result)) {
	
} 
?>
</body>
</html>
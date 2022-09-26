<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$link = mysql_connect("localhost:3306", "root", "");
mysql_query("set names utf8");
//mysql_query("use ???");
$sql = "show databases;";
$result = mysql_query($sql);
while($rec = mysql_fetch_array($result)) {
	echo "<br />" . $rec[0];//也可以写：$rec['Database'];
	echo "<a href='tables.php?db={$rec[0]}'>查看表</a>";
}
?>
</body>
</html>
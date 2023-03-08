<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
$link = mysql_connect("localhost", "root", "");//连接数据库系统
mysql_query("set names utf8");	//设定“连接编码”	
mysql_query("use php"); 	//选定要使用的数据库
$sql1 = "desc tab_int2;";
$result = mysql_query($sql1);
if($result === false) {
	echo "执行失败，请参考：" . mysql_error();
}
else {
	//此时，$result就是“结果集”（数据集）；
	echo "执行成功！数据如下：";
	//echo $result;//结果集是一种资源，不能直接输出
	echo "<table border='1'>";

		echo "<tr>";
		echo "<td>Field</td>";
		echo "<td>Type</td>";
		echo "<td>Null</td>";
		echo "<td>Key</td>";
		echo "<td>Default</td>";
		echo "<td>Extra</td>";
		echo "</tr>";

	while($rec = mysql_fetch_array($result)) {
		echo "<tr>";
		echo "<td>" . $rec['Field'] . "</td>";
		echo "<td>" . $rec['Type'] . "</td>";
		echo "<td>" . $rec['Null'] . "</td>";
		echo "<td>" . $rec['Key'] . "</td>";
		echo "<td>" . $rec['Default'] . "</td>";
		echo "<td>" . $rec['Extra'] . "</td>";
		echo "</tr>";
	}
	echo "</table>";
}
?>
</body>
</html>
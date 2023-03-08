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

$sql1 = "select * from tab_temp1";
$sql1 = "desc tab_temp1";
$sql1 = "desc tab_int2";
$sql1 = "select * from tab_int2";
$sql1 = "show tables";

$result = mysql_query($sql1);
if($result === false) {
	echo "执行失败，请参考：" . mysql_error();
}
else {
	echo "执行成功！数据如下：";
	echo "<table border='1'>";
 	$field_count = mysql_num_fields($result);//获得列数
 	echo "<tr>";
 	for($i = 0; $i < $field_count; ++$i) {
 		$field_name = mysql_field_name($result, $i);
 		echo "<td>" . $field_name . "</td>";
 	}		
	//echo "<td>Type</td>";
	//echo "<td>Null</td>";
	//echo "<td>Key</td>";
	//echo "<td>Default</td>";
	//echo "<td>Extra</td>";
	echo "</tr>";
	
	while($rec = mysql_fetch_array($result)) {
	//*
		echo "<tr>";
		//对这个结果集继续进行“列遍历”
		for($i = 0; $i < $field_count; ++$i) {
			$field_name = mysql_field_name($result, $i);//获得第i列的名字
			echo "<td>" . $rec[$field_name] . "</td>";
		}	
		//echo "<td>" . $rec['Type'] . "</td>";
		//echo "<td>" . $rec['Null'] . "</td>";
		//echo "<td>" . $rec['Key'] . "</td>";
		//echo "<td>" . $rec['Default'] . "</td>";
		//echo "<td>" . $rec['Extra'] . "</td>";
		echo "</tr>";
	//*/
	}
	echo "</table>";
}
?>
</body>
</html>
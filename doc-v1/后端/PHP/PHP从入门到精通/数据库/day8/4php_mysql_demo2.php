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
$sql1 = "select * from tab_temp1;";
$result = mysql_query($sql1);
if($result === false) {
	echo "执行失败，请参考：" . mysql_error();
}
else {
	//此时，$result就是“结果集”（数据集）；
	echo "执行成功！数据如下：";
	//echo $result;//结果集是一种资源，不能直接输出
	while($rec = mysql_fetch_array($result)) {
		echo "<br />id:" . $rec['id'];
		echo "------name:" . $rec['name'];
		echo "------age:" . $rec['age'];
	}
}
?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php

$link = mysql_connect('localhost', 'root', '');
mysql_query("set names utf8");
mysql_query("use php");

$sql = "start transaction";
mysql_query($sql);

$sql1 = "insert into tab_int(f1,f2,f3)values(15,25,35);";
$result1 = mysql_query($sql1);//执行第一条insert语句，并得到结果；
$sql2 = "insert into tab_int(f1,f2,f3)values(166,266,366);";
$result2 = mysql_query($sql2);//执行第二条insert语句，并得到结果；
//当然，我们知道这一条语句会出错
//因为f2是tinyint类型

if($result1 && $result2) {
	mysql_query("commit;");
	echo "事务执行成功！所有任务都已完成";
}
else {
	mysql_query("rollback;");
	echo "事务执行失败！数据没有修改";
}

?>
</body>
</html>
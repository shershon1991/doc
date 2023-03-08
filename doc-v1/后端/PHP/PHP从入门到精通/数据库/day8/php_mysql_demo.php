
<?php
header("content-type:text/html;charset=utf-8");
#连接数据库
mysql_connect('localhost', 'root', '');
#设置字符集编码
mysql_set_charset("utf8");
#选择数据库
mysql_select_db("php");
#拼凑sql语句
$num = rand(1, 100);
$sql = "insertttt into tab_int2(f1, f2, f3) values(12, $num, 132);";
#执行sql语句
$result = mysql_query($sql);
if($result === false){
	echo "执行失败，请参考：" . mysql_error();
}
else{
	echo "执行成功！";
}
?>

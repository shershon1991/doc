<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
require './MySQLDB.class.php';

$config = array(
	'host' => "localhost",
	'port' => 3306,
	'user' => "root",
	'pass' => "",
	'charset' => "utf8",
	'dbname' => "php"
);

$db1 = new MySQLDB($config);

//测试是否连接成功：
$result = mysql_query("select * from tab_int");
var_dump($result);

$v1 = rand(0,100);	//获取0到100之间的随机数
$sql = "insert into tab_int(f1, f2, f3)values($v1,12,13)";
$db1->exec($sql);
echo "执行插入语句成功！<br />";

$sql = "select * from user_list where user_id = 5";
$user = $db1->GetOneRow($sql);	//这里返回的就是一个数组
echo "<br />用户ID为：" . $user['user_id'];
echo "<br />用户名：" . $user['user_name'];
echo "<br />年龄：" . $user['age'];
echo "<br />学历：" . $user['edu'];
echo "<br />兴趣：" . $user['xingqu'];

?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
require_once './MySQLDB.class.php';

$config = array(
	'host' => "localhost",
	'port' => 3306,
	'user' => "root",
	'pass' => "",
	'charset' => "utf8",
	'dbname' => "php"
);
$db1 = MySQLDB::GetInstance($config);
var_dump($db1);
$db2 = clone $db1;	//私有化__clone()之后,此行出错，
				//这样就实现了“禁止克隆”的效果
				//因此，继续保证了单例的目标
echo "<br />";
var_dump($db2);
?>
</body>
</html>
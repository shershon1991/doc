<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//require_once './MySQLDB.class.php';
function __autoload($name){
    require_once './' . $name . "class.php";
}

$config = array(
    'host' => "localhost",
    'port' => 3306,
    'user' => "root",
    'pass' => "",
    'charset' => "utf8",
    'dbname' => "php"
);

$db1 = MySQLDB::GetInstance($config);
var_dunmp($db1);
?>
</body>
</html>
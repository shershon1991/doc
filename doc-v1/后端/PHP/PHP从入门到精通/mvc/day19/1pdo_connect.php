<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$dsn = "mysql:host=localhost; port=3306; dbname=php";
$opt = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'set names utf8');
$pdo = new PDO($dsn, 'root', '', $opt);
var_dump($pdo);
?>
</body>
</html>
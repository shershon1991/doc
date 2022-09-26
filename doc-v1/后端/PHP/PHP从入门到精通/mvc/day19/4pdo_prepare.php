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

$sql = "select user_id, user_name, age, edu from user_list where user_id= ? and user_name = ? ";
$stmt = $pdo->prepare($sql);
$stmt->bindValue(1, 28);
$stmt->bindValue(2, 'user5');
$stmt->execute();
$arr = $stmt->fetch(PDO::FETCH_ASSOC);
PRINT_R($arr);

echo "<hr />";
$sql = "select user_id, user_name, age, edu from user_list where user_id= :v1 and user_name = :v2";
$stmt = $pdo->prepare($sql);
$stmt->bindValue(":v1", 28);
$stmt->bindValue(":v2", 'user5');
$stmt->execute();
$arr = $stmt->fetch(PDO::FETCH_ASSOC);
PRINT_R($arr);
?>
</body>
</html>
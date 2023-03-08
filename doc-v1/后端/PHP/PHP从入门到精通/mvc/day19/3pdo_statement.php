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
$sql = "select * from tab_int limit 0, 3";
$stmt = $pdo->query($sql);	//得到PDO的结果集
$arr1 = $stmt->fetch(PDO::FETCH_ASSOC);	//返回关联数组
$arr2 = $stmt->fetch(PDO::FETCH_NUM);	//返回索引数组
$arr3 = $stmt->fetch();	//相当于fetch(PDO::FETCH_BOTH);
echo "<br />"; print_r($arr1);
echo "<br />"; print_r($arr2);
echo "<br />"; print_r($arr3);
?>
</body>
</html>
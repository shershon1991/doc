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

$sql = "updateeee * tab_int set f1 = 1;";	//这个sql语句是错的
$result = $pdo->exec($sql);
if($result === false){
	echo "<p>发生错误";
	echo "<br />错误代号：" . $pdo->errorcode();
	$e = $pdo->errorinfo();
	echo "<br />错误信息：" . $e[2];
}

//下面让pdo“进入”异常模式，以处理错误信息
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
try{
	$sql = "delettttt * from user_list";
	$result = $pdo->query($sql);
	echo "执行成功";
}
catch(Exception $e){
	echo "<p>发生错误：";
	echo "<br />错误代号：" . $e->GetCode();
	echo "<br />错误信息：" . $e->GetMessage();
}
?>
</body>
</html>
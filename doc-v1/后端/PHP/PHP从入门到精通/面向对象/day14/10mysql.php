<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
/*
设计目标：
1.	该类一实例化就可以自动连接上mysql数据库；
2.	该类可以单独去设定要使用的连接编码（set  names   XXX）
3.	该类可以单独去设定要使用的数据库（use  XXX）;
4.	可以主动关闭连接；
*/
class MySQLDB{
	public $link = null;
	function __construct($host, $port, $user, $pass, $charset, $dbname){
		$this->link = @mysql_connect("$host:$port", "$user", "$pass") or die("连接失败");
	Mysql_query("set names $charset");
	Mysql_query("use $dbname");
	}

	//可以设定要使用的连接编码
	function setCharset($charset){
		Mysql_query("set names $charset");
	}

	//可以设定要使用的数据库
	function selectDB($dbname){
		Mysql_query("use $dbname");
	}

	//可以关闭连接
	function closeDB(){
		mysql_close($this->link);
	}
}

$host = "localhost";
$port = 3306;
$user = "root";
$pass = "";
$charset = "utf8";
$dbname = "php";

$db1 = new MySQLDB($host, $port, $user, $pass, $charset, $dbname);

//测试是否连接成功：
$result = mysql_query("select * from tab_int");
var_dump($result);

//测试修改编码：
$db1->setCharset("gbk");
$result2 = mysql_query("select * from user_list");
$rec = mysql_fetch_array($result2);
echo "<hr />";
echo $rec["user_name"];

//测试连接关闭：
//$db1->closeDB();
$result = @mysql_query("select * from tab_int");
var_dump($result);

?>
</body>
</html>
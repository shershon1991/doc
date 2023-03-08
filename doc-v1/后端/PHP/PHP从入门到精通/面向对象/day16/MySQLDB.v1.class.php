<?php
/*
设计目标：
1.	该类一实例化就可以自动连接上mysql数据库；
2.	该类可以单独去设定要使用的连接编码（set  names   XXX）
3.	该类可以单独去设定要使用的数据库（use  XXX）;
4.	可以主动关闭连接；
*/

class MySQLDB{
	private $link = null;	//用于存储连接成功后的“资源”

	//定义一些属性，以存储连接数据库的6项基本信息
	private $host;
	private $port;
	private $user;
	private $pass;
	private $charset;
	private $dbname;
	function __construct($config){
		//先将这些基本的连接信息保存起来！
		$this->host = !empty($config['host']) ? $config['host'] : "localhost";	//考虑空值情况,使用默认值代替
		$this->port = !empty($config['port']) ? $config['port'] : "3306";
		$this->user = !empty($config['user']) ? $config['user'] : "root";
		$this->pass = !empty($config['pass']) ? $config['pass'] : "";
		$this->charset = !empty($config['charset']) ? $config['charset'] : "utf8";
		$this->dbname = !empty($config['dbname']) ? $config['dbname'] : "php";

		//连接数据库
		$this->link = @mysql_connect("{$this->host}:{$this->port}", "{$this->user}", "{$this->pass}") or die("连接失败");

		//设定编码
		//Mysql_query("set names {$config['charset']}");
		$this->setCharset($this->charset);//这一行代替上一行

		//选定要使用的数据库名
		//Mysql_query("use {$config['dbname']}");
		$this->selectDB($this->dbname);//这一行代替上一行
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

	//这个方法为了执行一条增删改语句，可以返回真假结果
	function exec($sql){
		$result = mysql_query($sql);
		if($result === false){
			//语句执行失败，则需要处理这种失败情况：
			echo "<p>sql语句执行失败，请参考如下信息：";
			echo "<br />错误代号:" . mysql_errno();//获取错误代号
			echo "<br />错误信息:" . mysql_error();//获取错误提示信息
			echo "<br />错误语句：" . $sql;
			die();
		}
		return true;
	}

	//这个方法为了执行一条返回一行数据的语句，可以返回一维数组
	//数组的下标，就是sql语句中的取出的字段名：
	function GetOneRow($sql){
		$result = mysql_query($sql);
		if($result === false){
			//语句执行失败，则需要处理这种失败情况：
			echo "<p>sql语句执行失败，请参考如下信息：";
			echo "<br />错误代号:" . mysql_errno();//获取错误代号
			echo "<br />错误信息:" . mysql_error();//获取错误提示信息
			echo "<br />错误语句：" . $sql;
			die();
		}
		//如果没有出错，则开始处理，以返回数组.此时$result是一个结果集
		$rec = mysql_fetch_assoc($result);	//去除第一行数据（其实应该只有这一行）
		return $rec;
	}

	//这个方法为了执行一条多行增删改语句，可以返回二维数组
	function GetRows($sql){
		$result = mysql_query($sql);
		if($result === false){
			//语句执行失败，则需要处理这种失败情况：
			echo "<p>sql语句执行失败，请参考如下信息：";
			echo "<br />错误代号:" . mysql_errno();//获取错误代号
			echo "<br />错误信息:" . mysql_error();//获取错误提示信息
			echo "<br />错误语句：" . $sql;
			die();
		}
		//如果没有出错，则开始处理，以返回数组.此时$result是一个结果集（且是多行数据）
		$arr = array();//空数组，用于存放要返回的结果数组（二维）
		while ($rec = mysql_fetch_assoc($result)){
			$arr[] = $rec;//此时$arr就是二维数组了！
		}	
		return $arr;
	}

	//这个方法为了执行一条返回一个数据的语句，可以返回一个直接值
	//这条语句类似这样：select count(*) asc from user_list
	function GetOneData($sql){

		$result = mysql_query($sql);
		if($result === false){
			//语句执行失败，则需要处理这种失败情况：
			echo "<p>sql语句执行失败，请参考如下信息：";
			echo "<br />错误代号:" . mysql_errno();//获取错误代号
			echo "<br />错误信息:" . mysql_error();//获取错误提示信息
			echo "<br />错误语句：" . $sql;
			die();
		}
		//如果没有出错，则开始处理，以返回一个数据
		$rec = mysql_fetch_row($result);//这里必须使用fetch_row这个函数！
			//这里得到的$rec仍然是一个数组，但其类似这样：
			//array (0=>5);或者array(0=>'user1');
		$data = $rec[0];
		return $data;
	}

}
?>
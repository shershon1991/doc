<?php
require './MySQLDB.class.php';

class BaseModel{
	//这个用于存储数据库工具类的实例（对象）
	protected $_dao = null;
	function __construct(){
		$config = array(
			'host' => "localhost",
			'port' => 3306,
			'user' => "root",
			'pass' => "",
			'charset' => "utf8",
			'dbname' => "php"
		);
		$this->_dao = MySQLDB::GetInstance($config);
	}
}
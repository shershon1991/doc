<?php
require './MySQLDB.class.php';
class BaseModel{
	protected $_dao = null;
	function __construct(){
		$config = array(
			'host' => "localhost",
			'port' => "3306",
			'user' => "root",
			'pass' => "",
			'charset' => "utf8",
			'dbname' => "php"
			);
		$this->_dao = MySQLDB::GetInstance($config);
	}
}
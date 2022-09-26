<?php
require './BaseModel.class.php';

class UserModel extends BaseModel{
	function GetAllUser(){
		$sql = "select * from user_list;";
		//$db = MySQLDB::GetInstance($config);
		$data = $this->_dao->GetRows($sql);
		return $data;
	}

	function GetCount(){
		$sql = "select count(*) as c from user_list;";
		//$db = MySQLDB::GetInstance($config);
		$data = $this->_dao->GetOneData($sql);
		return $data;
	}
}
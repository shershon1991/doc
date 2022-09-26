<?php
require './UserModel.class.php';
require './ModelFactory.class.php';
header("content-type:text/html;charset=utf-8");

//实例化模型类，并从中获取2份数据
if(!empty($_GET['act']) && $_GET['act'] == 'del'){
	$id = $_GET['id'];
	$obj = ModelFactory::M('UserModel');
	$result = $obj->delUserById($id);
	echo "<font color='red'>删除成功</font>";
}

//$user_obj = new UserModel();
$user_obj = ModelFactory::M('UserModel');
$data1 = $user_obj->GetAllUser();
$data2 = $user_obj->GetUserCount();		


//载入视图文件以显示该2份数据
include './ShowAllUser.html';
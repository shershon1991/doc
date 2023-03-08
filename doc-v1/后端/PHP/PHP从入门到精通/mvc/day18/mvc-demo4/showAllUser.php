<?php
header("content-type:text/html; charset=utf8");//设置输出的编码为utf8
require './UserModel.class.php';
require './ModelFactory.class.php';

//实例化模型类并从中获取2份数据：
if(!empty($_GET['act']) && $_GET['act'] == 'detail'){
	//获取一个用户的信息
	$id = $_GET['id'];
	$obj = ModelFactory::M('UserModel');
	$data = $obj->GetUserInfoById($id);

	//显示到“一个用户的视图”中
	include './userInfo.html';
}
else if(!empty($_GET['act']) && $_GET['act'] == 'del'){
	$id = $_GET['id'];
	$obj = ModelFactory::M('UserModel');
	$obj->delUserById($id);
	echo "<font color=red>删除成功！</font>";
	echo "<a href='?'>返回</a>";
}
else if(!empty($_GET['act']) && $_GET['act'] == 'ShowForm'){
	include './form_view.html';
}
else if(!empty($_GET['act']) && $_GET['act'] == 'AddUser'){
	//接收表单数据：
	$user_name = $_POST['username'];
	$user_pass = $_POST['password'];
	$age = $_POST['age'];
	$edu = $_POST['xueli'];
	$aihao = $_POST['aihao'];	//这是数组，需要额外处理
	$xingqu = implode(",", $aihao);//将数组的所有项，用英文的逗号连接“,”起来
	$from = $_POST['from'];

	$obj = ModelFactory::M('UserModel');
	$result = $obj->InsertUser($user_name, $user_pass, $age, $edu, $xingqu, $from);
	echo "<font color=red>添加用户成功！</font>";
	echo "<a href='?'>返回</a>";
}
else{
//$obj_user = new UserModel();	//这一行使用下一行代替
$obj_user = ModelFactory::M('UserModel');
$data1 = $obj_user->GetAllUser();	//是一个二维数组
$data2 = $obj_user->GetUserCount();	//是一个数字


//载入视图文件以显示该2份数据：
include './showAllUser_view.html';
}
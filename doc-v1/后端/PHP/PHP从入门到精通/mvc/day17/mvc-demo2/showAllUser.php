<?php
require './UserModel.class.php';

//实例化模型类并从中获取2份数据：
$obj_user = new UserModel();
$data1 = $obj_user->GetAllUser();	//是一个二维数组
$data2 = $obj_user->GetUserCount();	//是一个数字

//载入视图文件以显示该2份数据：
include './showAllUser_view.html';
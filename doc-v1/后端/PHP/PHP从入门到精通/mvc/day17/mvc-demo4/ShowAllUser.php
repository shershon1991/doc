<?php
require './UserModel.class.php';
header("content-type:text/html;charset=utf-8");

//实例化模型类，并从中获取2份数据
 $user_obj = new UserModel();
 $data1 = $user_obj->GetAllUser();
 $data2 = $user_obj->GetUserCount();

 //载入视图文件以显示该2份数据
 include './ShowAllUser.html';
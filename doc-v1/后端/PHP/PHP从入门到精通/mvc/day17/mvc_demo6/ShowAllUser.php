<?php
require './UserModel.class.php';
header("content-type:text/html;charset=utf-8");

$user_obj = new UserModel();
$data1 = $user_obj->GetAllUser();
$data2 = $user_obj->GetCount();

include './ShowAllUser.html';
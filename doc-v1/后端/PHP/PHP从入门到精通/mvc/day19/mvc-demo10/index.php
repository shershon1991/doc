<?php

$c = !empty($_GET['c']) ? $_GET['c'] : "user";	//它也可能是“user”, “product”或其他。。。
			//这里把“user”当做默认要使用的控制器

require './Framework/MySQLDB.class.php';
require './Framework/BaseModel.class.php';
require "./Framework/ModelFactory.class.php";//这个都一样，不用动
require "./Framework/BaseController.class.php"; //这个都一样，不用动
require  "./Models/" . $c . "Model.class.php";

//代表某个控制器，没个控制器是一个独立文件,但并不写在这里
//而是由下一行根据$c的值来决定载入哪一个控制器文件：
//class  XXXController  extends  BaseController{……}	

//这里才是需要载入的“当前控制器类”
require  "./Controllers/" . $c . "Controller.class.php";	

$controller_name = $c . "Controller";	//构建控制器的类名
$ctrl = new $controller_name ();	//可变类

$act = !empty($_GET['a']) ? $_GET['a'] : "Index";
$action = $act . "Action";	
$ctrl->$action();

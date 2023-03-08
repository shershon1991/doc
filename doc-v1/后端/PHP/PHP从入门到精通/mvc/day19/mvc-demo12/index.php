<?php

$p = !empty($_GET['p']) ? $_GET['p'] : "front";//确定使用哪个平台。
define("PLAT", $p);	//

define("DS", DIRECTORY_SEPARATOR);//DIRECTORY_SEPARATOR表示“目录分隔符”，
					//只有2个：'./'(unix系统),'.\'(window系统)
define("ROOT", __DIR__ . DS);	//当前MVC框架的根目录
//echo ROOT;
define("APP", ROOT . 'Application' . DS);	//application的完整路径
define("FRAMEWORK", ROOT . 'Framework' . DS);	//框架基础类所在路径
//echo FRAMEWORK;
define("PLAT_PATH", APP . PLAT . DS);	//当前平台所在目录
define("CTRL_PATH", PLAT_PATH . "Controllers" . DS);	//当前控制器所在目录
define("MODEL_PATH", PLAT_PATH . "Models" . DS);	//当前模型所在目录
define("VIEW_PATH", PLAT_PATH . "Views" . DS);	//当前视图所在目录

$c = !empty($_GET['c']) ? $_GET['c'] : "user";	//它也可能是“user”, “product”或其他。。。
			//这里把“user”当做默认要使用的控制器

require './Framework/MySQLDB.class.php';
require FRAMEWORK . 'BaseModel.class.php';
require FRAMEWORK . "ModelFactory.class.php";//这个都一样，不用动
require FRAMEWORK . "BaseController.class.php"; //这个都一样，不用动

require  MODEL_PATH . $c . "Model.class.php";


//这里才是需要载入的“当前控制器类”
require  CTRL_PATH . $c . "Controller.class.php";	

$controller_name = $c . "Controller";	//构建控制器的类名
$ctrl = new $controller_name ();	//可变类

$a = !empty($_GET['a']) ? $_GET['a'] : "Index";
$action = $a . "Action";	
$ctrl->$action();

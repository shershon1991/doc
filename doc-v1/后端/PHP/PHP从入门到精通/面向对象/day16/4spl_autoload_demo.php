<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//这里演示自定义的自动加载函数的使用：
spl_autoload_register("autoload1"); //声明“autoload1”作为自动家在函数；
spl_autoload_register("autoload2"); //声明“autoload2”作为自动家在函数；

function autoload1($class_name){//这个自动加载函数，用于加载class目录中的类文件
    echo "<br />准备在 autoload1 加载这个类：$class_name";
    $file = './class/' . $class_name . ".class.php";
    if(file_exists($file)){ //如果该文件存在
        include_once $file;
    }
    //如果不存在，则本函数就没有成功加载该类文件，就会继续找后续家在函数！
}
function autoload2($class_name){//这个自动加载函数，用于加载lib目录中的类文件
    echo "<br />准备 autoload2 加载这个类：$class_name";
    $file = './lib/' . $class_name . ".class.php";
    if(file_exists($file)){    //如果该文件存在
        include_once $file;
    }
    //如果不存在，则本函数就没有成功加载该类文件，就会继续找后续家在函数
}

$a1 = new A();  //这个类在class目录下;
echo "<br />";
var_dump($a1);
$b1 = new B();  //这个类在lib目录下;
echo "<br />";
var_dump($b1);
?>
</body>
</html>
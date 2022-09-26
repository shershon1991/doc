<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class C1{
    public $p1 = 1;//实例属性
    static $p2 = 2;//静态属性
    function showInfo1(){//实例方法
        echo "<br />实例方法被调用！";
        //$this代表一个对象，就是调用当前这个
        //方法的对象
        //实例方法中也可以使用“静态属性”
        echo "<br />p2的值为：" . self::$p2;
    }
    static function showInfo2(){//静态方法
        echo "<br />静态方法被调用！";
        //echo "<br />p1的值为：" . $this->p1;这一行出错！
        //因为，这里$this代表当前调用此方法的“对象”
        //但，当前调用这个方法shoeinfo2的是类C1
        //可见，静态方法中通常不能使用实例属性
        echo "<br />p2的值为：" . self::$p2;
        //self代表一个类，就是这个词本身所在的
        //这个类，这里是C1
    }
}
$o1 = new C1();
$o1->showInfo1();//使用对象调用实例方法
C1::showInfo2();//使用类来调用静态方法
?>
</body>
</html>
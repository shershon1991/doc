<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//修饰符
class A{
    public $p1 = 1;
    protected $p2 = 2;
    private $p3 = 3;
    function showInfo(){
        echo "<br />this->p1=" . $this->p1;
        echo "<br />this->p2=" . $this->p2;
        echo "<br />this->p3=" . $this->p3;
    }
}
$a1 = new A();
$a1->showInfo();
echo "<hr />";
echo "<br />a1->p1=" . $a1->p1;
//echo "<br />a1->p2=" . $a1->p2;//出错,因为这里是外部，又是pritected修饰
//echo "<br />a1->p3=" . $a1->p3;//出错，因为这里是外部，又是private修饰

class B extends A{
    function ShowParentInfo(){
        echo "<br />this->p1=" . $this->p1;//ok!这里是父类的public修饰，位置为子类内部
        echo "<br />this->p2=" . $this->p2;//ok！这里是父类的protected修饰，位置为子类内部
        //echo "<br />this->p3=" . $this->p3;//出错！因为这里是继承类内部，又是私有的
    }
}
$b1 = new B();
$b1->ShowParentInfo();
?>
</body>
</html>
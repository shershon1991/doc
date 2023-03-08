<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class A{
    public $p1 = "这是A中属性";
    function f1(){
        echo "<br />这是A中方法f1";
    }
}
class B extends A{
    public $p2 = "<br />这是B中属性";
}
$b1 = new B();
echo "<br />" . $b1->p2;
$b1->f1(); 

?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class A{
    public $p1 = 1;
    protected $p2 = 2;
    private $p3 = 3;
    static $p4 = 4;//静态属性
    function showAllProperties(){
	
 		foreach($this as $key=>$value){
    	    echo "<br />属性$key: $value";
    	}
    }
}
$obj1 = new A();
foreach($obj1 as $key=>$value){
    echo "<br />属性$key: $value";
}

echo "<hr />";
//那，怎么能够将一个对象的所有属性都遍历出来呢？
$obj1->showAllProperties();
?>
</body>
</html>
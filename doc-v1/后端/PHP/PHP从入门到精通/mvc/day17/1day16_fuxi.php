<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class A{
    public $p1 = 1;
    function __clone(){
		echo "正在克隆对象的p1为：" . $this->p1;
	}
}
$a1 = new A();
$a1->p1 = 11;
$aa1 = clone $a1;

$a2 = new A();
$a2->p2 = 22;
$aa2 = clone $a2;
?>
</body>
</html>
<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class C1 {
	var $p1 = 1;
}
$v1 = 1;
$v2 = $v1;//值传递
$v1++;
echo "<br />v1 = $v1, v2 = $v2";

$o1 = new C1();
$o2 = $o1;//值传递
$o1->p1 = 2;
echo "<br />o1->p1 = {$o1->p1}, o2->p1 = {$o2->p1}";

$o3 = new C1();
$o4 = & $o3;//引用传递
$o3->p1 = 2;
echo "<br />o3->p1 = {$o3->p1}, o4->p1 = {$o4->p1}";
?>
</body>
</html>
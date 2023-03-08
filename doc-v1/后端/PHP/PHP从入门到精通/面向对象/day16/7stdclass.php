<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$obj1 = new stdclass();
var_dump($obj1);
class A{}
$obj2 = new A();
echo "<br />";
var_dump($obj2);
?>
</body>
</html>
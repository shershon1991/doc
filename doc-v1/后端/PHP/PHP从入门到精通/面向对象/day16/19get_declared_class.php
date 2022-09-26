<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class A{}
class B{}
$v1 = get_declared_classes();
echo "<pre>";
var_dump($v1);
echo "</pre>";
?>
</body>
</html>
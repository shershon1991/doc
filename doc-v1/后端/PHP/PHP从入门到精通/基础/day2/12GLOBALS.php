<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
$v1 = 1;
echo "<pre>";
print_r($GLOBALS);
echo "</pre>";
echo "<hr />";

$v2 = 2;
echo "<pre>";
print_r($GLOBALS);
echo "</pre>";
?>
</body>
</html>
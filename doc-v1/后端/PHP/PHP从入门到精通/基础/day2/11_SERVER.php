<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
echo "<pre>";
print_r($_SERVER);
echo "</pre>";

echo "<table border='1'>";
foreach($_SERVER as $key => $value){
	echo "<tr>";
	echo "<td>$key</td>";
	echo "<td>$value</td>";
	echo "</tr>";
}
echo "</table>";
?>
</body>
</html>
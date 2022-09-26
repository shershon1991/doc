<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//演示sort()排序
$arr1 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
echo "<br />排序前："; print_r($arr1);
sort($arr1);
echo "<br />排序后："; print_r($arr1);

//演示asort()排序
$arr2 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
echo "<br />排序前："; print_r($arr2);
asort($arr2);
echo "<br />排序后："; print_r($arr2);
?>
</body>
</html>
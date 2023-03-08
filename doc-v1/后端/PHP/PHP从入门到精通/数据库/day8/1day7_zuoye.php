<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
//求一个整数数组中的最小奇数，如果没有奇数，则直接输出“没有奇数”，否则就输出该数
$a = array(112, 132, 12, 8, 92, 332);
$jishu_arr = array();
foreach($a as $key => $value) {
    if($value % 2 == 1) {
	$jishu_arr[] = $value;
    }
}

if(count($jishu_arr) == 0){
    echo "没有奇数";
    }
else {
	$min = $jishu_arr[0];
    foreach($jishu_arr as $v) {
	
	if($v < $min) {
	    $min = $v;
        }
    }
    echo "最小奇数为：$min";
}
?>
</body>
</html>
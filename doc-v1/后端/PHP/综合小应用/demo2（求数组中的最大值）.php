<html>
<head>
<title></title>
<?php
//求数组的最大值
$num = array(10,20,33,46,25,11);
$max = $num[0];  //假设第1个值（下表为0）是最大的
//循环比较，如果数组中有一个值比最大值要大，就把这个值赋给最大值
for($i=1,$n=count($num);$i<$n;$i++){
    if($num[$i] > $max){
    	$max = $num[$i];
    }
}
echo "最大值为" . $ max;
?>

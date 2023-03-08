<?php
//求数组的和
//假设起始总和为0，循环数组元素，依次相加
$num = array(1,2,3,4,5);
$sum = 0;
for($i=0,$n=count($num);$i<$n;$i++){
    $sum += $num[$i];
}
echo '数组的和为' . $sum . '<br />';

//foreach循环
$sum =0;
foreach($num as $v){
    $sum += $v;
}
echo '数组的和为' . $sum;
?>
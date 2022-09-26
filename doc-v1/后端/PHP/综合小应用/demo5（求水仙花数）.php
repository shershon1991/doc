<?php
/*
 * 水仙花是指一个n位数（n>=3），它的每个位上的数字的n次幂之和等于它本身
 */ 
//第一种方法
for($i=100;$i<=999;++$i){
    $a=floor($i/100);   
    $b=floor($i%100/10); 
    $c=$i%10;		
    if(pow($a,3)+pow($b,3)+pow($c,3)==$i){
	   echo $i,'<br />';
    }
}
echo '<br /><br />------------------------<br /><br />';
//第二种方法
for($i=100;$i<=999;++$i){
    $a=substr($i,0,1);
    $b=substr($i,1,1);
    $c=substr($i,2,1);
    if(pow($a,3)+pow($b,3)+pow($c,3)==$i){
	   echo $i,'<br />';
    }
}
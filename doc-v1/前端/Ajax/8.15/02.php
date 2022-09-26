<?php
//解析、反编码json信息
$city = array('hubei'=>'wuhan', 'beijing'=>'haidian', 'chongqing'=>'huilongguan');
$jn_city = json_encode($city);

//反编码
//$fan_city = json_decode($jn_city);
//var_dump($fan_city);//object(stdClass)[1]public 'hubei' => string 'wuhan' (length=5) public 'beijing' => string 'haidian' (length=7) public 'chongqing' => string 'huilongguan' (length=11)
$fan_city1 = json_decode($jn_city, true);
var_dump($fan_city1);//array (size=3)'hubei' => string 'wuhan' (length=5)'beijing' => string 'haidian' (length=7)'chongqing' => string 'huilongguan' (length=11)


<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<title></title>
</head>
<body>
<form action="#" method="post">
	请输入一个数值：<input type="text" name="num" />
	<input type="submit" value="计算阶乘" />
</form>
</body>
</html>
<?php
@$num = $_POST['num'];
if(isset($_POST['num'])){
    $num = intval($_POST['num']);
    if($num == '' || !is_numeric($num) || $num<0){
		echo '该数值不能进行阶乘！';
    }else{
		if(is_int($num)){
		    if($num == 0){
				echo '0的阶乘为1!';
		    }else{
				$result = 1;
				for($i=1;$i<=$num;$i++){
				    $result *= $i;
				}
				echo "{$num}!为{$result}";
		    }
		}else{
		    echo '不能进行阶乘！';
		}
    }
}

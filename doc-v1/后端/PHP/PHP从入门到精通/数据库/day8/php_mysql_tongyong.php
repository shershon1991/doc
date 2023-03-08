<?php
header("content-type:text/html;charset=utf-8");
mysql_connect('localhost', 'root', '');
mysql_set_charset("utf8");
mysql_select_db("php");
$sql = "select * from temp1;";
$result = mysql_query($sql);
if($result === false){
	echo "执行失败，请参考：" . mysql_error();
}
else{
	echo "执行成功，数据如下：";
	echo "<table border='1'>";
	echo "<tr>";
	$field_count = mysql_num_fields($result);
	for($i=0;$i<$field_count;$i++){
		$field_name = mysql_field_name($result, $i);
		echo "<td>" . $field_name . "</td>";
	}
	echo "</tr>";
	

	while($rec = mysql_fetch_assoc($result)){
		echo "<tr>";
		for($i=0;$i<$field_count;$i++){
			$field_name = mysql_field_name($result, $i);
			echo "<td>" . $rec[$field_name] . "</td>";
		}
		echo "</tr>";
	}
	echo "</table>";
}
?>
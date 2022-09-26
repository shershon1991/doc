<html>
<head>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	<title>网页标题</title>
	<style type="text/css">
	table {
		width:980px;
		border:#000 solid 1px;
		border-collapse:collapse;
	}
	td {
		border:#000 solid 1px;
	}
	</style>
</head>
<body>
<table>
	<tr>
		<?php
		for($i=1;$i<=100;++$i){
			echo "<td><img src='images/" . $i . ".bmp'></td>";
			if($i/10==0){
				echo '</tr><tr>';
			}
		}
		?>
	</tr>
</table>
</body>
</html>
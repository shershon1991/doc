<?php

$fp = fopen("./02.txt", "a"); //追加方式打开02.txt文件（文件不存在会自动创建）
fwrite($fp, "小山你好\n"); //给文件写内容
fclose($fp); //关闭文件

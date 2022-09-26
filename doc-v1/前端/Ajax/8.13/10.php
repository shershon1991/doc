<?php
//设置header头，禁止浏览器缓存当前页面
//header("Cache-Control:no-cache");
//header("Pragma:no-cache");
//header("Expires:-1");

$fp = fopen("./10.txt", "a"); //追加方式打开10.txt文件（文件不存在会自动创建）
fwrite($fp, "hello world\n"); //给文件写内容
fclose($fp); //关闭文件
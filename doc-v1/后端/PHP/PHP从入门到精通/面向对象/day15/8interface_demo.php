<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
interface Player{//播放器接口
		function play();
		function stop();
		function next();
		function prev();
}
interface USBset{//USB设备接口
	const USBWidth = 12;//USB接口的宽度，单位毫米
	const USBHeight = 5;//USB接口的高度，单位毫米
	function dataIn();//数据输入
	function dataOut();//数据输出
}
//mp3播放器类，它同时具有播放器的功能，也具有usb的特征和功能
//则这里就可以从这2个接口获取其“特征信息”，并在其中实现它
class MP3Player implements Player, USbset{
		function play(){}	//实现该方法
		function stop(){}	//实现该方法
		function next(){}	//实现该方法
		function prev(){}	//实现该方法
		function dataIn(){}	//数据输入
		function dataOut(){}	//数据输出
}
?>
</body>
</html>
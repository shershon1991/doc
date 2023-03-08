<?php
class MyDateTime{
	function GetDate(){
		return date("Y-m-d");
	}
	function GetTime(){
		return date("H:i:s");
	}
	function GetDateTime(){
		return date("Y-m-d H:i:s");
	}
}
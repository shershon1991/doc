<?php
class ShowDateTime{
	function ShowDate(){
		$t = date("Y-m-d");
		return $t;
	}
	function ShowTime(){
		$t = date("H:i:s");
		return $t;

	}
	function ShowDateTime(){
		$t = date("Y-m-d H:i:s");
		return $t;
	}
}
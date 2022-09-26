<?php
class A{
	function f1(){
		echo "<br />__DIR__:" . __DIR__;
		echo "<br />__FILE__:" . __FILE__;
		echo "<br />__LINE__:" . __LINE__;
		echo "<br />__METHOD__:" . __METHOD__;
		echo "<br />__LINE__:" . __LINE__;
	}
}
$obj1 = new A();
$obj1->f1();
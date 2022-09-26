<?php

class FenYe{
	public function limit2($total,$per){
		$pageNo = ceil($total/$per);
		$startNo = ($pageNo-1)*$per;
		$lmt = "limit $startNo,$per";
		return $lmt;
	}
}


<?php

class Page{
    private $total;//总记录数
    private $per;//页面大小
    private $page;//页码
    private $sumPage;//总页数

    public function __construct($total, $per, $page){
        $this->total = $total;
        $this->per = $per;
        $this->page = $page;
        $this->sumPage = ceil($total/$per);

        if($page <= 1){
            $this->page = 1;
        } elseif($page >= $this->sumPage){
            $this->page = $this->sumPage;
        }
    }

	public function lmt(){
		$startNo = (($this->page)-1)*($this->per);
		$lmt = "limit $startNo,$this->per";
		return $lmt;
	}

	public function pageList(){
        if(($this->page)-1 == 0){
            $last = 1;
        } else{
            $last = ($this->page)-1;
        }
        if(($this->page)+1 > ($this->sumPage)){
            $next = ($this->sumPage);
        } else{
            $next = ($this->page)+1;
        }
        $str = "【<a href='fenye.php?page=1'>首页</a>】";
        $str .= "【<a href='fenye.php?page=" . $last . "'>上一页</a>】";
        $str .= "【<a href='fenye.php?page=" . $next . "'>下一页</a>】";
        $str .= "【<a href='fenye.php?page=" . ($this->sumPage). "'>尾页</a>】";

        for($i=1;$i<=$this->sumPage;++$i){
            $str .= '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="fenye.php?page=' . $i . '">' . $i . '</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
        }

        return $str;
    }
}


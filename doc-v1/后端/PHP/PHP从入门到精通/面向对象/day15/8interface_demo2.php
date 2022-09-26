<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
interface Player{//播放器接口
    function play();
    function stop();
    function prev();
    function next();
}
interface USBset{//USB设备接口
    const USBWidth = 12;//USB接口的宽度，单位毫米
    const USBHeight = 5;//USB接口的高度，单位毫米
    function dataIn();//数据输入
    function dataOut();//数据输出
}

class MP3Player implements Player, USBset{
    function play(){
        
    };
    function stop(){
        
    };
    function prev(){
        
    };
    function next(){
        
    };
    function dataIn(){
        
    }
    function dataOut(){
        
    }
}


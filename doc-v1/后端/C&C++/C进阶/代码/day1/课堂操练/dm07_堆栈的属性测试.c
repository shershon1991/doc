#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//栈在debug下的开口向下，在release下的开口向上
//一般认为，栈的开口向下
//不管栈的开口向上还是向下,buf的内存地址buf+1是永远向上的

void main71()
{
          int a, b;

          char buf[128]; //在静态编译的时候，buf所代表的内存空间的标号，就已经定下来了

          printf("&a:%d, &b:%d\n", &a, &b);

          system("pause");
          return;
}
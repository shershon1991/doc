#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//一级指针的典型用法
//数组int a[10]
//字符串
//1.C语言的字符串 是以零结尾的字符串
//2.在C语言中没有字符串类型，通过字符数组来模拟字符串
//3.字符串的内存分配 堆上 栈上 全局区（很重要）

//字符数组 初始化
void main51()
{
          //1.指定长度
          char buf2[100] = {'a', 'b', 'c', 'd'};
          //char buf3[2] = { 'a','b','c','d' };//若初始化的个数大于内存的个数，编译错误
          //后面的buf2[4]-buf2[99]都是0

          //2.不指定长度 C编译器会自动帮程序员求元素的个数
          char buf1[] = {'a', 'b', 'c', 'd'}; //buf1是一个数组，不是一个以0结尾的字符串

          printf("buf2:%s\n", buf2);
          printf("buf2[88]:%d\n", buf2[88]);

          printf("hello...\n");
          system("pause");
          return;
}

//用字符串来初始化字符数组
void main52()
{
          int size = 0;
          char buf3[] = "abcd"; //buf3作为字符数组，应该是5个字节，作为字符串，应该是4个字节

          int len = strlen(buf3);
          printf("buf3的字符长度：%d \n", len); //4

          //buf3作为数组，数组是一种数据类型（本质：固定大小的内存别名）
          size = sizeof(buf3);
          printf("buf3的数组所占内存空间大小：%d \n", size); //5

          {
                    char buf4[128] = "abcd";
                    printf("buf4[100]:%d\n", buf4[100]);
          }

          printf("hello...\n");
          system("pause");
          return;
}

void main53()
{
          int i = 0;
          char *p = NULL;
          char buf5[128] = "abcdefg";

          for (i = 0; i < strlen(buf5); i++)
          {
                    printf("%c", buf5[i]);
          }

          p = buf5; //buf代表数组首元素的地址

          for (i = 0; i < strlen(buf5); i++)
          {
                    printf("%c", *p);
                    p++;
          }

          //[] *的推导过程
          //buf5[i] ===> buf5[0+i] ===> *(buf5+i)

          printf("hello...\n");
          system("pause");
          return;
}

//[]的本质和*p是一样的，只不过符合程序员的阅读习惯
//buf5是一个指针，只读的常量，buf5是一个常量指针
//为什么这么做？原因：析构内存的时候，保证buf所指向的内存空间安全释放
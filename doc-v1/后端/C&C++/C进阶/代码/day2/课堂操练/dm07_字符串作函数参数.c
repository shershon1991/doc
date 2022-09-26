#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main71()
{
          char a[] = "i am a student";
          char b[64];
          int i = 0;

          for (i = 0; *(a + i) != '\0'; i++)
          {
                    *(b + i) = *(a + i);
          }

          //0没有copy到b中
          b[i] = '\0';
          printf("a:%s\n", a);
          printf("b:%s\n", b);

          printf("hello...\n");
          system("pause");
          return;
}

//字符串copy函数技术推演
//字符串copy函数
void copy_str21(char *from, char *to)
{
          for (; *from != '\0'; from++, to++)
          {
                    *to = *from;
          }
          *to = '\0';

          return;
}

//*和++的操作
//++优先级高
void copy_str22(char *from, char *to)
{
          for (; *from != '\0';)
          {
                    *to++ = *from++; //先 *to = *from;再from++, to++
          }
          *to = '\0';

          return;
}

void copy_str23(char *from, char *to)
{
          while ((*to = *from) != '\0')
          {
                    from++;
                    to++;
          }
}

void copy_str24(char *from, char *to)
{
          while ((*to++ = *from++) != '\0')
          {
                    ;
          }
}

void copy_str25(char *from, char *to)
{
          while ((*to++ = *from++))
          {
                    ;
          }
}

void main72()
{
          char *from = "abcd";
          char buf2[100];
          //copy_str21(from, buf2);
          //copy_str22(from, buf2);
          //copy_str23(from, buf2);
          //copy_str24(from, buf2);
          //copy_str25(from, buf2);
          //printf("buf2:%s\n", buf2);

          {
                    //错误案例
                    char *myto = NULL; //需要分配内存，* myto=NULL说明指针指向0x00000000，而0x00000000是系统保护的内存
                    copy_str25(from, myto);
          }

          printf("hello...\n");
          system("pause");
          return;
}

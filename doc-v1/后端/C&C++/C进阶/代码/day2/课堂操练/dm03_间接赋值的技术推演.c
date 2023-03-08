#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getFileLen(int *p)
{
          *p = 41;
}

int getFileLen2()
{
          int a = 100;
          return a;
}

int getFileLen3(int b)
{
          b = 43;
}

//一级指针的技术推演
void main31()
{
          int a = 10;
          int *p = NULL;

          a = 20; //修改a的值，直接修改
          p = &a;
          *p = 30; //p的值是a的地址，*就像一把钥匙，通过地址找到一块内存空间，并间接地修改了a的值
          printf("a:%d\n", a);

          {
                    *p = 40;
                    printf("a:%d\n", a);
          }

          getFileLen(&a);
          printf("getFileLen后a:%d\n", a);
          a = getFileLen2();
          printf("getFileLen后a:%d\n", a);
          getFileLen3(a);
          printf("getFileLen3后a:%d\n", a);

          printf("hello...\n");
          system("pause");
          return;
}

void getMem(char **p2)
{
          *p2 = 200; //间接赋值 p2是p1的地址
}

void getMem2(char *p2)
{
          p2 = 300; //间接赋值 p2是p1的地址
}

void main32()
{
          char *p1 = NULL;
          char **p2 = NULL;

          p1 = 0x11;
          p2 = 0x22;
          printf("p1:%d\n", p1);

          p1 = 0x12; //直接修改
          printf("p1:%d\n", p1);

          p2 = &p1;

          {
                    *p2 = 100; //间接赋值 p2是p1的地址
                    printf("p1:%d\n", p1);
          }

          getMem(&p1);
          printf("p1:%d\n", p1);

          getMem2(p1);
          printf("p1:%d\n", p1);

          system("pause");
          return;
}

int getMem33(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
          int ret = 0;
          char *tmp1, *tmp2;

          tmp1 = (char *)malloc(100);
          strcpy(tmp1, "123456");
          *mylen1 = strlen(tmp1); //一级指针的间接赋值
          *myp1 = tmp1;           //二级指针的间接赋值

          tmp2 = (char *)malloc(200);
          strcpy(tmp2, "abcdefghi");
          *mylen2 = strlen(tmp2); //一级指针的间接赋值
          *myp2 = tmp2;           //二级指针的间接赋值

          return ret;
}

void main33()
{
          int ret = 0;
          char *p1 = NULL;
          int len1 = 0;
          char *p2 = NULL;
          int len2 = 0;

          ret = getMem33(&p1, &len1, &p2, &len2);
          if (ret != 0)
          {
                    printf("func getMem3() error:%d \n", ret);
                    return ret;
          }
          printf("p1:%s \n", p1);
          printf("p2:%s \n", p2);
          printf("len1:%d \n", len1);
          printf("len2:%d \n", len2);
          if (p1 != NULL)
          {
                    free(p1);
                    p1 = NULL;
          }
          if (p2 != NULL)
          {
                    free(p2);
                    p2 = NULL;
          }

          system("pause");
          return ret;
}

//间接赋值的应用场景
int main34()
{
          //123都写在一个函数里面
          //12写在一个函数里，3写在另外一个函数里===>函数调用
          //1写在一个函数里，23写在另外一个函数里===》抛砖，C++会有
          char from[128];
          char to[128] = {0};
          char *p1 = from;
          char *p2 = to;

          strcpy(from, "123456789abcdefg");

          while (*p1 != '\0')
          {
                    *p2 = *p1;
                    p2++;
                    p1++;
          }

          printf("to:%s \n", to);

          system("pause");
          return;
}

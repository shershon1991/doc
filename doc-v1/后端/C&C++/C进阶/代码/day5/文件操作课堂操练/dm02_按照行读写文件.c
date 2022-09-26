#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//fputs
void main_fputs()
{
          int i = 0;
          FILE *fp = NULL;
          //char* filename = "c:\\1.txt";
          char *filename2 = "c:/22.txt"; //统一使用45°
          char a[20] = "abcdefghijk";

          fp = fopen(filename2, "w+");
          if (fp == NULL)
          {
                    printf("func fopen() err:%d \n");
                    return;
          }

          printf("打开成功 \n");
          fputs(a, fp);

          fclose(fp);

          return;
}

//fgets
void main_fgets()
{
          int i = 0;
          FILE *fp = NULL;
          //char* filename = "c:\\1.txt";
          char *filename2 = "c:/22.txt"; //统一使用45°
          char a[20] = "abcdefg";
          char buf[1024];

          fp = fopen(filename2, "r+");
          if (fp == NULL)
          {
                    printf("func fopen() err:%d \n");
                    return;
          }

          printf("打开成功 \n");

          //1.C函数库会一行一行的copy数据到buf指针所指向的内存空间中，并且变成C风格的字符串
          //2.把\n也copy到buf中
          //3.内存打包（把内存首地址+内存的长度）
          while (!feof(fp))
          {
                    char *p = fgets(buf, 1024, fp);
                    if (p == NULL)
                    {
                              goto End;
                    }

                    printf("%s", buf);
          }
End:
          if (fp != NULL)
          {
                    fclose(fp);
          }

          return;
}

void main21()
{
          //main_fputs();
          main_fgets();

          system("pause");
          return;
}

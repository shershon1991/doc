#include <stdio.h>
#pragma warning(disable : 4996)

int main1()
{
          FILE *p = fopen("C:\\temp\\a.txt", "r"); //如果文件打开，fopen返回打开文件的指针，如果失败，返回NULL
          if (p == NULL)
          {
                    printf("file open fail\n");
          }
          else
          {
                    printf("file open success\n");
                    fclose(p);
          }
          printf("end\n");

          system("pause");
          return 0;
}

int main2()
{
          FILE *p = fopen("C:\\temp\\a.txt", "a"); //使用追加的方式打开文件
          //"a"的含义：如果文件不存在，则创建；如果存在，就在文件结尾处追加

          if (p == NULL)
          {
                    printf("file open fail\n");
          }
          else
          {
                    fputs("hello", p);
                    fclose(p);
          }
          printf("end\n");

          system("pause");
          return 0;
}

int main3()
{
          /*char c = '\n';
	printf("%x\n", c);
	return 0;*/

          FILE *p = fopen("C:\\temp\\a.txt", "w"); //使用文本文件方式写文件

          if (p == NULL)
          {
                    printf("file open fail\n");
          }
          else
          {
                    fputs("hello\n", p);
                    fputs("world\n", p);
                    fclose(p);
          }
          printf("end\n");

          system("pause");
          return 0;
}
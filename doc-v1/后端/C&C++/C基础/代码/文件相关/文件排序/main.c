#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

void swap(int *a, int *b) //交换参数的值
{
          int tmp = *a;
          *a = *b;
          *b = tmp;
}

void bubble(int *p, int n) //冒泡排序
{
          int i;
          int j;
          for (i = 0; i < n; i++)
          {
                    for (j = 1; j < n - 1; j++)
                    {
                              if (p[j - 1] > p[j])
                              {
                                        swap(&p[j - 1], &p[j]);
                              }
                    }
          }
}

int main1() //在栈中建立一个数组，对文件内容进行排序
{
          int index = 0; //计数器
          int array[100] = {0};
          char buf[100];

          FILE *p = fopen("C:\\temp\\a.txt", "r");
          if (p == NULL)
          {
                    printf("error\n");
          }
          else
          {

                    while (!feof(p)) //如果没有到达文件结尾，循环继续
                    {
                              memset(buf, 0, sizeof(buf)); //每次读取之前清空buf
                              fgets(buf, sizeof(buf), p);  //从文件中读取一行
                              array[index] = atoi(buf);    //将读取的一行转换为int，并赋值给数组成员
                              index++;
                    }

                    fclose(p);
          }
          bubble(array, index);
          p = fopen("C:\\temp\\b.txt", "w");
          int i;
          for (i = 0; i < index - 1; i++)
          {
                    memset(buf, 0, sizeof(buf));
                    sprintf(buf, "%d\n", array[i]); //将数组成员转换为字符串
                    fputs(buf, p);
          }
          fclose(p);

          return 0;
}

int main() //在堆中建立一个数组，对文件内容进行排序
{
          int index = 0; //计数器
          char buf[100];

          FILE *p = fopen("C:\\temp\\a.txt", "r"); //第一次打开文件的目的：得知文件行数
          while (!feof(p))                         //如果没有到达文件结尾，循环继续
          {
                    memset(buf, 0, sizeof(buf)); //每次读取之前清空buf
                    fgets(buf, sizeof(buf), p);  //从文件中读取一行
                    index++;
          }
          fclose(p);

          int *array = calloc(sizeof(int), index); //在堆中动态建立数组

          p = fopen("C:\\temp\\a.txt", "r");
          index = 0; //计数器从0开始
          while (!feof(p))
          {
                    fgets(buf, sizeof(buf), p);
                    array[index] = atoi(buf);
                    index++;
          }
          fclose(p);

          bubble(array, index);
          p = fopen("C:\\temp\\b.txt", "w");
          int i;
          for (i = 0; i < index - 1; i++)
          {
                    memset(buf, 0, sizeof(buf));
                    sprintf(buf, "%d\n", array[i]); //将数组成员转换为字符串
                    fputs(buf, p);
          }
          fclose(p);

          return 0;
}
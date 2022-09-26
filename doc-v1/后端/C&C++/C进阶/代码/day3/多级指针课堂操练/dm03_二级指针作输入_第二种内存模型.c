#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>

//打印 排序 封装成函数
void main31()
{
          int i, j = 0;
          int num = 4;

          char myBuf[30];
          char myArray[10][30] = {"aaaaa", "ccccc", "bbbbb", "1111111111"};

          printf("排序前\n");
          for (i = 0; i < num; i++)
          {
                    printf("%s \n", myArray[i]);
          }

          //排序
          for (i = 0; i < num; i++)
          {
                    for (j = i + 1; j < num; j++)
                    {
                              if (strcmp(myArray[i], myArray[j]) > 0)
                              {
                                        strcpy(myBuf, myArray[i]);
                                        strcpy(myArray[i], myArray[j]);
                                        strcpy(myArray[j], myBuf);
                              }
                    }
          }

          printf("排序后\n");
          for (i = 0; i < num; i++)
          {
                    printf("%s \n", myArray[i]);
          }

          system("pause");
          return;
}

/*
问题的本质：dm03_二级指针作输入_第二种内存模型 的 myArray+i
与 dm02_二级指针作输入_第一种内存模型 的 myArray+i不一样
指针的步长不一样，指针所指向的内存空间的数据类型不一样
*/
void printMyArray31(char **myArray, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i)); //
          }
}

void printMyArray32(char myArray[10][30], int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i));
          }
}

void sortMyArray31(char myArray[10][30], int num)
{
          int i, j = 0;
          char myBuf[30];
          ;
          //排序
          for (i = 0; i < num; i++)
          {
                    for (j = i + 1; j < num; j++)
                    {
                              if (strcmp(myArray[i], myArray[j]) > 0)
                              {
                                        strcpy(myBuf, myArray[i]);
                                        strcpy(myArray[i], myArray[j]);
                                        strcpy(myArray[j], myBuf);
                              }
                    }
          }
}

void main32()
{
          int i, j = 0;
          int num = 4;

          char myBuf[30];
          char myArray[10][30] = {"aaaaa", "ccccc", "bbbbb", "1111111111"};
          //myArray:编译器只会关心，有10行，每行30列，干什么？myArray+1，这是多维数组名的本质

          {
                    int len1 = sizeof(myArray);
                    int len2 = sizeof(myArray[0]);
                    int size = len1 / len2;
                    printf("len1:%d, len2:%d, size:%d \n", len1, len2, size);
          }

          printf("排序前\n");
          //printMyArray31(myArray, num);//error
          printMyArray32(myArray, num);

          sortMyArray31(myArray, num);

          printf("排序后\n");
          printMyArray32(myArray, num);

          system("pause");
          return;
}
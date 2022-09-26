#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main21()
{
          int i, j = 0;
          int num = 0;
          char *tmp;
          //数组中的每一个元素都是指针 指针数组
          char *myArray[] = {"aaaaa", "ccccc", "bbbbb", "11111"};

          printf("排序之前： \n");
          num = sizeof(myArray) / sizeof(myArray[0]);
          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i));
          }

          //排序
          for (i = 0; i < num; i++)
          {
                    for (j = i; j < num; j++)
                    {
                              if (strcmp(myArray[i], myArray[j]) > 0)
                              {
                                        tmp = myArray[i];
                                        myArray[i] = myArray[j];
                                        myArray[j] = tmp;
                              }
                    }
          }

          printf("排序之后： \n");
          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i));
          }

          printf("hello...\n");
          system("pause");
          return;
}

void printMyArray11(char **myArray, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i));
          }
}

void sortMyArray11(char **myArray, int num)
{
          int i, j = 0;
          char *tmp = NULL;

          //排序
          for (i = 0; i < num; i++)
          {
                    for (j = i; j < num; j++)
                    {
                              if (strcmp(myArray[i], myArray[j]) > 0)
                              {
                                        tmp = myArray[i];
                                        myArray[i] = myArray[j];
                                        myArray[j] = tmp;
                              }
                    }
          }
}

void main22()
{
          int num = 0;

          //数组中的每一个元素都是指针 指针数组
          char *myArray[] = {"aaaaa", "ccccc", "bbbbb", "11111"};

          printf("排序之前： \n");
          num = sizeof(myArray) / sizeof(myArray[0]);
          printMyArray11(myArray, num);

          sortMyArray11(myArray, num);

          printf("排序之后： \n");
          printMyArray11(myArray, num);

          printf("hello...\n");
          system("pause");
          return;
}
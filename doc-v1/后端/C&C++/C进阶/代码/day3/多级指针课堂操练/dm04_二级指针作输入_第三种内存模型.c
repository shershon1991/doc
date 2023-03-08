#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main41()
{
          int i, j = 0;
          char **p2 = NULL;
          int num = 5;
          char *tmp;
          char tmpBuf[100];

          p2 = (char **)malloc(sizeof(char *) * num);
          for (i = 0; i < num; i++)
          {
                    p2[i] = (char *)malloc(sizeof(char) * 100); //char buf[100]
                    sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
          }

          printf("排序之前 \n");
          for (i = 0; i < num; i++)
          {
                    printf("%s \n", p2[i]);
          }

          //排序1 交换的是指针
          /*for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}*/

          //排序2 交换的是内存
          for (i = 0; i < num; i++)
          {
                    for (j = i + 1; j < num; j++)
                    {
                              if (strcmp(p2[i], p2[j]) < 0)
                              {
                                        strcpy(tmpBuf, p2[i]);
                                        strcpy(p2[i], p2[j]);
                                        strcpy(p2[j], tmpBuf);
                              }
                    }
          }

          printf("排序之后 \n");
          for (i = 0; i < num; i++)
          {
                    printf("%s \n", p2[i]);
          }

          //释放内存
          for (i = 0; i < num; i++)
          {
                    if (p2[i] != NULL)
                    {
                              free(p2[i]);
                              p2[i] = NULL;
                    }
          }

          if (p2 != NULL)
          {
                    free(p2);
                    p2 = NULL;
          }

          system("pause");
          return;
}

char **getMem41(int num)
{
          char **p2;
          int i = 0;

          p2 = (char **)malloc(sizeof(char *) * num);
          if (p2 == NULL)
          {
                    return NULL;
          }
          for (i = 0; i < num; i++)
          {
                    p2[i] = (char *)malloc(sizeof(char) * 100); //char buf[100]
                    sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
          }

          return p2;
}

void printMyArray41(char **myArray, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    //printf("%s \n", myArray[i]);
                    printf("%s \n", *(myArray + i));
          }
}

void sortMyArray41(char **myArray, int num)
{
          int i, j = 0;
          char *tmp = NULL;

          for (i = 0; i < num; i++)
          {
                    for (j = i; j < num; j++)
                    {
                              if (strcmp(myArray[i], myArray[j]) < 0)
                              {
                                        tmp = myArray[i];
                                        myArray[i] = myArray[j];
                                        myArray[j] = tmp;
                              }
                    }
          }
}

void getMemFree41(char **p, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    if (p[i] != NULL)
                    {
                              free(p[i]);
                              p[i] = NULL;
                    }
          }

          if (p != NULL)
          {
                    free(p);
                    p = NULL;
          }
}

void main42()
{
          int i, j = 0;
          char **p2 = NULL;
          int num = 5;
          char *tmp;
          char tmpBuf[100];

          p2 = getMem41(num);

          printf("排序之前 \n");
          printMyArray41(p2, num);

          sortMyArray41(p2, num);

          printf("排序之后 \n");
          printMyArray41(p2, num);

          //释放内存
          getMemFree41(p2, num);

          system("pause");
          return;
}

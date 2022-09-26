#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//有一个字符串（"abcdefg,acccd,eeee,aaaa,e3rrr,ssss,"）
//写一个接口：以逗号分割字符串，形成二维数组，把结果输出；把二维数组行数运算结果也传出

int spitStr(const char *buf1, char c, char buf2[10][30], int *count)
{
          /*strcpy(buf2[0], "aaaa");
	strcpy(buf2[1], "bbbb");
	*count = 2;*/

          char *p = NULL, *pTmp = NULL;
          int tmpCount = 0;

          //1.初始化
          p = buf1;
          pTmp = buf1;

          do
          {
                    //2.检索复合条件的位置，p后移，形成差值，挖字符串
                    p = strchr(p, c);
                    if (p != NULL)
                    {
                              if (p - pTmp > 0)
                              {
                                        strncpy(buf2[tmpCount], pTmp, p - pTmp);
                                        buf2[tmpCount][p - pTmp] = '\0'; //把第一行数据变成C风格字符串
                                        tmpCount++;
                                        //3.重新让p和pTmp达到下一次检索的条件
                                        pTmp = p = p + 1;
                              }
                    }
                    else
                    {
                              break;
                    }
          } while (*p != '\0');
          *count = tmpCount;

          return 0;
}

void main71()
{
          int ret, i = 0;
          char *p1 = "abcdefg,acccd,eeee,aaaa,e3rrr,ssss,";
          char deli = ',';
          char myArr[10][30];
          int count;

          ret = spitStr(p1, deli, myArr, &count);
          if (ret != 0)
          {
                    printf("func spitStr() err:%d \n", ret);
                    return ret;
          }

          for (i = 0; i < count; i++)
          {
                    printf("%s \n", myArr[i]);
          }
          printf("count:%d \n", count);

          system("pause");
          return;
}

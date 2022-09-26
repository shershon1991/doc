#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MaxLine 2048

//获取配置项
int getCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char *pValue /*in*/, int *pValueLen /*out*/)
{
          int ret = 0;
          FILE *fp = NULL;
          char lineBuf[MaxLine];
          char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;

          fp = fopen(pFileName, "r");
          if (fp == NULL)
          {
                    ret = -1;
                    return ret;
          }

          while (!feof(fp))
          {
                    memset(lineBuf, 0, sizeof(lineBuf));
                    fgets(lineBuf, MaxLine, fp);

                    //printf("lineBuf:%s ", lineBuf);

                    pTmp = strchr(lineBuf, '=');
                    if (pTmp == NULL) //判断有没有=
                    {
                              continue;
                    }

                    pTmp = strstr(lineBuf, pKey);
                    if (pTmp == NULL) //判断所在行是否有key
                    {
                              continue;
                    }

                    pTmp = pTmp + strlen(pKey);

                    pTmp = strchr(pTmp, '=');
                    if (pTmp == NULL)
                    {
                              continue;
                    }
                    pTmp = pTmp + 1;

                    //printf("pTmp:%s", pTmp);

                    //获取value起点
                    while (1)
                    {
                              if (*pTmp == ' ')
                              {
                                        pTmp++;
                              }
                              else
                              {
                                        pBegin = pTmp;
                                        if (*pBegin == '\n')
                                        {
                                                  //printf("配置项：%s， 没有配置value \n", pKey);
                                                  goto End;
                                        }
                                        break;
                              }
                    }
                    //获取value终点
                    while (1)
                    {
                              if (*pTmp == ' ' || *pTmp == '\n')
                              {
                                        break;
                              }
                              else
                              {
                                        pTmp++;
                              }
                    }
                    pEnd = pTmp;
                    //赋值
                    *pValueLen = pEnd - pBegin;
                    memcpy(pValue, pBegin, pEnd - pBegin);
                    printf("pValue:%s \n", pValue);
          }

End:
          if (fp == NULL)
          {
                    fclose(fp);
          }
          return 0;
}

//写配置项
int writeCfgItem(char *pFileName /*in*/, char *pItemName /*in*/, char *pItemValue /*in*/, int itemValueLen /*in*/)
{
          return 0;
}
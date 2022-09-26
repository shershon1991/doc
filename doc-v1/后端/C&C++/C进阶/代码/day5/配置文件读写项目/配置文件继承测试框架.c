#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cfg_op.h"

#define CFGNAME "c:/mycfg.ini"

void myMenu()
{
          printf("======================\n");
          printf("1 测试写配置文件\n");
          printf("2 测试读配置文件\n");
          printf("0 退出\n");
          printf("======================\n");
}

//获取配置项
int tGetCfg()
{
          int ret = 0;
          int vlen = 0;
          char name[1024];
          char value[1024];

          printf("\n请键入key:");
          scanf("%s", name);

          ret = getCfgItem(CFGNAME /*in*/, name /*in*/, value /*in*/, &vlen);
          if (ret != 0)
          {
                    printf("func getCfgItem() err:%d \n", ret);
                    return ret;
          }
          printf("value:%s \n", value);

          return 0;
}

//写配置项
int tWriteCfg()
{
          int ret = 0;
          char name[1024];
          char value[1024];

          printf("\n请键入key:");
          scanf("%s", name);

          printf("\n请键入value:");
          scanf("%s", value);

          ret = writeCfgItem(CFGNAME /*in*/, name /*in*/, value /*in*/, strlen(value) /*in*/);
          if (ret != 0)
          {
                    printf("func writeCfgItem() err:%d \n", ret);
                    return ret;
          }
          printf("你的输入是：%s = %s \n", name, value);

          return ret;
}

void main()
{
          int choice;

          for (;;)
          {
                    //显示一个菜单
                    myMenu();
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1: //写配置项
                              tWriteCfg();
                              break;
                    case 2: //读配置项
                              tGetCfg();
                              break;
                    case 0:
                              exit(0);
                              break;
                    default:
                              exit(0);
                    }
          }

          system("pause");
          return;
}

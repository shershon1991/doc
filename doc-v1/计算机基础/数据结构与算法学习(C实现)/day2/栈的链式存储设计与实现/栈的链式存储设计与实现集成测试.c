#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkstack.h"

void main()
{
          int i = 0;
          int a[10];
          LinkStack *stack = NULL;

          stack = LinkStack_Create();
          if (stack == NULL)
          {
                    return;
          }

          //添加元素
          for (i = 0; i < 5; i++)
          {
                    a[i] = i + 1;
                    LinkStack_Push(stack, &a[i]);
          }

          //获取栈的基本属性
          printf("top:%d \n", *((int *)LinkStack_Top(stack)));
          printf("length:%d \n", LinkStack_Size(stack));

          //删除栈元素
          while (LinkStack_Size(stack) > 0)
          {
                    int tmp = *((int *)LinkStack_Pop(stack));
                    printf("tmp:%d \n", tmp);
          }

          //销毁栈
          LinkStack_Destroy(stack);

          system("pause");
          return;
}

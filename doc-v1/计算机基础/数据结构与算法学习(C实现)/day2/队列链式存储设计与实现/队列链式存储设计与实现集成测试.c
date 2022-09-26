#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkqueue.h"

void main()
{
          int i = 0, a[10];
          LinkQueue *queue = NULL;

          queue = LinkQueue_Create();
          if (queue == NULL)
          {
                    return;
          }

          //入队列
          for (i = 0; i < 5; i++)
          {
                    a[i] = i + 1;
                    LinkQueue_Append(queue, &a[i]);
          }

          //求队列的属性
          printf("len:%d \n", LinkQueue_Length(queue));
          printf("header:%d \n", *((int *)LinkQueue_Header(queue)));

          //出队列
          while (LinkQueue_Length(queue) > 0)
          {
                    int tmp = *((int *)LinkQueue_Retrieve(queue));
                    printf("tmp:%d \n", tmp);
          }

          //销毁队列
          LinkQueue_Destroy(queue);

          system("pause");
          return;
}

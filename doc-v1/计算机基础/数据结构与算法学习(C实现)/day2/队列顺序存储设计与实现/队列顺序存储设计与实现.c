#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqqueue.h"

void main()
{
          int i = 0, ret = 0;
          int a[10];
          SeqQueue *queue = NULL;

          //创建队列
          queue = SeqQueue_Create(10);
          if (queue == NULL)
          {
                    return;
          }

          //入队列
          for (i = 0; i < 5; i++)
          {
                    a[i] = i + 1;
                    ret = SeqQueue_Append(queue, &a[i]);
          }

          //打印队列的属性
          printf("len:%d \n", SeqQueue_Length(queue));
          printf("header:%d \n", *((int *)SeqQueue_Header(queue)));
          printf("capacity:%d \n", SeqQueue_Capacity(queue));

          //出队列
          while (SeqQueue_Length(queue) > 0)
          {
                    int *tmp = SeqQueue_Retrieve(queue);
                    printf("tmp:%d \n", *tmp);
          }

          //销毁队列
          SeqQueue_Destroy(queue);

          system("pause");
          return;
}

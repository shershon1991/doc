#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct Teacher
{
          LinkListNode node;
          int age;
          char name[64];
} Teacher;

void main()
{
          int i = 0, len = 0, ret = 0;

          LinkList *list = NULL;
          Teacher t1, t2, t3, t4, t5;
          t1.age = 31;
          t2.age = 32;
          t3.age = 33;
          t4.age = 34;
          t5.age = 35;

          //创建链表
          list = LinkList_Create();
          if (list == NULL)
          {
                    return;
          }

          //链表的算法和具体业务结点的分离
          //插入结点
          len = LinkList_Length(list);
          ret = LinkList_Insert(list, (LinkListNode *)(&t1), 0);
          ret = LinkList_Insert(list, (LinkListNode *)(&t2), 0);
          ret = LinkList_Insert(list, (LinkListNode *)(&t3), 0);
          ret = LinkList_Insert(list, (LinkListNode *)(&t4), 0);
          ret = LinkList_Insert(list, (LinkListNode *)(&t5), 0);

          //遍历
          for (i = 0; i < LinkList_Length(list); i++)
          {
                    Teacher *tmp = (Teacher *)LinkList_Get(list, i);
                    if (tmp == NULL)
                    {
                              return;
                    }
                    printf("tmp->age:%d\n", tmp->age);
          }

          //删除链表
          while (LinkList_Length(list) > 0)
          {
                    Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
                    if (tmp == NULL)
                    {
                              return;
                    }
                    printf("tmp->age:%d\n", tmp->age);
          }

          //销毁链表
          LinkList_Destroy(list);

          system("pause");
          return;
}

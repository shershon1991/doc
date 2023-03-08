#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
          LinkListNode header;
          int length;
} TLinkList;

LinkList *LinkList_Create()
{
          TLinkList *ret = NULL;
          ret = (TLinkList *)malloc(sizeof(TLinkList));
          memset(ret, 0, sizeof(TLinkList));
          ret->length = 0;
          ret->header.next = NULL;

          return ret;
}

void LinkList_Destroy(LinkList *list)
{
          if (list != NULL)
          {
                    free(list);
                    list = NULL;
          }
          return;
}

//让链表恢复到初始化状态
void LinkList_Clear(LinkList *list)
{
          TLinkList *tList = NULL;
          if (list == NULL)
          {
                    return;
          }
          tList = (TLinkList *)list;

          tList->header.next = NULL;
          tList->length = 0;

          return;
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
          int ret = 0, i = 0;
          LinkListNode *current = NULL;
          TLinkList *tList = NULL;

          if (list == NULL || node == NULL || pos < 0)
          {
                    ret = -1;
                    printf("func LinkList_Insert() err:%d \n", ret);
                    return ret;
          }
          tList = (TLinkList *)list;
          current = &(tList->header);

          for (i = 0; i < pos && (current->next != NULL); i++)
          {
                    current = current->next;
          }

          node->next = current->next;
          current->next = node;
          tList->length++;

          return 0;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
          int i = 0;
          LinkListNode *current = NULL;
          LinkListNode *ret = NULL;
          TLinkList *tList = NULL;

          if (list == NULL || pos < 0)
          {
                    printf("func LinkList_Insert() err:%d \n", ret);
                    return NULL;
          }
          tList = (TLinkList *)list;
          current = &(tList->header);

          for (i = 0; i < pos && (current->next != NULL); i++)
          {
                    current = current->next;
          }
          //缓存被删除的结点的位置
          ret = current->next;
          //连线
          current->next = ret->next;
          tList->length--;

          return ret;
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
          int ret = 0, i = 0;
          LinkListNode *current = NULL;
          TLinkList *tList = NULL;

          if (list == NULL || pos < 0)
          {
                    ret = -1;
                    printf("func LinkList_Insert() err:%d \n", ret);
                    return NULL;
          }
          tList = (TLinkList *)list;
          current = &(tList->header);

          for (i = 0; i < pos && (current->next != NULL); i++)
          {
                    current = current->next;
          }

          return current->next;
}

int LinkList_Length(LinkList *list)
{
          TLinkList *tList = NULL;
          if (list == NULL)
          {
                    return -1;
          }
          tList = (TLinkList *)list;
          return tList->length;
}
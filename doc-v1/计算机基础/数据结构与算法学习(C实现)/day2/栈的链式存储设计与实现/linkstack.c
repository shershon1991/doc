#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkstack.h"
#include "linklist.h"

/*
typedef struct Teacher
{
	LinkListNode node;
	void* item;
}Teacher;
*/

typedef struct _tag_LinkStackNode
{
          LinkListNode node;
          void *item;
} TLinkStackNode;

//创建一个栈 相当于 创建一个线性表
LinkStack *LinkStack_Create()
{
          return LinkList_Create();
}

//销毁一个栈 相当于 销毁一个线性表
void LinkStack_Destroy(LinkStack *stack)
{
          LinkStack_Clear(stack);
          LinkList_Destroy(stack);
}

//清空一个栈 相当于 清空一个线性表
//清空一个栈时，涉及到栈元素生命周期的管理

//所有入栈的结点都是malloc出来的
//清空栈时，把栈中元素弹出，且释放结点内存
void LinkStack_Clear(LinkStack *stack)
{
          if (stack == NULL)
          {
                    return;
          }
          while (LinkStack_Size(stack) > 0)
          {
                    LinkStack_Pop(stack); //在这个函数中释放结点的内存
          }
          return;
}

//向栈中添加元素 相当于 向线性表的头部插入元素
//void* item 栈的业务结点 ===》 转化成链表的业务结点
int LinkStack_Push(LinkStack *stack, void *item)
{
          int ret = 0;
          TLinkStackNode *tmp = NULL;

          tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
          if (tmp == NULL)
          {
                    return -1;
          }
          memset(tmp, 0, sizeof(TLinkStackNode));
          tmp->item = item;

          ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
          if (ret != 0)
          {
                    printf("func LinkStack_Push() err:%d \n", ret);
                    if (tmp != NULL)
                    {
                              free(tmp);
                    }
                    return ret;
          }

          return ret;
}

//向栈中弹出元素 相当于 向线性表的头部删除元素
//把线性表的业务结点 转化成 栈的业务结点
void *LinkStack_Pop(LinkStack *stack)
{
          void *item = NULL; //栈的业务结点
          TLinkStackNode *tmp = NULL;
          tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
          if (tmp == NULL)
          {
                    return NULL;
          }
          item = tmp->item;
          //因为LinkList_Insert的时候，分配了内存，所有LinkList_Delete释放内存
          free(tmp);
          return item;
}

//获取栈顶元素 相当于 获取线性表的0号位置的元素
void *LinkStack_Top(LinkStack *stack)
{
          TLinkStackNode *tmp = NULL;
          tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
          if (tmp == NULL)
          {
                    return NULL;
          }
          return tmp->item;
}

//求栈的大小 相当于 求线性表的大小
int LinkStack_Size(LinkStack *stack)
{
          return LinkList_Length(stack);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqstack.h"
#include "seqlist.h"

//创建栈 相当于 创建线性表
SeqStack *SeqStack_Create(int capacity)
{
          return SeqList_Create(capacity);
}

//销毁栈 相当于 销毁线性表
void SeqStack_Destroy(SeqStack *stack)
{
          SeqList_Destroy(stack);
}

//清空栈 相当于 清空线性表
void SeqStack_Clear(SeqStack *stack)
{
          SeqList_Clear(stack);
}

//向栈中压入元素 相当于 向链表的尾部 插入元素
int SeqStack_Push(SeqStack *stack, void *item)
{
          return SeqList_Insert(stack, item, SeqList_Length(stack));
}

//从栈中弹出元素 相当于 从链表的尾部拿出元素
void *SeqStack_Pop(SeqStack *stack)
{
          return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

//获取栈顶元素 相当于 获取链表的尾部元素
void *SeqStack_Top(SeqStack *stack)
{
          return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

//获取栈的大小 相当于 获取链表的实际长度
int SeqStack_Size(SeqStack *stack)
{
          return SeqList_Length(stack);
}

//获取栈的容量 相当于 获取链表的容量
int SeqStack_Capacity(SeqStack *stack)
{
          return SeqList_Capacity(stack);
}
Pop(SeqStack *stack)
{
          return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

//获取栈顶元素 相当于 获取链表的尾部元素
void *SeqStack_Top(SeqStack *stack)
{
          return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

//获取栈的大小 相当于 获取链表的实际长度
int SeqStack_Size(SeqStack *stack)
{
          return SeqList_Length(stack);
}

//获取栈的容量 相当于 获取链表的容量
int SeqStack_Capacity(SeqStack *stack)
{
          return SeqList_Capacity(stack);

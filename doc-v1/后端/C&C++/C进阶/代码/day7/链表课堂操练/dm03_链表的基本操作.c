#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node
{
          int data;
          struct Node *next;
} SLIST;

typedef struct Node2
{
          int data;
          char name[64];
          struct Node *next;
} SLIST2;

typedef struct myNode
{
          struct Node *next;
} myNode;

typedef struct Teacher
{
          int data;
          char name[64];
          char name2[128];
          struct Node node;
} Teacher;

void TestAdv()
{
          Teacher t1, t2, t3;
          t1.node.next = &(t2.node);
          t2.node.next = &(t3.node);
          t3.node.next = NULL;
}

SLIST *SList_Create();                            //创建链表
int SList_Print(SLIST *pHead);                    //遍历链表
int SList_NodeInsert(SLIST *pHead, int x, int y); //在x值之前插入y,若x值不存在，在尾部插入y
int SList_NodeDel(SLIST *pHead, int y);           //删除y值
int SList_Destory(SLIST *pHead);                  //销毁链表
int SList_Reverse(SLIST *pHead);                  //逆置链表

SLIST *SList_Create()
{
          int data;
          SLIST *pHead, *pM, *pCur;

          //创建头结点，并初始化
          pHead = (SLIST *)malloc(sizeof(SLIST));
          if (pHead == NULL)
          {
                    return NULL;
          }
          pHead->data = 0;
          pHead->next = NULL;

          printf("\nplease enter you data:");
          scanf("%d", &data);

          pCur = pHead;

          while (data != -1)
          {
                    //1.创建业务结点，并初始化(不断接受输入，malloc新结点)
                    pM = (SLIST *)malloc(sizeof(SLIST));
                    if (pM == NULL)
                    {
                              return NULL;
                    }
                    pM->data = data;
                    pM->next = NULL;

                    //2.新结点入链表
                    pCur->next = pM;

                    //3.新结点变成当前结点
                    pCur = pM;

                    printf("\nplease enter you data:");
                    scanf("%d", &data);
          }

          return pHead;
}

int SList_Print(SLIST *pHead)
{
          SLIST *tmp = NULL;

          if (pHead == NULL)
          {
                    return -1;
          }
          tmp = pHead->next;

          printf("\nbegin\t");
          while (tmp)
          {
                    printf("%d ", tmp->data);
                    tmp = tmp->next;
          }
          printf("\tend");

          return 0;
}

int SList_NodeInsert(SLIST *pHead, int x, int y)
{
          SLIST *pM, *pCur, *pPre;

          //创建新的业务结点pM
          pM = (SLIST *)malloc(sizeof(SLIST));
          if (pM == NULL)
          {
                    return -1;
          }
          pM->data = y;
          pM->next = NULL;

          //遍历链表
          pPre = pHead;
          pCur = pHead->next;

          while (pCur)
          {
                    if (pCur->data == x)
                    {
                              break;
                    }
                    pPre = pCur;
                    pCur = pCur->next;
          }

          //让新结点连接后续链表
          pM->next = pPre->next;
          //让前驱结点连接新结点
          pPre->next = pM;

          return 0;
}

int SList_NodeDel(SLIST *pHead, int y)
{
          SLIST *pCur, *pPre;

          //初始化
          pPre = pHead;
          pCur = pHead->next;

          while (pCur != NULL)
          {
                    if (pCur->data == y)
                    {
                              break;
                    }
                    pPre = pCur;
                    pCur = pCur->next;
          }

          //删除操作
          if (pCur == NULL)
          {
                    printf("未找到值为:%d的结点", y);
                    return -1;
          }
          pPre->next = pCur->next;
          if (pCur != NULL)
          {
                    free(pCur);
          }

          return 0;
}

int SList_Destory(SLIST *pHead)
{
          SLIST *tmp = NULL;

          if (pHead == NULL)
          {
                    return -1;
          }

          while (tmp != NULL)
          {
                    tmp = pHead->next;
                    free(pHead);
                    pHead = tmp;
          }

          return 0;
}

int SList_Reverse(SLIST *pHead)
{
          SLIST *p = NULL; //前驱指针
          SLIST *q = NULL; //当前指针
          SLIST *t = NULL; //缓存的一个结点

          if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
          {
                    return 0;
          }

          //初始化
          p = pHead->next;
          q = pHead->next->next;
          //一个结点一个结点地逆置
          while (q)
          {
                    t = q->next; //缓存后面的链表
                    q->next = p; //逆置
                    p = q;       //让p下移一个结点
                    q = t;
          }
          //头结点 变成 尾部结点后 置为NULL
          pHead->next->next = NULL;
          pHead->next = p;

          return 0;
}

void main31()
{
          int ret = 0;

          SLIST *pHead = NULL;
          pHead = SList_Create();
          ret = SList_Print(pHead);

          ret = SList_NodeInsert(pHead, 20, 19);
          ret = SList_Print(pHead);

          ret = SList_NodeDel(pHead, 19);
          ret = SList_Print(pHead);

          ret = SList_Reverse(pHead);
          ret = SList_Print(pHead);

          SList_Destory(pHead);

          system("pause");
          return;
}

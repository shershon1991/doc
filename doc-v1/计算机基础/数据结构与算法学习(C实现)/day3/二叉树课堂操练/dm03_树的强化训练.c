#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//二叉链表示法
struct BiTNode
{
          int data;
          struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode *BiTree;

void inOrder3(BiTNode *root)
{
          if (root == NULL)
          {
                    return;
          }
          //遍历左子树
          inOrder3(root->lchild);

          printf("%d ", root->data);

          //遍历右子树
          inOrder3(root->rchild);
}

int Depth(BiTNode *T)
{
          int depthleft = 0;
          int depthright = 0;
          int depthvalue = 0;

          if (T == NULL)
          {
                    depthvalue = 0;
                    return depthvalue;
          }

          //求左子树的高度
          depthleft = Depth(T->lchild);
          //求右子树的高度
          depthright = Depth(T->rchild);

          depthvalue = (depthleft > depthright ? depthleft : depthright) + 1;

          return depthvalue;
}

BiTNode *CopyTree(BiTNode *T)
{
          BiTNode *newNode = NULL;
          BiTNode *newLp = NULL;
          BiTNode *newRp = NULL;

          if (T == NULL)
          {
                    return NULL;
          }
          //copy左子树
          if (T->lchild != NULL)
          {
                    newLp = CopyTree(T->lchild);
          }
          else
          {
                    newLp = NULL;
          }
          //copy右子树
          if (T->rchild != NULL)
          {
                    newRp = CopyTree(T->rchild);
          }
          else
          {
                    newRp = NULL;
          }

          //malloc根节点
          newNode = (BiTNode *)malloc(sizeof(BiTNode));
          if (newNode == NULL)
          {
                    return NULL;
          }
          newNode->lchild = newLp;
          newNode->rchild = newRp;
          newNode->data = T->data;
          return newNode;
}

void main301()
{
          BiTNode t1, t2, t3, t4, t5;

          memset(&t1, 0, sizeof(BiTNode));
          memset(&t2, 0, sizeof(BiTNode));
          memset(&t3, 0, sizeof(BiTNode));
          memset(&t4, 0, sizeof(BiTNode));
          memset(&t5, 0, sizeof(BiTNode));
          t1.data = 1;
          t2.data = 2;
          t3.data = 3;
          t4.data = 4;
          t5.data = 5;

          //建立关系
          t1.lchild = &t2;
          t1.rchild = &t3;
          t2.lchild = &t4;
          t3.lchild = &t5;

          //求树的高度
          printf("depth:%d \n", Depth(&t1));

          //copy树
          {
                    BiTNode *root = CopyTree(&t1);
                    printf("copy inorder\n");
                    inOrder3(root);
                    printf("\n");
          }

          printf("old inorder\n");
          inOrder3(&t1);
          printf("\n");

          system("pause");
          return;
}

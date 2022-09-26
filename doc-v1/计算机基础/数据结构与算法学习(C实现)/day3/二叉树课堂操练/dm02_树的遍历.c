#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode, *BiTree;
*/

//二叉链表示法
struct BiTNode
{
          int data;
          struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode *BiTree;

// 先序遍历
void preOrder(BiTNode *root)
{
          if (root == NULL)
          {
                    return;
          }
          printf("%d ", root->data);

          //遍历左子树
          preOrder(root->lchild);

          //遍历右子树
          preOrder(root->rchild);
}

// 中序遍历
void inOrder(BiTNode *root)
{
          if (root == NULL)
          {
                    return;
          }
          //遍历左子树
          inOrder(root->lchild);

          printf("%d ", root->data);

          //遍历右子树
          inOrder(root->rchild);
}

// 后序遍历
void postOrder(BiTNode *root)
{
          if (root == NULL)
          {
                    return;
          }
          //遍历左子树
          postOrder(root->lchild);

          //遍历右子树
          postOrder(root->rchild);

          printf("%d ", root->data);
}

int sum;

void countLeaf(BiTNode *T)
{
          if (T != NULL)
          {
                    if (T->lchild == NULL && T->rchild == NULL)
                    {
                              sum++;
                    }
                    if (T->lchild)
                    {
                              countLeaf(T->lchild);
                    }
                    if (T->rchild)
                    {
                              countLeaf(T->rchild);
                    }
          }
}

void countLeaf2(BiTNode *T, int *sum)
{
          if (T != NULL)
          {
                    if (T->lchild == NULL && T->rchild == NULL)
                    {
                              (*sum)++;
                    }
                    if (T->lchild)
                    {
                              countLeaf2(T->lchild, sum);
                    }
                    if (T->rchild)
                    {
                              countLeaf2(T->rchild, sum);
                    }
          }
}

void countLeaf3(BiTNode *T, int *sum)
{
          if (T != NULL)
          {
                    if (T->lchild == NULL && T->rchild == NULL)
                    {
                              (*sum)++;
                    }
                    if (T->lchild)
                    {
                              countLeaf3(T->lchild, sum);
                    }
                    if (T->rchild)
                    {
                              countLeaf3(T->rchild, sum);
                    }
          }
}

void main201()
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

          sum = 0;
          countLeaf(&t1);
          printf("sum:%d \n", sum);

          int mysum = 0;
          countLeaf2(&t1, &mysum);
          printf("mysum:%d \n", mysum);

          int mysum2 = 0;
          countLeaf3(&t1, &mysum2);
          printf("mysum2:%d \n", mysum2);

          //树的遍历
          /*
	preOrder(&t1);//先序遍历
	printf("\n");
	inOrder(&t1);//中序遍历
	printf("\n");
	postOrder(&t1);//后序遍历
	*/

          system("pause");
          return;
}

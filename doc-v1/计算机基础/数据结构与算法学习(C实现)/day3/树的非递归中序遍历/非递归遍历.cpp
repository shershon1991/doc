#include <iostream>
using namespace std;
#include "stack"

//二叉链表示法
struct BiTNode
{
          int data;
          struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode *BiTree;

//递归中序遍历
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

//一直往左走，找到中序遍历的起点
BiTNode *goLeft(BiTNode *T, stack<BiTNode *> &s)
{
          if (T == NULL)
          {
                    return NULL;
          }
          //判断T有没有左孩子 若有T入栈，继续往左走，若无就return T
          while (T->lchild != NULL)
          {
                    s.push(T);
                    T = T->lchild;
          }
          return T;
}

//非递归中序遍历
void inOrder2(BiTNode *T)
{
          BiTNode *t = NULL;
          stack<BiTNode *> s;

          t = goLeft(T, s);

          while (t)
          {
                    printf("%d ", t->data);

                    //若t有右子树 重复步骤1
                    if (t->rchild != NULL)
                    {
                              t = goLeft(t->rchild, s); //右子树中序遍历的起点
                    }
                    else if (!s.empty()) //若t无右子树 根据栈顶指示 回退
                    {
                              t = s.top();
                              s.pop();
                    }
                    else //若t无右子树 且栈为空
                    {
                              t = NULL;
                    }
          }
}

void main()
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

          printf("inorder\n");
          inOrder(&t1);
          printf("\n");

          printf("非递归inorder\n");
          inOrder2(&t1);
          printf("\n");

          system("pause");
          return;
}

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

//三叉链表示法
typedef struct TriTNode
{
          int data;
          struct TriTNode *lchild, *rchild;
          struct TriTNode *parent;
} TriTNode, *TriTree;

//双亲链表示法
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
          int data;
          int parentPosition; //指向双亲的指针 //数组下标
          char LRTag;         //左右孩子标志域
} BPTNode;

typedef struct BPTree
{
          BPTNode nodes[100]; //因为结点之间是分散的，需要把结点存储到数组中
          int num_node;       //结点数目
          int root;           //根节点的位置 //注意此域存储的是父亲结点在数组的下标
} BPTree;

void main101()
{
          BiTNode t1, t2, t3, t4, t5;
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

          //树的遍历

          system("pause");
          return;
}

void main102()
{
          BiTNode *p1, *p2, *p3, *p4, *p5;
          p1 = (BiTNode *)malloc(sizeof(BiTNode));
          p2 = (BiTNode *)malloc(sizeof(BiTNode));
          p3 = (BiTNode *)malloc(sizeof(BiTNode));
          p4 = (BiTNode *)malloc(sizeof(BiTNode));
          p5 = (BiTNode *)malloc(sizeof(BiTNode));
          p1->data = 1;
          p2->data = 2;
          p3->data = 3;
          p4->data = 4;
          p5->data = 5;

          //建立关系
          p1->lchild = p2;
          p1->rchild = p3;
          p2->lchild = p4;
          p3->lchild = p5;

          //树的遍历

          system("pause");
          return;
}

void main103()
{
          BPTree tree;

          //根节点
          tree.nodes[0].parentPosition = 1000;
          //B
          tree.nodes[1].parentPosition = 0;
          tree.nodes[1].data = 'B';
          tree.nodes[1].LRTag = 1;
          //C
          tree.nodes[2].parentPosition = 0;
          tree.nodes[2].data = 'C';
          tree.nodes[2].LRTag = 2;

          system("pause");
}
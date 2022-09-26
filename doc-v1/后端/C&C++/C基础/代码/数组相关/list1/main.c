#include <stdio.h>

struct list
{
          int data;          //数据域
          struct list *next; //指针域
};

struct list *create_list() //建立一个节点
{
          return calloc(sizeof(struct list), 1);
}

struct list *insert_list(struct list *ls, int n, int data) //在指定位置插入一个元素
{
          struct list *p = ls;
          while (p && n--)
          {
                    p = p->next;
          }
          if (p == NULL)
          {
                    return NULL; //n的位置大于链表节点数
          }
          struct list *node = create_list(); //新建立一个结点
          node->data = data;
          node->next = p->next;
          p->next = node;
          return node;
}

void delete_list(struct list *ls, int n) //删除指定位置元素
{
          struct list *p = ls;
          while (p && n--)
          {
                    p = p->next;
          }
          if (p == NULL)
          {
                    return -1; //n的位置不合适
          }
          struct list *tmp = p->next;
          p->next = p->next->next;
          free(tmp);
          return 0; //删除成功
}

int count_list(struct list *ls) //返回链表元素个数
{
          struct list *p = ls;
          int count = 0;
          while (p)
          {
                    count++;
                    p = p->next;
          }
          return count;
}

void clear_list(struct list *ls) //清空链表，只是保留首节点
{
          struct list *p = ls->next;
          while (p)
          {
                    struct list *tmp = p->next;
                    free(p);
                    p = tmp;
          }
          ls->next = NULL; //只有首节点，首节点的next应该是NULL
}

int empty_list(struct list *ls) //返回链表是否为空
{
          if (ls->next)
                    return 0;
          else
                    return -1;
}

struct list *locale_list(struct list *ls, int n) //返回链表指定位置的结点
{
          struct list *p = ls;
          while (p && n--)
          {
                    p = p->next;
          }
          if (p == NULL)
                    return NULL;
          return p;
}

struct list *elem_locale(struct list *ls, int data) //返回数据域等于data的结点
{
          struct list *p = ls;
          while (p)
          {
                    if (p->data == data)
                              return p;
                    p = p->next;
          }
          return NULL; //没有找到数据域等于data的结点
}

int elem_pos(struct list *ls, int data) //返回数据域等于data的节点位置
{
          int index = 0;
          struct list *p = ls;
          while (p)
          {
                    index++;
                    if (p->data == data)
                              return index;
                    p = p->next;
          }
          return -1; //没有找到数据域等于data的结点
}

struct list *last_list(struct list *ls) //得到链表最后一个结点
{
          struct list *p = ls;
          while (p->next)
          {
                    p = p->next;
          }
          return p;
}

void merge_list(struct list *ls1, struct list *ls2) //合并两个链表，结果放入到ls1中
{
          //只合并链表的结点，不合并链表头
          last_list(ls1)->next = ls2->next;
          free(ls2); //链表头不要了
}

void traverse(struct list *ls) //循环遍历链表
{
          struct list *p = ls;
          while (p)
          {
                    printf("%d\n", p->data);
                    p = p->next; //p指向其对应的下一个节点
          }
}

int main()
{
          struct list *first = create_list(); //在堆中创建一个结点
          struct list *second = create_list();
          struct list *third = create_list();

          first->next = second;
          second->next = third;
          third->next = NULL;

          first->data = 1;
          second->data = 2;
          third->data = 3;

          insert_list(first, 1, 10);
          insert_list(first, 1, 20);
          insert_list(first, 1, 30);

          //delete_list(first, 2);

          //clear_list(first);

          traverse(first);

          printf("---------------\n");
          printf("count = %d\n", count_list(first));
          printf("%d\n", locale_list(first, 3)->data);
          printf("data = %d\n", last_list(first)->data);

          printf("---------------\n");
          struct list *first1 = create_list();
          int i;
          for (i = 0; i < 10; i++)
          {
                    insert_list(first1, 0, i);
          }

          merge_list(first, first1);
          traverse(first);

          return 0;
}
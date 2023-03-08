#include <stdio.h>

struct student
{
          char name[100];
          int age;
};

void print_student(const struct student s) //一般来将，不把结构体变量作为函数的参数
{
          printf("name = %s, age = %d\n", s.name, s.age);
}

void set_student(struct student *s, const char *name, int age)
{
          strcpy(s->name, name);
          s->age = age;
}

int main()
{
          struct student st = {"tom", 20};
          set_student(&st, "mike", 100);
          print_student(st);

          struct student st2 = {"Shershon", 28};
          print_student(st2);

          system("pause");
          return 0;
}
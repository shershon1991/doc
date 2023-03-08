#include <iostream>
using namespace std;

class programmer
{
public:
          virtual void getSal() = 0;
};

class junior_programmer : public programmer
{
public:
          junior_programmer(char *name, char *job, int sal)
          {
                    this->name = name;
                    this->job = job;
                    this->sal = sal;
          }
          virtual void getSal()
          {
                    cout << this->name << " " << this->job << " " << this->sal << endl;
          }

private:
          char *name;
          char *job;
          int sal;
};

class mid_programmer : public programmer
{
public:
          mid_programmer(char *name, char *job, int sal)
          {
                    this->name = name;
                    this->job = job;
                    this->sal = sal;
          }
          virtual void getSal()
          {
                    cout << this->name << " " << this->job << " " << this->sal << endl;
          }

private:
          char *name;
          char *job;
          int sal;
};

class adv_programmer : public programmer
{
public:
          adv_programmer(char *name, char *job, int sal)
          {
                    this->name = name;
                    this->job = job;
                    this->sal = sal;
          }
          virtual void getSal()
          {
                    cout << this->name << " " << this->job << " " << this->sal << endl;
          }

private:
          char *name;
          char *job;
          int sal;
};

//计算函数，简单的框架
void calProSal(programmer *base)
{
          base->getSal();
}

void main801()
{
          char name1[] = "张三";
          char name2[] = "李四";
          char name3[] = "王二";
          char *p1 = name1;
          char *p2 = name2;
          char *p3 = name3;

          char level1[] = "初级";
          char level2[] = "中级";
          char level3[] = "高级";
          char *l1 = level1;
          char *l2 = level2;
          char *l3 = level3;

          junior_programmer jp(p1, l1, 4000);
          mid_programmer mp(p2, l2, 8600);
          adv_programmer ap(p3, l3, 15000);

          calProSal(&jp);
          calProSal(&mp);
          calProSal(&ap);

          cout << "hello..." << endl;
          system("pause");
          return;
}

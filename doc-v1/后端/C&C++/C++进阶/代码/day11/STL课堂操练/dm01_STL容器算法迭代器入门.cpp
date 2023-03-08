#include <iostream>
using namespace std;

#include "vector"
#include "algorithm"

//容器中装基本数据类型变量
void main11()
{
          vector<int> v1; //1.容器：把你的元素copy到容器中
          v1.push_back(-1);
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          //1   3   5
          //△
          //2.迭代器：相当于一个指针
          for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << *it << " ";
          }

          //3.算法：算法和迭代器进行无缝地连接
          int num1 = count(v1.begin(), v1.end(), 3);
          cout << "num1: " << num1 << endl;
}

class Teacher
{
public:
          int age;
          char name[64];

          void printT()
          {
                    cout << "age: " << age << endl;
          }
};

//容器中装老师元素
void main12()
{
          Teacher t1, t2, t3;
          t1.age = 31;
          t2.age = 32;
          t3.age = 33;

          vector<Teacher> v1;
          v1.push_back(t1);
          v1.push_back(t2);
          v1.push_back(t3);

          for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << it->age << " ";
          }

          //int num1 = count(v1.begin(), v1.end(), 3);
          //cout << "num1: " << num1 << endl;
          //抛砖：如何求容器中老师结点（年龄=33）的个数
}

//容器中装老师元素
void main13()
{
          Teacher t1, t2, t3;
          t1.age = 31;
          t2.age = 32;
          t3.age = 33;

          Teacher *p1, *p2, *p3;
          p1 = &t1;
          p2 = &t2;
          p3 = &t3;

          vector<Teacher *> v1; //是把t1,t2,t3内存首地址放入到了容器
          v1.push_back(p1);
          v1.push_back(p2);
          v1.push_back(p3);

          for (vector<Teacher *>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << (*it)->age << endl;
          }

          //3.算法 算法和迭代器进行无缝地连接
          //int num1 = count(v1.begin(), v1.end(), 3);
          //cout << "num1: " << num1 << endl;
}

void main101()
{
          //main11();
          //main12();
          main13();

          cout << "hello..." << endl;
          system("pause");
          return;
}

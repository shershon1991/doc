#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "set"

//1.集合 元素唯一 自动排序(默认从小到大) 不能按照[]方式插入元素
//红黑树
//set元素的添加、遍历、删除操作
void main91()
{
          set<int> set1;

          for (int i = 0; i < 5; i++)
          {
                    int tmp = rand();
                    set1.insert(tmp);
          }
          //插入元素（重复元素）
          set1.insert(100);
          set1.insert(100);
          set1.insert(100);

          for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
          {
                    cout << *it << " ";
          }

          //删除集合
          while (!set1.empty())
          {
                    set<int>::iterator it = set1.begin();
                    cout << *it << " ";
                    set1.erase(set1.begin());
          }
}

//对基本的数据类型，set能自动排序
void main92()
{
          set<int> set1;                //从小到大排序（默认）
          set<int, less<int> > set2;    //从小到大排序
          set<int, greater<int> > set3; //从大到小排序

          for (int i = 0; i < 5; i++)
          {
                    int tmp = rand();
                    set3.insert(tmp);
          }

          for (set<int, greater<int> >::iterator it = set3.begin(); it != set3.end(); it++)
          {
                    cout << *it << " ";
          }
}

//对于复杂的数据类型 Teacher Student
class Student
{
public:
          Student(const char *name, int age)
          {
                    strcpy(this->name, name);
                    this->age = age;
          }

public:
          char name[64];
          int age;
};
//仿函数
struct FuncStudent
{
          bool operator()(const Student &left, const Student &right)
          {
                    if (left.age < right.age) //若左边的小，就返回真（按照年龄从小到大排序）
                    {
                              return true;
                    }
                    else
                    {
                              return false;
                    }
          }
};
//仿函数的用法
void main93()
{
          Student s1("s1", 31);
          Student s2("s2", 32);
          Student s3("s3", 55);
          Student s4("s4", 34);
          Student s5("s5", 31);

          set<Student, FuncStudent> set1;
          set1.insert(s1);
          set1.insert(s2);
          set1.insert(s3);
          set1.insert(s4);
          set1.insert(s5); //若两个31岁，能否插入成功？//不能

          //遍历
          for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++)
          {
                    cout << it->age << "\t" << it->name << endl;
          }
}

//typedef pair<iterator, bool> _Pairb;
//如何判断set1.insert函数的返回值
void main94()
{
          Student s1("s1", 31);
          Student s2("s2", 32);
          Student s3("s3", 55);
          Student s4("s4", 34);
          Student s5("s5", 31);

          set<Student, FuncStudent> set1;
          pair<set<Student, FuncStudent>::iterator, bool> pair1 = set1.insert(s1);
          if (pair1.second == true)
          {
                    cout << "插入s1成功" << endl;
          }
          else
          {
                    cout << "插入s1失败" << endl;
          }

          set1.insert(s2);

          pair<set<Student, FuncStudent>::iterator, bool> pair5 = set1.insert(s5); //若两个31岁，能否插入成功？//不能
          if (pair5.second == true)
          {
                    cout << "插入s1成功" << endl;
          }
          else
          {
                    cout << "插入s1失败" << endl;
          }

          //遍历
          for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++)
          {
                    cout << it->age << "\t" << it->name << endl;
          }
}

//find查找 equal_range
//返回结果是pair
void main95()
{
          set<int> set1;

          for (int i = 0; i < 10; i++)
          {
                    set1.insert(i + 1);
          }

          for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
          {
                    cout << *it << " ";
          }
          cout << endl;

          set<int>::iterator it0 = set1.find(5);
          cout << "*it0:" << *it0 << endl;

          int num1 = set1.count(5);
          cout << "num1:" << num1 << endl;

          set<int>::iterator it1 = set1.lower_bound(5); // >=5的元素的迭代器的位置
          cout << "*it1:" << *it1 << endl;

          set<int>::iterator it2 = set1.lower_bound(5); // >=的元素的迭代器的位置
          cout << "*it2:" << *it2 << endl;

          pair<set<int>::iterator, set<int>::iterator> mypair = set1.equal_range(5);
          set<int>::iterator it3 = mypair.first;
          cout << "*it3:" << *it3 << endl; //5

          set<int>::iterator it4 = mypair.second;
          cout << "*it4:" << *it4 << endl; //6
}

void main901()
{
          //main91();
          //main92();
          //main93();
          //main94();
          main95();

          cout << "hello..." << endl;
          system("pause");
          return;
}

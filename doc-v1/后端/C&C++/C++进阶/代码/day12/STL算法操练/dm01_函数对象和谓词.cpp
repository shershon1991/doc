#include <iostream>
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"

//函数对象 类重载了函数调用操作符
template <typename T>
class ShowElemt
{
public:
          ShowElemt()
          {
                    n = 0;
          }
          void operator()(T &t)
          {
                    n++;
                    //printN();
                    cout << t << " ";
          }
          void printN()
          {
                    cout << "n:" << n << endl;
          }

private:
          int n;
};

//函数模板
template <typename T>
void FuncShowElemt(T &t)
{
          cout << t << " ";
}

//普通函数
void FuncShowElemt2(int &t)
{
          cout << t << " ";
}

//函数对象定义
//函数对象和普通函数的区别
void main11()
{
          int a = 10;
          ShowElemt<int> showElemt;
          showElemt(a); //函数对象的()的执行 很像一个函数  //仿函数

          FuncShowElemt<int>(a);
          FuncShowElemt2(a);
}

//函数对象是属于类对象，能突破函数的概念，能保持状态信息
//函数对象的好处
//for_each算法中，函数对象做函数参数
//for_each算法中，函数对象当返回值
void main12()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          for_each(v1.begin(), v1.end(), ShowElemt<int>()); //匿名函数对象 匿名仿函数
          cout << endl;

          for_each(v1.begin(), v1.end(), FuncShowElemt2); //通过回调函数 谁调用for_each谁去填写回调函数的入口

          ShowElemt<int> show1;
          //函数对象做函数参数
          //1.for_each算法的函数对象的传递 是元素的传递，不是引用传递
          for_each(v1.begin(), v1.end(), show1);
          show1.printN();
          cout << "通过for_each算法的返回值来看调用的次数" << endl;
          show1 = for_each(v1.begin(), v1.end(), show1);
          show1.printN();
          //结论：要点：分清楚stl算法返回值是迭代器还是谓词（函数对象），是stl算法入门的重点
}

template <typename T>
class IsDiv
{
public:
          IsDiv(const T &divisor)
          {
                    this->divisor = divisor;
          }
          bool operator()(T &t)
          {
                    return (t % divisor == 0);
          }

private:
          T divisor;
};
void main13()
{
          vector<int> v2;
          for (int i = 10; i < 33; i++)
          {
                    v2.push_back(i);
          }
          int a = 4;
          IsDiv<int> myDiv(a);

          //find_if(v2.begin(), v2.end(), myDiv);

          vector<int>::iterator it;
          it = find_if(v2.begin(), v2.end(), IsDiv<int>(a));
          if (it == v2.end())
          {
                    cout << "容器中没有被4整除的元素" << endl;
          }
          else
          {
                    cout << "第一个被4整除的元素：" << *it << endl;
          }
}

//二元函数对象
template <typename T>
class SumAdd
{
public:
          T operator()(T t1, T t2)
          {
                    return t1 + t2;
          }
};
void main14()
{
          //v1 v2==>v3
          vector<int> v1, v2;
          vector<int> v3;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          v2.push_back(2);
          v2.push_back(4);
          v2.push_back(6);

          v3.resize(10);

          transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

          for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
          {
                    cout << *it << endl;
          }
}

bool MyCompare(const int &a, const int &b)
{
          return a < b; //从小到大
}
void main15()
{
          vector<int> v1(10);

          for (int i = 0; i < 10; i++)
          {
                    int tmp = rand() % 100;
                    v1[i] = tmp;
          }

          for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << *it << " ";
          }
          cout << endl;

          for_each(v1.begin(), v1.end(), FuncShowElemt2);
          cout << endl;

          sort(v1.begin(), v1.end(), MyCompare);
          for_each(v1.begin(), v1.end(), FuncShowElemt2);
}

struct CompareNoCase
{
          bool operator()(const string &str1, const string &str2)
          {
                    string str1_;
                    str1_.resize(str1.size());
                    transform(str1.begin(), str1.end(), str1_.begin(), tolower);

                    string str2_;
                    str2_.resize(str2.size());
                    transform(str2.begin(), str2.end(), str2_.begin(), tolower);

                    return (str1_ < str2_);
          }
};
/*
void main16()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");

	set<string>::iterator it = set1.find("aaA");//find函数默认是区分大小写的
	if (it == set1.end())
	{
		cout << "未查找到aaa" << endl;
	}
	else
	{
		cout << "查找到aaa" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it2 = set2.find("aaA");
	if (it2 == set2.end())
	{
		cout << "未查找到aaa" << endl;
	}
	else
	{
		cout << "查找到aaa" << endl;
	}
}
*/

void main101()
{
          //main11();
          //main12();
          //main13(); //一元谓词
          //main14(); //二元函数对象
          //main15(); //二元谓词
          //main16(); //二元谓词在set集合中的应用

          cout << "hello..." << endl;
          system("pause");
          return;
}

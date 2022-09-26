#include <iostream>
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator"
#include <numeric>

void printV(vector<int> &v)
{
          for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
          {
                    cout << *it << " ";
          }
}

void printList(list<int> &v)
{
          for (list<int>::iterator it = v.begin(); it != v.end(); it++)
          {
                    cout << *it << " ";
          }
}
//一般情况下，for_each使用的函数对象，参数时引用，没有返回值
//transform使用的函数对象，参数一般不使用引用，而且还有返回值
void showElem(int &n)
{
          cout << n << " ";
}

class CMyShow
{
public:
          CMyShow()
          {
                    num = 0;
          }
          void operator()(int &n)
          {
                    num++;
                    cout << n << " ";
          }
          void printNum()
          {
                    cout << "num:" << num << endl;
          }

private:
          int num;
};

void main41_foreach()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          printV(v1);
          cout << endl;

          //函数对象 回调函数的入口地址
          for_each(v1.begin(), v1.end(), showElem);
          cout << endl;

          for_each(v1.begin(), v1.end(), CMyShow());
          cout << endl;

          CMyShow mya;
          CMyShow my1 = for_each(v1.begin(), v1.end(), mya); //给my1初始化
          mya.printNum();                                    //mya和my1是两个不同的对象
          my1.printNum();

          my1 = for_each(v1.begin(), v1.end(), mya); //给my1赋值
          my1.printNum();
}

int increase(int i)
{
          return i + 100;
}
void main42_transform()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          printV(v1);
          cout << endl;

          //transform使用回调函数
          transform(v1.begin(), v1.end(), v1.begin(), increase);
          printV(v1);
          cout << endl;

          //transform使用 预定义的函数对象
          transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
          printV(v1);
          cout << endl;

          //transform使用 函数适配器和函数对象
          list<int> mylist;
          mylist.resize(v1.size());

          transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(), 10));
          printList(mylist);
          cout << endl;

          //transform也可以把运算结果直接输出到屏幕
          transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
}

void main44_adjacent_find()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(2);
          v1.push_back(2);
          v1.push_back(3);
          v1.push_back(5);

          vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
          if (it == v1.end())
          {
                    cout << "没有找到重复的元素" << endl;
          }
          else
          {
                    cout << *it << endl;
          }
          int index = distance(v1.begin(), it);
          cout << index << endl;
}
void main45_binary_search()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);
          v1.push_back(9);

          bool b = binary_search(v1.begin(), v1.end(), 7);
          if (b == true)
          {
                    cout << "找到了" << endl;
          }
          else
          {
                    cout << "未找到" << endl;
          }
}
void main46_count()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(9);

          int num = count(v1.begin(), v1.end(), 7);
          cout << "num:" << num << endl;
}

bool GreaterThree(int iNum)
{
          if (iNum > 3)
          {
                    return true;
          }
          return false;
}
void main46_count_if()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(9);

          int iCount = count_if(v1.begin(), v1.end(), GreaterThree);
          cout << "iCount:" << iCount << endl;
}

void main47_count_if()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(7);
          v1.push_back(9);

          vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
          cout << *it << endl;

          vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), GreaterThree);
          cout << *it2 << endl;
}

void main_merge()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          vector<int> v2;
          v2.push_back(2);
          v2.push_back(4);
          v2.push_back(6);

          vector<int> v3;
          v3.resize(v1.size() + v2.size());

          merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

          printV(v3);
}

class Student
{
public:
          Student(string name, int id)
          {
                    m_name = name;
                    m_id = id;
          }
          void printT()
          {
                    cout << "name:" << m_name << ", id:" << m_id << endl;
          }

public:
          string m_name;
          int m_id;
};
bool compareS(Student &s1, Student &s2)
{
          return (s1.m_id < s2.m_id);
}
void main_sort()
{
          Student s1("laoda", 1);
          Student s2("laoer", 2);
          Student s3("laosan", 3);
          Student s4("laosi", 4);
          Student s5("laowu", 5);

          vector<Student> v1;
          v1.push_back(s4);
          v1.push_back(s1);
          v1.push_back(s3);
          v1.push_back(s2);
          v1.push_back(s5);

          cout << "排序前：";
          for (vector<Student>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    it->printT();
          }

          cout << "排序后：";
          //sort根据自定义函数对象，进行自定义数据类型的排序
          //替换 算法的统一性（实现算法和数据类型的分离） ===》 技术手段函数对象
          sort(v1.begin(), v1.end(), compareS);
          for (vector<Student>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    it->printT();
          }
}

void main_random_shuffle()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);

          random_shuffle(v1.begin(), v1.end());
          printV(v1);
          cout << endl;

          string str = "abcdefg";
          random_shuffle(str.begin(), str.end());
          cout << "str:" << str << endl;
}

void main_reverse()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);

          reverse(v1.begin(), v1.end());
          printV(v1);
}

void main_copy()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);

          vector<int> v2;
          v2.resize(v1.size());

          copy(v1.begin(), v1.end(), v2.begin());
          printV(v2);
}

bool great_equal_5(int num)
{
          if (num >= 5)
          {
                    return true;
          }
          return false;
}
void main_replace_replaceif()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);
          v1.push_back(3);
          v1.push_back(3);

          replace(v1.begin(), v1.end(), 3, 8);
          printV(v1);
          cout << endl;

          replace_if(v1.begin(), v1.end(), great_equal_5, 2);
          printV(v1);
}

void main_swap()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          vector<int> v2;
          v2.push_back(2);
          v2.push_back(4);
          v2.push_back(6);

          swap(v1, v2);
          printV(v1);
}

void main_accumulate()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          int tmp = accumulate(v1.begin(), v1.end(), 100);
          cout << tmp << endl;
}

void main_fill()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          fill(v1.begin(), v1.end(), 8);
          printV(v1);
}

void main_union()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);

          vector<int> v2;
          v2.push_back(2);
          v2.push_back(4);
          v2.push_back(6);

          vector<int> v3;
          v3.resize(v1.size() + v2.size());

          set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
          printV(v3);
}
void main401()
{
          //main41_foreach();
          //main42_transform();
          //main44_adjacent_find();
          //main45_binary_search();
          //main46_count();
          //main46_count_if();
          //main47_count_if();

          //main_merge();
          //main_sort();
          //main_random_shuffle();
          //main_reverse();

          //main_copy();
          //main_replace_replaceif();
          //main_swap();

          //main_accumulate();
          //main_fill();

          main_union();

          cout << "hello..." << endl;
          system("pause");
          return;
}

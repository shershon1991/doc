#include <iostream>
using namespace std;
#include "vector"

//数组元素的添加，删除
void main31()
{
          vector<int> v1;
          cout << "length:" << v1.size() << endl;

          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          cout << "length:" << v1.size() << endl;

          cout << "头部元素：" << v1.front() << endl; //获取头部元素

          //修改头部元素的值
          //函数返回值当左值，应该返回一个引用
          v1.front() = 11;
          v1.back() = 55;

          while (v1.size() > 0)
          {
                    cout << "尾部元素：" << v1.back(); //获取尾部元素
                    v1.pop_back();                     //删除尾部元素
          }
}

//vector初始化
void main32()
{
          vector<int> v1;
          v1.push_back(1);
          v1.push_back(3);
          v1.push_back(5);
          v1.push_back(7);

          vector<int> v2 = v1;

          vector<int> v3(v1.begin(), v1.begin() + 2);
}

void printV(vector<int> &v)
{
          for (int i = 0; i < v.size(); i++)
          {
                    cout << v[i] << " ";
          }
}

//vector的遍历，通过数组的方式
void main33()
{
          vector<int> v1(10); //提前把内存准备好

          for (int i = 0; i < 10; i++)
          {
                    v1[i] = i + 1;
          }

          /*
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", v1[i]);
	}
	*/

          printV(v1);
}

//push_back的强化记忆
void main34()
{
          vector<int> v1(10); //提前把内存准备好
          v1.push_back(100);
          v1.push_back(200);

          cout << "size:" << v1.size() << endl;
          printV(v1);
}

void main35()
{
          vector<int> v1(10);
          for (int i = 0; i < 10; i++)
          {
                    v1[i] = i + 1;
          }
          //正序遍历
          for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << *it << " ";
          }
          //逆序遍历
          for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++)
          {
                    cout << *rit << " ";
          }
}

//vector删除
void main36()
{
          vector<int> v1(10);
          for (int i = 0; i < 10; i++)
          {
                    v1[i] = i + 1;
          }
          //区间删除
          v1.erase(v1.begin(), v1.begin() + 3);
          printV(v1);

          //根据元素的位置 指定位置删除
          v1.erase(v1.begin()); //在头部删除一个元素

          cout << endl;

          //根据元素的值
          v1[1] = 2;
          v1[3] = 2;
          printV(v1);

          for (vector<int>::iterator it = v1.begin(); it != v1.end();)
          {
                    if (*it == 2)
                    {
                              it = v1.erase(it); //当删除迭代器所指向的元素的时候，erase删除函数会让it自动下移
                    }
                    else
                    {
                              it++;
                    }
          }
          printV(v1);

          cout << endl;
          v1.insert(v1.begin(), 100);
          v1.insert(v1.end(), 200);
          printV(v1);
}

void main301()
{
          //main31();
          //main32();
          //main33();
          //main34();
          //main35();
          main36();

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;
#include "map"
#include "string"

//map元素的添加、遍历、删除等基本操作
void main111()
{
          map<int, string> map1;

          //方法1
          map1.insert(pair<int, string>(1, "teacher01"));
          map1.insert(pair<int, string>(2, "teacher02"));

          //方法2
          map1.insert(make_pair(3, "teacher03"));
          map1.insert(make_pair(4, "teacher04"));

          //方法3
          map1.insert(map<int, string>::value_type(5, "teacher05"));
          map1.insert(map<int, string>::value_type(6, "teacher06"));

          //方法4
          map1[7] = "teacher07";
          map1[8] = "teacher08";

          //容器的遍历
          for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
          {
                    cout << it->first << "\t" << it->second << endl;
          }
          cout << "遍历结果" << endl;

          //容器的删除
          while (!map1.empty())
          {
                    map<int, string>::iterator it = map1.begin();
                    cout << it->first << "\t" << it->second << endl;
                    map1.erase(it);
          }
}

//插入的四种方法的异同
//前三种方法返回的是pair<iterator,bool> 若key已经存在，则报错
//方法四								若key已经存在，则修改
void main112()
{
          map<int, string> map1;

          //方法1
          pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
          map1.insert(pair<int, string>(2, "teacher02"));

          //方法2
          pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher03"));
          map1.insert(make_pair(4, "teacher04"));

          //方法3
          pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(5, "teacher05"));
          //mypair5.first;
          if (mypair5.second != true)
          {
                    cout << "key5插入失败" << endl;
          }
          else
          {
                    cout << mypair5.first->first << "\t" << mypair5.first->second << endl;
          }

          pair<map<int, string>::iterator, bool> mypair6 = map1.insert(map<int, string>::value_type(5, "teacher06"));
          if (mypair6.second != true)
          {
                    cout << "key5插入失败" << endl;
          }
          else
          {
                    cout << mypair6.first->first << "\t" << mypair6.first->second << endl;
          }

          //方法4
          map1[7] = "teacher07";
          map1[7] = "teacher08";

          //容器的遍历
          for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
          {
                    cout << it->first << "\t" << it->second << endl;
          }
          cout << "遍历结果" << endl;
}

void main113()
{
          map<int, string> map1;

          //方法1
          map1.insert(pair<int, string>(1, "teacher01"));
          map1.insert(pair<int, string>(2, "teacher02"));

          //方法2
          map1.insert(make_pair(3, "teacher03"));
          map1.insert(make_pair(4, "teacher04"));

          //方法3
          map1.insert(map<int, string>::value_type(5, "teacher05"));
          map1.insert(map<int, string>::value_type(6, "teacher06"));

          //方法4
          map1[7] = "teacher07";
          map1[8] = "teacher08";

          //容器的遍历
          for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
          {
                    cout << it->first << "\t" << it->second << endl;
          }
          cout << "遍历结果" << endl;

          //map的查找 //异常处理
          map<int, string>::iterator it2 = map1.find(100);
          if (it2 == map1.end())
          {
                    cout << "key 100的值不存在" << endl;
          }
          else
          {
                    cout << it2->first << "\t" << it2->second << endl;
          }

          //equal_range //异常处理
          pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5);
          //第一个迭代器 >= 5的迭代器的位置
          //第二个是>5的位置
          if (mypair.first == map1.end())
          {
                    cout << "第一个迭代器 >= 5的迭代器的位置不存在" << endl;
          }
          else
          {
                    cout << mypair.first->first << "\t" << mypair.first->second << endl;
          }

          if (mypair.second == map1.end())
          {
                    cout << "第二个迭代器 > 5的迭代器的位置不存在" << endl;
          }
          else
          {
                    cout << mypair.first->first << "\t" << mypair.first->second << endl;
          }
}

void main1101()
{
          //main111();
          //main112();
          main113();

          cout << "hello..." << endl;
          system("pause");
          return;
}

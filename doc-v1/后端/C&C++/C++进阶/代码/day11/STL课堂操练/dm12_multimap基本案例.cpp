#include <iostream>
using namespace std;
#include "map"
#include "string"

class Person
{
public:
          string name;
          int age;
          string tel;
          double saly;
};

void main121()
{
          Person p1, p2, p3, p4, p5;
          p1.name = "wang1";
          p1.age = 31;
          p2.name = "wang2";
          p3.age = 32;
          p3.name = "zhang3";
          p3.age = 33;
          p4.name = "zhang4";
          p4.age = 34;
          p5.name = "zhao5";
          p5.age = 35;

          multimap<string, Person> map2;
          //sale部门
          map2.insert(make_pair("sale", p1));
          map2.insert(make_pair("sale", p2));
          //development部门
          map2.insert(make_pair("development", p3));
          map2.insert(make_pair("development", p4));
          //财务部
          map2.insert(make_pair("financial", p5));

          for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
          {
                    cout << it->first << "\t" << it->second.name << endl;
          }
          cout << "遍历结束";

          //
          int num2 = map2.count("development");
          cout << "development部门人数：" << num2 << endl;

          cout << "development部门员工信息：" << endl;
          multimap<string, Person>::iterator it2 = map2.find("development");
          int tag = 0;
          while (it2 != map2.end() && tag < num2)
          {
                    cout << it2->first << "\t" << it2->second.name << endl;
                    it2++;
                    tag++;
          }
}

//将age=32修改为name32
void main122()
{
          Person p1, p2, p3, p4, p5;
          p1.name = "wang1";
          p1.age = 31;
          p2.name = "wang2";
          p2.age = 32;
          p3.name = "zhang3";
          p3.age = 33;
          p4.name = "zhang4";
          p4.age = 34;
          p5.name = "zhao5";
          p5.age = 35;

          multimap<string, Person> map2;
          //sale部门
          map2.insert(make_pair("sale", p1));
          map2.insert(make_pair("sale", p2));
          //development部门
          map2.insert(make_pair("development", p3));
          map2.insert(make_pair("development", p4));
          //财务部
          map2.insert(make_pair("financial", p5));

          cout << "\n按照条件检索数据，进行修改" << endl;
          for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
          {
                    if (it->second.age == 32)
                    {
                              it->second.name = "name32";
                    }
          }
          cout << "遍历结束" << endl;

          for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
          {
                    cout << it->first << "\t" << it->second.name << endl;
          }
}

void main1201()
{
          //main121();
          main122();

          cout << "hello..." << endl;
          system("pause");
          return;
}

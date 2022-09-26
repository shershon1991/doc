#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "fstream"

void main901()
{
          const char *fname = "C:/222aaa.txt";
          ofstream fout(fname, ios::app); //建立一个输出流，和文件进行关联
          if (!fout)
          {
                    cout << "打开文件失败" << endl;
                    system("pause");
                    return;
          }
          fout << "hello...111" << endl;
          fout << "hello...222" << endl;
          fout << "hello...333" << endl;
          fout.close();

          //读文件
          ifstream fin(fname); //建立了一个输入流和文件关联
          char ch;
          while (fin.get(ch))
          {
                    cout << ch;
          }
          fin.close();

          cout << "hello..." << endl;
          system("pause");
          return;
}

class Teacher
{
public:
          Teacher()
          {
                    age = 33;
                    strcpy(name, "");
          }
          Teacher(int _age, const char *_name)
          {
                    age = _age;
                    strcpy(name, _name);
          }
          void printT()
          {
                    cout << "age:" << age << ", name:" << name << endl;
          }

private:
          int age;
          char name[32];
};

void main902()
{
          const char *fname = "C:/1.dat";
          ofstream fout(fname, ios::binary);
          if (!fout)
          {
                    cout << "打开文件失败" << endl;
                    system("pause");
                    return;
          }

          Teacher t1(31, "t31");
          Teacher t2(32, "t32");
          fout.write((char *)&t1, sizeof(t1));
          fout.write((char *)&t2, sizeof(t2));
          fout.close();

          ifstream fin(fname);
          Teacher tmp;

          fin.read((char *)&tmp, sizeof(Teacher));
          tmp.printT();

          fin.read((char *)&tmp, sizeof(Teacher));
          tmp.printT();

          fin.close();

          system("pause");
          return;
}
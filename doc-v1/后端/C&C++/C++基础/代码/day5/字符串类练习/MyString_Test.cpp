#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "MyString.h"

void main01()
{
          MyString s1;
          MyString s2("s2");
          MyString s2_2 = NULL;
          MyString s3 = s2;
          MyString s4 = "dsadasadsadas";

          //= [] << 重载
          s4 = s2;      //MyString& operator=(const MyString &s)
          s4 = "s2222"; //MyString& operator=(const char *p)
          s4[1] = '4';  //char& operator[](int index)
          printf("%c", s4[1]);

          cout << s4 << endl; //ostream& operator<<(ostream &out, MyString &s)

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main02()
{
          MyString s1;
          MyString s2("s2");
          MyString s3 = s2;

          if (s2 == "s2222") //bool operator==(const char *p)
          {
                    printf("相等");
          }
          else
          {
                    printf("不相等");
          }

          if (s3 == s2) //bool operator==(const MyString &p)
          {
                    printf("相等");
          }
          else
          {
                    printf("不相等");
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main03()
{
          MyString s1;
          MyString s2("s2");
          MyString s3 = s2;

          s3 = "aaa";

          //int operator<(const char *p);
          //int operator>(const char *p);
          //int operator<(const MyString &s);
          //int operator>(const MyString &s);
          int tag = (s3 < "bbbb");
          if (tag < 0)
          {
                    printf("s3 < bbbb");
          }
          else
          {
                    printf("s3 > bbbb");
          }

          int tag2 = (s3 < s2);
          if (tag2 < 0)
          {
                    printf("s3 < s2");
          }
          else
          {
                    printf("s3 > s2");
          }

          MyString s4 = "aaaaffff";
          strcpy(s4.c_str(), "aa11"); //MFC
          cout << s4 << endl;

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main()
{
          MyString s1(128);
          cout << "\n请输入字符串（回车结束）";
          cin >> s1;
          //istream& operator>>(istream &in, MyString &s)

          cout << s1 << endl;

          system("pause");
          return;
}
#include <iostream>
using namespace std;

void main701()
{
          char myBuf[1024];
          int myInt;
          long myLong;

          cin >> myInt;
          cin >> myLong;
          cin >> myBuf; //遇见空格，停止接收数据
          cout << "myInt:" << myInt << ", myLong:" << myLong << ", myBuf:" << myBuf << endl;

          system("pause");
          return;
}

void main702()
{
          char ch;
          while ((ch = cin.get()) != EOF)
          {
                    cout << ch << endl;
          }

          system("pause");
          return;
}

void main703()
{
          char a, b, c;

          cout << "cin.get(a)若缓冲区没有数据，则程序阻塞 \n";
          cin.get(a);
          cin.get(b);
          cin.get(c);
          cout << a << b << c << "若缓冲区有数据，则程序不会阻塞 \n";

          cin.get(a).get(b).get(c);
          cout << a << b << c;

          system("pause");
          return;
}

void main704()
{
          char buf1[256];
          char buf2[256];

          cout << "请输入一个字符串，含有多个空格 \n";

          cin >> buf1;
          cin.getline(buf2, 256);
          cout << "buf1:" << buf1 << ",buf2:" << buf2 << endl;

          system("pause");
          return;
}

void main705()
{
          char buf1[256];
          char buf2[256];

          cout << "请输入一个字符串，含有多个空格 aa  bbccdd\n";

          cin >> buf1;
          cin.ignore(2);

          int myint = cin.peek();
          cout << "myint:" << myint << endl;

          cin.getline(buf2, 256);
          cout << "buf1:" << buf1 << ",buf2:" << buf2 << endl;

          system("pause");
          return;
}
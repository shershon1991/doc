#include <iostream>
using namespace std;
#include "string"
#include "algorithm"

//string的初始化
void main21()
{
          string s1 = "aaaaa";
          string s2("bbbbb");
          string s3 = s2; //通过copy构造函数类初始化对象s3
          string s4(10, 'a');

          cout << "s1:" << s1 << endl;
          cout << "s2:" << s2 << endl;
          cout << "s3:" << s3 << endl;
          cout << "s4:" << s4 << endl;
}

//string的遍历
void main22()
{
          string s1 = "abcdefg";

          //1.数组方式
          for (int i = 0; i < s1.length(); i++)
          {
                    cout << s1[i] << " ";
          }
          cout << endl;

          //2.迭代器
          for (string::iterator it = s1.begin(); it != s1.end(); it++)
          {
                    cout << *it << " ";
          }
          cout << endl;

          try
          {
                    for (int i = 0; i < s1.length() + 3; i++)
                    {
                              cout << s1.at(i) << " "; //抛异常
                    }
          }
          catch (...)
          {
                    cout << "发生异常" << endl;
          }

          /*
	try
	{
		for (int i = 0; i < s1.length()+3; i++)
		{
			cout << s1[i] << " "; //发生异常，不向外面抛异常，引起程序的中断 
		}
	}
	catch (...)
	{
		cout << "发生异常" << endl;
	}
	*/
}

//字符指针和string的转换
void main23()
{
          string s1 = "aaabbb";

          //1.s1 ===> char *
          printf("s1:%s \n", s1.c_str());

          //2.char * ===> string

          //3 s1的内容拷贝到buf
          char buf1[128] = {0};
          s1.copy(buf1, 3, 0); //注意：只会拷贝3个字符，不会变成C风格的字符串
          cout << "buf1:" << buf1 << endl;
}

//字符串的连接
void main24()
{
          string s1 = "aaa";
          string s2 = "bbbb";
          s1 = s1 + s2;
          cout << "s1:" << s1 << endl;

          string s3 = "333";
          string s4 = "4444";
          s3.append(s4);
          cout << "s3:" << s3 << endl;
}

//字符串的查找和替换
void main25()
{
          string s1 = "shershon hello 111 hello 222";

          //第一次出现hello的index
          int index = s1.find("hello", 0); //位置下标从0开始
          cout << "index:" << index << endl;

          //案例1：求hello出现的次数及每一次出现的数组下标
          int offindex = s1.find("hello", 0);
          while (offindex != string::npos)
          {
                    cout << "offindex:" << offindex << endl;
                    offindex = offindex + 1;
                    offindex = s1.find("hello", offindex);
          }

          //案例2：把小写的hello换成大写
          int offindex2 = s1.find("hello", 0);
          while (offindex2 != string::npos)
          {
                    cout << "offindex2:" << offindex2 << endl;
                    s1.replace(offindex2, 5, "HELLO");
                    offindex2 = offindex2 + 1;
                    offindex2 = s1.find("hello", offindex2);
          }

          cout << "s1替换后的结果：" << s1 << endl;
}

//截断（区间删除）和插入
void main26()
{
          string s1 = "hello1 hello2 hello3";
          string::iterator it = find(s1.begin(), s1.end(), 'l');
          if (it != s1.end())
          {
                    s1.erase(it);
          }
          cout << "s1删除l以后的结果：" << s1 << endl;

          string s2 = "BBB";
          s2.insert(0, "AAA"); //头插法
          s2.insert(s2.length(), "CCC");
          cout << "s2:" << s2 << endl;
}

void main27()
{
          string s1 = "AAAbbb";
          //1函数的入口地址 2函数对象 3预定义的函数对象
          transform(s1.begin(), s1.end(), s1.begin(), toupper);
          cout << "s2:" << s1 << endl;

          string s2 = "AAAbbb";
          transform(s2.begin(), s2.end(), s2.begin(), tolower);
          cout << "s2:" << s2 << endl;
}

void main()
{
          //main21();
          //main22();
          //main23();
          //main24();
          //main25();
          //main26();
          main27();

          cout << "hello..." << endl;
          system("pause");
          return;
}

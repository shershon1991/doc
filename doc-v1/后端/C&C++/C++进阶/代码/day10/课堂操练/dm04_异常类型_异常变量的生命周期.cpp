#include <iostream>
using namespace std;

class BadSrcType
{
};

class BadDestType
{
};

class BadProcessType
{
public:
          BadProcessType()
          {
                    cout << "BadProcessType构造函数\n";
          }
          BadProcessType(const BadProcessType &obj)
          {
                    cout << "BadProcessType copy构造函数\n";
          }
          ~BadProcessType()
          {
                    cout << "BadProcessType析构函数\n";
          }
};

//throw 类对象类型异常
void my_strcpy404(char *to, char *from)
{
          if (from == NULL)
          {
                    throw BadSrcType();
          }
          if (to == NULL)
          {
                    throw BadDestType();
          }
          if (*from == 'a')
          {
                    throw BadProcessType(); //会不会产生一个匿名对象？
          }
          if (*from == 'b')
          {
                    throw &(BadProcessType());
          }
          if (*from == 'c')
          {
                    throw new BadProcessType();
          }
          while (*from != '\0')
          {
                    *to = *from;
                    to++;
                    from++;
          }
          *to = '\0';
}

void main404()
{
          int ret = 0;
          char buf1[] = "cbcdefg";
          char buf2[1024] = {0};

          try
          {
                    my_strcpy404(buf2, buf1);
          }
          catch (int a)
          {
                    cout << a << "捕获int类型异常\n";
          }
          catch (char *e)
          {
                    cout << e << ",捕获char *类型异常\n";
          }
          catch (BadSrcType e)
          {
                    cout << "捕获BadSrcType类型异常\n";
          }
          catch (BadDestType e)
          {
                    cout << "捕获BadDestType类型异常\n";
          }
          //1.结论：若接收异常时，使用一个异常变量，则拷贝构造异常变量
          /*
	catch (BadProcessType e)//是把匿名对象copy给e
	{
		cout << "捕获BadProcessType类型异常\n";
	} 
	*/
          //2.结论：使用引用的话，会使用throw时的那个对象
          /*
	catch (BadProcessType &e)//是把匿名对象copy给e
	{
		cout << "捕获BadProcessType类型异常\n";
	}
	*/
          //3.结论：指针可以和引用、元素写在一块，但是元素和引用不能写在一块
          catch (BadProcessType *e) //是把匿名对象copy给e
          {
                    delete e;
                    cout << "捕获BadProcessType类型异常\n";
          }
          //4.结论：类对象时，使用引用是比较合适的
          catch (...)
          {
                    cout << "捕获未知类型异常\n";
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

//throw char*类型异常
void my_strcpy403(char *to, char *from)
{
          if (from == NULL)
          {
                    throw "源buf出错";
          }
          if (to == NULL)
          {
                    throw "目的buf出错";
          }
          if (*from == 'a')
          {
                    printf("开始BadProcessType类型异常 \n");
                    throw(char *) "copy过程出错";
          }
          while (*from != '\0')
          {
                    *to = *from;
                    to++;
                    from++;
          }
          *to = '\0';
}

void main403()
{
          int ret = 0;
          char buf1[] = "abcdefg";
          char buf2[1024] = {0};

          try
          {
                    my_strcpy403(buf2, buf1);
          }
          catch (int a)
          {
                    cout << a << "捕获int类型异常\n";
          }
          catch (char *e)
          {
                    cout << e << ",捕获char *类型异常\n";
          }
          catch (...)
          {
                    cout << "捕获未知异常\n";
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

//throw int类型异常
void my_strcpy402(char *to, char *from)
{
          if (from == NULL)
          {
                    throw 1;
          }
          if (to == NULL)
          {
                    throw 2;
          }
          if (*from == 'a')
          {
                    throw 3;
          }
          while (*from != '\0')
          {
                    *to = *from;
                    to++;
                    from++;
          }
          *to = '\0';
}

void main402()
{
          int ret = 0;
          char buf1[] = "abcdefg";
          char buf2[1024] = {0};

          try
          {
                    my_strcpy402(buf2, buf1);
          }
          catch (int a) //a可以写，也可以不写
          {
                    cout << a << "捕获int类型异常\n";
          }
          catch (...)
          {
                    cout << "捕获未知异常\n";
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

//传统异常处理
int my_strcpy401(char *to, char *from)
{
          if (from == NULL)
          {
                    return 1;
          }
          if (to == NULL)
          {
                    return 2;
          }
          if (*from == 'a')
          {
                    return 3;
          }
          while (*from != '\0')
          {
                    *to = *from;
                    to++;
                    from++;
          }
          *to = '\0';
          return 0;
}

void main401()
{
          int ret = 0;
          char buf1[] = "zbcdefg";
          char buf2[1024] = {0};

          ret = my_strcpy401(buf2, buf1);
          if (ret != 0)
          {
                    switch (ret)
                    {
                    case 1:
                              printf("1号出错！\n");
                              break;
                    case 2:
                              printf("2号出错！\n");
                              break;
                    case 3:
                              printf("3号出错！\n");
                              break;
                    default:
                              printf("未知错误！\n");
                              break;
                    }
          }
          printf("buf2:%s \n", buf2);

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;
#include "windows.h"
#include "winbase.h"
#include <process.h>

class Singleton2
{
private:
          //1.构造函数私有化
          //C++的构造函数不能保证是线程安全的
          Singleton2()
          {
                    m_num++;
                    printf("Singleton2 begin\n");
                    Sleep(1000);
                    printf("Singleton2 end\n");
          }

public:
          static void printS()
          {
                    printf("m_num:%d \n", m_num);
          }
          //2.提供全局访问点
          static Singleton2 *GetSingleton2()
          {
                    return single;
          }

private:
          static Singleton2 *single;
          static int m_num;
};

//Singleton2* Singleton2::single = new Singleton2;
Singleton2 *Singleton2::single = NULL;
int Singleton2::m_num = 0;

void main201()
{
          //只有我们调用GetSingleton2时，类才会new出对象，在new对象实例时多判断 ===> 懒汉式
          Singleton2 *s1 = Singleton2::GetSingleton2();
          Singleton2 *s2 = Singleton2::GetSingleton2();

          if (s1 == s2)
          {
                    cout << "s1 == s2" << endl;
          }
          else
          {
                    cout << "s1 != s2" << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

void threadFunc2(void *p)
{
          DWORD id = GetCurrentThreadId();
          Singleton2::GetSingleton2()->printS();
          printf("id:%d \n", id);
          return;
}

void main202()
{
          int i = 0;
          int threadnum = 3;
          HANDLE hThread[100];

          for (i = 0; i < threadnum; i++)
          {
                    hThread[i] = (HANDLE)_beginthread(threadFunc2, 0, NULL);
          }

          for (i = 0; i < threadnum; i++) //让主进程等待所有子线程运行完毕
          {
                    WaitForSingleObject(hThread[i], INFINITE);
          }
          printf("main \n");

          system("pause");
}

#include <iostream>
using namespace std;
#include "windows.h"
#include "winbase.h"
#include <process.h>

class Singleton
{
private:
          //1.构造函数私有化
          //C++的构造函数不能保证是线程安全的
          Singleton()
          {
                    m_num++;
                    printf("Singleton begin\n");
                    Sleep(1000);
                    printf("Singleton end\n");
          }

public:
          static void printS()
          {
                    printf("m_num:%d \n", m_num);
          }
          //2.提供全局访问点
          static Singleton *GetSingleton()
          {
                    if (single == NULL)
                    {
                              single = new Singleton;
                    }
                    return single;
          }

private:
          static Singleton *single;
          static int m_num;
};

Singleton *Singleton::single = NULL;
int Singleton::m_num = 0;

void main101()
{
          //只有我们调用GetSingleton时，类才会new出对象，在new对象实例时多判断 ===> 懒汉式
          Singleton *s1 = Singleton::GetSingleton();
          Singleton *s2 = Singleton::GetSingleton();

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

void threadFunc(void *p)
{
          DWORD id = GetCurrentThreadId();
          Singleton::GetSingleton()->printS();
          printf("id:%d \n", id);
          return;
}

void main102()
{
          int i = 0;
          int threadnum = 3;
          HANDLE hThread[100];

          for (i = 0; i < threadnum; i++)
          {
                    hThread[i] = (HANDLE)_beginthread(threadFunc, 0, NULL);
          }

          for (i = 0; i < threadnum; i++) //让主进程等待所有子线程运行完毕
          {
                    WaitForSingleObject(hThread[i], INFINITE);
          }
          printf("main \n");

          system("pause");
}

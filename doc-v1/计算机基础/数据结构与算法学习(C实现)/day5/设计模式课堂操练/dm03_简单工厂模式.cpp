#include <iostream>
using namespace std;

class Friut
{
public:
          virtual void getFriut()
          {
                    cout << "Friut:getFriut" << endl;
          }
};

class Pear : public Friut
{
public:
          virtual void getFriut() //采集水果
          {
                    cout << "Pear:getFriut" << endl;
          }
};

class Banana : public Friut
{
public:
          virtual void getFriut() //采集水果
          {
                    cout << "Banana:getFriut" << endl;
          }
};

//依赖
class Factory
{
public:
          Friut *Create(const char *name) //简单工厂的创建工作 业务逻辑集中在这里
          {
                    if (strcmp(name, "Pear") == 0)
                    {
                              return new Pear;
                    }
                    else if (strcmp(name, "Banana") == 0)
                    {
                              return new Banana;
                    }
                    else
                    {
                              return NULL;
                    }
          }
};

void main301()
{
          Factory *ff = NULL;
          Friut *friut = NULL;

          ff = new Factory;

          friut = ff->Create("Pear");
          friut->getFriut(); //多态成立的三个条件：继承、虚函数重写、父类指针（父类引用）指向子类对象
          delete friut;

          friut = ff->Create("Banana");
          friut->getFriut();
          delete friut;

          cout << "hello..." << endl;
          system("pause");
          return;
}

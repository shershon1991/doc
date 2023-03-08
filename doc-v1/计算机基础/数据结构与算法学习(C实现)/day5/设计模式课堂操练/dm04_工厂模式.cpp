#include <iostream>
using namespace std;

//抽象水果类 Friut
//抽象工厂类 FriutFactory
//具体的工厂类 BananaFactory..
//具体的水果类 Banana..

class Friut2
{
public:
          virtual void sayName()
          {
                    cout << "Friut2 " << endl;
          }
};

//抽象工厂和一般的工厂模式相比较，区别是：产品的细化。。。
class Friut2Factory
{
public:
          virtual Friut2 *getFriut2()
          {
                    cout << "Friut2Factory:getFriut2 " << endl;
                    return NULL;
          }
};

class Banana2 : public Friut2
{
public:
          virtual void sayName()
          {
                    cout << "我是香蕉 " << endl;
          }
};

class Pear2 : public Friut2
{
public:
          virtual void sayName()
          {
                    cout << "我是梨子 " << endl;
          }
};

class BananaFactory : public Friut2Factory
{
public:
          virtual Friut2 *getFriut2()
          {
                    return new Banana2;
          }
};

class PearFactory : public Friut2Factory
{
public:
          virtual Friut2 *getFriut2()
          {
                    return new Pear2;
          }
};

void main401()
{
          Friut2Factory *ff = NULL;
          Friut2 *friut = NULL;

          ff = new BananaFactory;
          friut = ff->getFriut2();
          friut->sayName();
          delete ff;
          delete friut;

          ff = new PearFactory;
          friut = ff->getFriut2();
          friut->sayName();
          delete ff;
          delete friut;

          cout << "hello..." << endl;
          system("pause");
          return;
}

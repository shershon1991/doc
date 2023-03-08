#include <iostream>
using namespace std;

class Friut3
{
public:
          virtual void sayName()
          {
                    cout << "Friut2 " << endl;
          }
};

//抽象工厂和一般的工厂模式相比较，区别是：产品的细化。。。
class Friut3Factory
{
public:
          virtual Friut3 *getBanana()
          {
                    cout << "Friut3Factory:getBanana " << endl;
                    return NULL;
          }
          virtual Friut3 *getApple()
          {
                    cout << "Friut3Factory:getApple " << endl;
                    return NULL;
          }
          virtual Friut3 *getMg()
          {
                    cout << "Friut3Factory:getMg " << endl;
                    return NULL;
          }
};

//南方香蕉
class SouthBanana : public Friut3
{
public:
          virtual void sayName()
          {
                    cout << "SouthBanana " << endl;
          }
};

// 北方香蕉
class NorthBanana : public Friut3
{
public:
          virtual void sayName()
          {
                    cout << "NorthBanana " << endl;
          }
};

//南方苹果
class SouthApple : public Friut3
{
public:
          virtual void sayName()
          {
                    cout << "SouthApple " << endl;
          }
};

// 北方苹果
class NorthApple : public Friut3
{
public:
          virtual void sayName()
          {
                    cout << "NorthApple " << endl;
          }
};

//北方工厂
class NorthFactory : public Friut3Factory
{
public:
          virtual Friut3 *getBanana()
          {
                    return new NorthBanana;
          }
          virtual Friut3 *getApple()
          {
                    return new NorthApple;
          }
          virtual Friut3 *getMg()
          {
                    return NULL;
          }
};

//南方工厂
class SouthFactory : public Friut3Factory
{
public:
          virtual Friut3 *getBanana()
          {
                    return new SouthBanana;
          }
          virtual Friut3 *getApple()
          {
                    return new SouthApple;
          }
          virtual Friut3 *getMg()
          {
                    return NULL;
          }
};

void main501()
{
          Friut3Factory *ff = NULL;
          Friut3 *friut1 = NULL;
          Friut3 *friut2 = NULL;

          //南方工厂
          ff = new SouthFactory;
          friut1 = ff->getApple();
          friut1->sayName();
          friut2 = ff->getBanana();
          friut2->sayName();
          delete friut1;
          delete friut2;

          //北方工厂
          ff = new NorthFactory;
          friut1 = ff->getApple();
          friut1->sayName();
          friut2 = ff->getBanana();
          friut2->sayName();
          delete friut1;
          delete friut2;

          cout << "hello..." << endl;
          system("pause");
          return;
}

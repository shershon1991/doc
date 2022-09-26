#include <iostream>
using namespace std;

//HeroFighter AdvHeroFighter EnemyFighter

class HeroFighter
{
public:
          virtual int power()
          {
                    return 10;
          }
};

class AdvHeroFighter : public HeroFighter
{
public:
          virtual int power()
          {
                    return 20;
          }
};

class AdvAdvHeroFighter : public HeroFighter
{
public:
          virtual int power()
          {
                    return 30;
          }
};

class EnemyFighter
{
public:
          int attack()
          {
                    return 15;
          }
};

void main1301()
{
          HeroFighter hf;
          AdvHeroFighter Advhf;
          EnemyFighter ef;

          if (hf.power() > ef.attack())
          {
                    printf("主角win \n");
          }
          else
          {
                    printf("主角挂掉 \n");
          }

          if (Advhf.power() > ef.attack())
          {
                    printf("升级版主角win \n");
          }
          else
          {
                    printf("升级版主角挂掉 \n");
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

//多态威力
//不写virtual关键字，是静态联编，C++编译器根据HeroFighter类型去执行这个类型的power函数，在编译器编译阶段就已经决定了函数的调用
//动态联编：迟绑定。//在运行的时候，根据具体对象（具体的类型），执行不同对象的函数，表现成多态
void PlayObject(HeroFighter *hf, EnemyFighter *ef)
{
          if (hf->power() > ef->attack()) //hf->power()函数调用会有多态发生
          {
                    printf("主角win \n");
          }
          else
          {
                    printf("主角挂掉 \n");
          }
}

//多面向对象3大思想
//封装：突破了C语言的概念...用类做函数参数时，可以使用对象的属性和对象的方法
//继承：A B 可以复用代码
//多态：可以使用未来...

//C语言里面 间接赋值是指针存在的最大意义
//是C语言特有的现象（1.定义2个变量；2.建立关联；3.*p在被调用函数中间接地修改实参的值）

//实现多态的3个条件
//1.要有继承
//2.要有虚函数重写
//3.用父类指针（父类引用）指向子类对象...

void main1302()
{
          HeroFighter hf;
          AdvHeroFighter Advhf;
          AdvAdvHeroFighter AdvAdvhf;
          EnemyFighter ef;

          PlayObject(&hf, &ef);
          PlayObject(&Advhf, &ef);
          PlayObject(&AdvAdvhf, &ef); //这个框架 能把我们后来人写的代码给调用起来

          system("pause");
          return;
}
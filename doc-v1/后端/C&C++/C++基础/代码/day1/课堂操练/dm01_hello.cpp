#include "iostream"  //包含C++的头文件
using namespace std; //使用命名空间std标准的命名空间（在这个命名空间中定义了很多标准定义）

void main101()
{
          //printf("Hello World \n");

          //cout 标准输出
          //<<左移操作符，在C++里面，功能的改造增强==>C++语言操作符重载
          cout << "Hello World" << endl;
          system("pause");
}
//<< >>用法技巧：标准输入cin和标准输出cout始终写在操作符的左边
//求圆的面积
//1.面向过程的方法
void main102()
{
          double r = 0;
          double s = 0;

          cout << "请输入圆的半径：";

          //cin 标准输入
          cin >> r;
          cout << "r的值为：" << r << endl;

          s = 3.14 * r * r;
          cout << "圆的面积s为：" << s << endl;

          system("pause");
}

//在C++中，定义了一个自定义数据类型
struct Circle
{
          double m_s;
          double m_r;
};

//在C++中，定义了一个自定义数据类型
class MyCircle
{
public:
          double m_s; //圆的面积 属性 成员变量
          double m_r; //圆的半径
public:
          void setR(double r) //成员函数
          {
                    m_r = r;
          }

          double getR() //成员函数
          {
                    return m_r;
          }

          double getS()
          {
                    m_s = 3.14 * m_r * m_r;
                    return m_s;
          }
};

void main103()
{
          MyCircle c1, c2, c3;
          double r;
          cout << "请输入C1圆的半径：";
          cin >> r;

          //给C1圆的属性赋值
          c1.setR(r);

          cout << "C1圆的面积是：" << c1.getS() << endl;

          system("pause");
}

//2.面向对象的方法
//面向过程加工的是 一个一个的函数
//面向对象加工的是 一个一个的类

//思考1：类的调用 执行过程==》类代码不是一步一步地执行
//类是一个数据类型（固定大小内存块的别名），定义一个类，是一个抽象的概念，操作系统不会分配内存，
//用数据类型定义变量的时候，才会分配内存
//思考2：抛砖：C++编译器是如何处理 多个对象，调用类的成员函数的；具体一点，如何区分是c1/c2/c3调用的类的成员函数
void main104()
{
          MyCircle c1, c2, c3;
          double r1, r2, r3;

          //圆形1
          cout << "请输入C1圆的半径r1：";
          cin >> r1;
          //给C1圆的属性赋值
          c1.setR(r1);
          cout << "C1圆的面积是：" << c1.getS() << endl;

          //圆形2
          cout << "请输入C2圆的半径r2：";
          cin >> r2;
          //给C2圆的属性赋值
          c2.setR(r2);
          cout << "C2圆的面积是：" << c2.getS() << endl;

          //圆形3
          cout << "请输入C3圆的半径r3: ";
          cin >> r3;
          //给C3圆的属性赋值
          c3.setR(r3);
          cout << "C3圆的面积是：" << c3.getS() << endl;

          system("pause");
}
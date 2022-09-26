#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
          friend ostream &operator<<<T>(ostream &out, const MyVector &obj);

public:
          MyVector(int size = 0);        //构造函数
          MyVector(const MyVector &obj); //拷贝构造函数
          ~MyVector();                   //析构函数

          T &operator[](int index);
          MyVector &operator=(const MyVector &obj);

          int getLen()
          {
                    return m_len;
          }

private:
          T *m_space;
          int m_len;
};

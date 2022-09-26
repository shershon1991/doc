#include <iostream>
using namespace std;

template <typename T>
class AA
{
public:
          static T m_a;
};

template <typename T>
T AA<T>::m_a = 0;

void main1001()
{
          AA<int> a1, a2, a3;
          a1.m_a = 10;
          a2.m_a++;
          a3.m_a++;
          cout << AA<int>::m_a << endl;

          AA<char> b1, b2, b3;
          b1.m_a = 'a';
          b2.m_a++;
          b2.m_a++;
          cout << AA<char>::m_a << endl;

          //m_a应该是 每一种类型的类使用自己的m_a

          cout << "hello..." << endl;
          system("pause");
          return;
}

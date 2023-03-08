#include <iostream>
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"

//plus<int> 与定义好的函数对象，能实现不同类型的数据的+运算
//实现了数据类型和算法的分离 ==》 通过函数对象技术实现的

//思考：怎么样知道plus<type>是两个参数
void main21()
{
          /*
	template <class _Ty = void>
struct plus { // functor for operator+
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty result_type;

    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const { // apply operator+ to operands
        return _Left + _Right;
    }
};*/
          plus<int> intAdd;
          int x = 10;
          int y = 20;
          int z = intAdd(x, y);
          cout << "z:" << z << endl;

          plus<string> stringAdd;
          string str1 = "aaa";
          string str2 = "bbb";
          string str3 = stringAdd(str1, str2);
          cout << "str3:" << str3 << endl;

          vector<string> v1;
          v1.push_back("bbb");
          v1.push_back("aaa");
          v1.push_back("ccc");
          v1.push_back("zzz");

          sort(v1.begin(), v1.end(), greater<string>());

          for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << *it << endl;
          }

          //求c出现的个数
          string sc = "ccc";

          //equal_to<string>()有两个参数，left来自容器，right来自sc
          //bind2nd函数适配器 作用：把预定义函数对象和第二个参数进行绑定
          int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
          cout << "num:" << num << endl;
}

class IsGreat
{
public:
          IsGreat(int i)
          {
                    m_num = i;
          }
          bool operator()(int &num)
          {
                    if (num > m_num)
                    {
                              return true;
                    }
                    return false;
          }

private:
          int m_num;
};
//函数适配器综合案例
void main22()
{
          vector<int> v1;
          for (int i = 0; i < 10; i++)
          {
                    v1.push_back(i + 1);
          }
          for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
          {
                    cout << *it << " ";
          }
          cout << endl;

          int num1 = count(v1.begin(), v1.end(), 3);
          cout << "num1:" << num1 << endl;

          //通过谓词求大于2的个数
          int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
          cout << "num2:" << num2 << endl;

          //通过预定义的函数对象求大于2的个数
          //greater<int>()有两个参数，做参数来自容器，有参数固定成2（通过bind2nd做的）
          int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
          cout << "num3:" << num3 << endl;

          //求奇数的个数
          int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
          cout << "num4:" << num4 << endl;

          //求偶数的个数
          int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
          cout << "num5:" << num5 << endl;
}

void main201()
{
          //main21();
          main22();

          cout << "hello..." << endl;
          system("pause");
          return;
}

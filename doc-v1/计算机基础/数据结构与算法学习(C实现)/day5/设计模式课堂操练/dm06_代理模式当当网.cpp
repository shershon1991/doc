#include <iostream>
using namespace std;

class BookStore
{
public:
          virtual void sellBook()
          {
                    cout << "BookStore sellbook" << endl;
          }
};

class RealStore : public BookStore
{
public:
          virtual void sellBook()
          {
                    cout << "RealStore sellbook" << endl;
          }
};

class DDProxy : public BookStore
{
public:
          virtual void sellBook()
          {
                    RealStore realstore;
                    doubleEleven();
                    realstore.sellBook(); //实体店卖书
                    cout << "DDProxy sellbook" << endl;
                    doubleEleven();
                    doubleEleven();
                    doubleEleven();
          }
          void doubleEleven()
          {
                    cout << "打折促销" << endl;
          }
};

void main()
{
          DDProxy *ddproxy = new DDProxy;
          ddproxy->sellBook();

          cout << "hello..." << endl;
          system("pause");
          return;
}

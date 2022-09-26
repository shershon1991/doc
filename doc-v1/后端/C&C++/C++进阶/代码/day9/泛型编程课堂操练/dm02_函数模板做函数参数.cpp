#include <iostream>
using namespace std;

//函数模板本质：类型参数化
//对字符数组、int数组排序

template <typename T, typename T2>
int mySort(T *array, T2 size)
{
          T2 i, j;
          T tmp;
          if (array == NULL)
          {
                    return -1;
          }
          for (i = 0; i < size; i++)
          {
                    for (j = i + 1; j < size; j++)
                    {
                              if (array[i] > array[j])
                              {
                                        tmp = array[i];
                                        array[i] = array[j];
                                        array[j] = tmp;
                              }
                    }
          }
          return 0;
}

template <typename T, typename T2>
int myPrint(T *array, T2 size)
{
          T2 i = 0;
          for (i = 0; i < size; i++)
          {
                    cout << array[i] << " ";
          }
          return 0;
}

void main202()
{
          //int类型
          {
                    int myarray[] = {11, 22, 24, 12, 7, 13};

                    int size = sizeof(myarray) / sizeof(myarray[0]);

                    mySort<int, int>(myarray, size);

                    printf("排序之后\n");
                    myPrint<int, int>(myarray, size);
          }

          //char类型
          {
                    printf("\n");
                    char buf[] = "dsadsadsadasdsad";
                    int len = strlen(buf);

                    mySort<char, int>(buf, len);
                    myPrint<char, int>(buf, len);
                    printf("\n");
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int capacity)
{
          //T* pArray;
          //pArray = new char[10]; //char array[10]
          pArray = new T[capacity];
          this->capacity = capacity;
          this->length = 0;
}

template <typename T>
SeqList<T>::~SeqList()
{
          delete[] pArray;
          //pArray = NULL;
          length = 0;
          capacity = 0;
}

template <typename T>
int SeqList<T>::getLen()
{
          return this->length;
}

template <typename T>
int SeqList<T>::getCapacity()
{
          return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T &t, int pos)
{
          int i = 0;
          if (pos < 0)
          {
                    return -1;
          }
          //元素后移
          for (i = length; i > pos; i--)
          {
                    pArray[i] = pArray[i - 1];
          }

          pArray[i] = t; //stl元素保存 是通过复制的机制实现的，你的类需要可以复制才行
          //插入元素
          this->length++;

          return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T &t)
{
          int i = 0;
          if (pos < 0)
          {
                    return -1;
          }
          t = pArray[pos];
          return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t)
{
          int i = 0;
          t = pArray[pos];

          for (i = pos + 1; i < length; i++)
          {
                    pArray[i - 1] = pArray[i];
          }
          length--;
          return 0;
}
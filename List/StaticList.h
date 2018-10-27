#pragma once

const int maxSize = 100;

template <class T>
struct StaticLinkNode
{
  T data;
  int link;
};

template <class T>
class StaticList
{
protected:
  StaticLinkNode<T> elem[maxSize];
  int avil;

public:
  StaticList();
  ~StaticList();
  void InitList();
  int Length();
  int Search();
  int Locate();
  bool Append();
  bool Insert();
  bool Remove();
  bool IsEmpty();
};

template <class T>
StaticList<T>::StaticList()
{
}

template <class T>
StaticList<T>::~StaticList()
{
}

template <class T>
void StaticList<T>::InitList()
{
}

template <class T>
int StaticList<T>::Length()
{
  return 0;
}

template <class T>
int StaticList<T>::Search()
{
  return 0;
}

template <class T>
int StaticList<T>::Locate()
{
  return 0;
}

template <class T>
bool StaticList<T>::Append()
{
  return false;
}

template <class T>
bool StaticList<T>::Insert()
{
  return false;
}

template <class T>
bool StaticList<T>::Remove()
{
  return false;
}

template <class T>
bool StaticList<T>::IsEmpty()
{
  return false;
}

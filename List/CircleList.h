#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct CirLinkNode
{
    T data;
    CirLinkNode<T> *link;
    CirLinkNode(CirLinkNode<T> *ptr = NULL)
    {
        link = ptr;
    }
    CirLinkNode(const T &item, CirLinkNode<T> *ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};

template <class T>
class CircleList
{
  protected:
    CirLinkNode<T> *first, *last;

  public:
    CircleList();
    ~CircleList();
    void makeEmpty();
    int Length() const;
    bool IsEmpty() const;
    CirLinkNode<T> *getHead() const;
    void setHead(CirLinkNode<T> *p);
    CirLinkNode<T> *Search(const T &x);
    CirLinkNode<T> *Locate(int i);
    T *getData(int i) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
};

template <class T>
CircleList<T>::CircleList()
{
}

template <class T>
CircleList<T>::~CircleList()
{
}

template <class T>
void CircleList<T>::makeEmpty()
{
}

template <class T>
int CircleList<T>::Length() const
{
    return 0;
}

template <class T>
bool CircleList<T>::IsEmpty() const
{
    return false;
}

template <class T>
CirLinkNode<T> *CircleList<T>::getHead() const
{
    return nullptr;
}

template <class T>
void CircleList<T>::setHead(CirLinkNode<T> *p)
{
}

template <class T>
CirLinkNode<T> *CircleList<T>::Search(const T &x)
{
    return nullptr;
}

template <class T>
CirLinkNode<T> *CircleList<T>::Locate(int i)
{
    return nullptr;
}

template <class T>
T *CircleList<T>::getData(int i) const
{
    return nullptr;
}

template <class T>
void CircleList<T>::setData(int i, T &x)
{
}

template <class T>
bool CircleList<T>::Insert(int i, T &x)
{
    return false;
}

template <class T>
bool CircleList<T>::Remove(int i, T &x)
{
    return false;
}

#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct DbLinkNode
{
    T data;
    DbLinkNode<T> *llink, *rlink;
    DbLinkNode(DbLinkNode<T> *left = NULL, DbLinkNode<T> *right = NULL)
    {
        llink = left;
        rlink = right;
    }
    DbLinkNode(const T &item, DbLinkNode<T> *left = NULL, DbLinkNode<T> *right = NULL)
    {
        data = item;
        llink = left;
        rlink = right;
    }
};

template <class T>
class DbList
{
  public:
    DbList(T val);
    ~DbList();
    int Length() const;
    bool IsEmpty() const;
    DbLinkNode<T> *getHead() const;
    void setHead(DbLinkNode<T> *p);
    DbLinkNode<T> *Search(const T &x);
    DbLinkNode<T> *Locate(int i);
    T *getData(int i) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
};

template <class T>
DbList<T>::DbList(T val)
{
}

template <class T>
DbList<T>::~DbList()
{
}

template <class T>
int DbList<T>::Length() const
{
    return 0;
}

template <class T>
bool DbList<T>::IsEmpty() const
{
    return false;
}

template <class T>
DbLinkNode<T> *DbList<T>::getHead() const
{
    return nullptr;
}

template <class T>
void DbList<T>::setHead(DbLinkNode<T> *p)
{
}

template <class T>
DbLinkNode<T> *DbList<T>::Search(const T &x)
{
    return nullptr;
}

template <class T>
DbLinkNode<T> *DbList<T>::Locate(int i)
{
    return nullptr;
}

template <class T>
T *DbList<T>::getData(int i) const
{
    return nullptr;
}

template <class T>
void DbList<T>::setData(int i, T &x)
{
}

template <class T>
bool DbList<T>::Insert(int i, T &x)
{
    return false;
}

template <class T>
bool DbList<T>::Remove(int i, T &x)
{
    return false;
}

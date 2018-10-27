#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL)
    {
        link = ptr;
    }
    LinkNode(const T &item, LinkNode<T> *ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};

template <class T>
class LinkedList
{
  protected:
    LinkNode<T> *first;

  public:
    LinkedList();
    LinkedList(const T &x);
    LinkedList(LinkedList<T> &L);
    ~LinkedList();
    void makeEmpty();
    int Length() const;
    LinkNode<T> *getHead() const;
    void setHead(LinkNode<T> *p);
    LinkNode<T> *Search(const T &x);
    LinkNode<T> *Locate(int i);
    T *getData(int i) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
    bool IsEmpty() const;
    bool IsFull() const;
    void Sort();
    void input();
    void inputFront(T endTag);
    void inputRear(T endTag);
    void output();
    LinkedList<T> &operator=(LinkedList<T> &L);
};

template <class T>
LinkedList<T>::LinkedList()
{
}

template <class T>
LinkedList<T>::LinkedList(const T &x)
{
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &L)
{
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
void LinkedList<T>::makeEmpty()
{
}

template <class T>
int LinkedList<T>::Length() const
{
    return 0;
}

template <class T>
LinkNode<T> *LinkedList<T>::getHead() const
{
    return nullptr;
}

template <class T>
void LinkedList<T>::setHead(LinkNode<T> *p)
{
}

template <class T>
LinkNode<T> *LinkedList<T>::Search(const T &x)
{
    return nullptr;
}

template <class T>
LinkNode<T> *LinkedList<T>::Locate(int i)
{
    return nullptr;
}

template <class T>
T *LinkedList<T>::getData(int i) const
{
    return nullptr;
}

template <class T>
void LinkedList<T>::setData(int i, T &x)
{
}

template <class T>
bool LinkedList<T>::Insert(int i, T &x)
{
    return false;
}

template <class T>
bool LinkedList<T>::Remove(int i, T &x)
{
    return false;
}

template <class T>
bool LinkedList<T>::IsEmpty() const
{
    return false;
}

template <class T>
bool LinkedList<T>::IsFull() const
{
    return false;
}

template <class T>
void LinkedList<T>::Sort()
{
}

template <class T>
void LinkedList<T>::input()
{
}

template <class T>
void LinkedList<T>::inputFront(T endTag)
{
}

template <class T>
void LinkedList<T>::inputRear(T endTag)
{
}

template <class T>
void LinkedList<T>::output()
{
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &L)
{
    // TODO: insert return statement here
}

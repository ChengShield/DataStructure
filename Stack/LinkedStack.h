#pragma once

#include "Stack.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
struct StackNode
{
    T data;
    StackNode<T> *link;
    StackNode(T d = 0, StackNode<T> *next = NULL) : link(next), data(d) {}
};

template <typename T>
class LinkedStack
{
  private:
    StackNode<T> *top;

  public:
    LinkedStack();
    ~LinkedStack();
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x) const;
    int getSize() const;
    bool IsEmpty() const;
    bool IsFull() const;
    void makeEmpty();
    friend ostream &operator<<(ostream &os, LinkedStack<T> &s)
    {
        os << "Stack Size: " << s.getSize() << endl;
        StackNode<T> *p = s.top;
        int i = 0;
        while (p)
        {
            os << ++i << ": " << p->data << endl;
            p = p->link;
        }
        return os;
    }
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
}

template <typename T>
void LinkedStack<T>::Push(const T &x)
{
}

template <typename T>
bool LinkedStack<T>::Pop(T &x)
{
    return false;
}

template <typename T>
bool LinkedStack<T>::getTop(T &x) const
{
    return false;
}

template <typename T>
int LinkedStack<T>::getSize() const
{
    return 0;
}

template <typename T>
bool LinkedStack<T>::IsEmpty() const
{
    return false;
}

template <typename T>
bool LinkedStack<T>::IsFull() const
{
    return false;
}

template <typename T>
void LinkedStack<T>::makeEmpty()
{
}

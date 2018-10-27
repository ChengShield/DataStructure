#pragma once

#include "Stack.h"
#include <iostream>
using namespace std;

template <class T>
class SeqStack
{
  private:
    T *elements;
    int top;
    int maxSize;
    void overflowProcess();

  public:
    SeqStack(int sz = 50);
    ~SeqStack();
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x);
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;
    void makeEmpty();
    friend ostream &operator<<(ostream &os, SeqStack<T> &s);
};

#include "SeqStack.h"
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
void SeqStack<T>::overflowProcess()
{
}

template <class T>
SeqStack<T>::SeqStack(int sz)
{
}

template <class T>
SeqStack::~SeqStack()
{
}

template <class T>
void SeqStack<T>::Push(const T &x)
{
}

template <class T>
bool SeqStack<T>::Pop(T &x)
{
    return false;
}

template <class T>
bool SeqStack<T>::getTop(T &x)
{
    return false;
}

template <class T>
bool SeqStack<T>::IsEmpty() const
{
    return false;
}

template <class T>
bool SeqStack<T>::IsFull() const
{
    return false;
}

template <class T>
int SeqStack<T>::getSize() const
{
    return 0;
}

template <class T>
void SeqStack<T>::makeEmpty()
{
}

ostream &operator<<(ostream &os, SeqStack<T> &s)
{
    // TODO: insert return statement here
}

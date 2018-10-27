#pragma once

#include <cassert>
#include <iostream>
#include <stdlib.h>
using namespace std;

const int defaultSize = 100;

template <class T>
class SeqList
{
  protected:
    T *data;
    int maxSize;
    int last;
    void reSize(int newSize);

  public:
    SeqList(int sz = defaultSize);
    SeqList(SeqList<T> &L);
    ~SeqList();
    int Size() const;
    int Length() const;
    int Search(T &x) const;
    int Locate(int i) const;
    T *getData(int i) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
    bool IsEmpty();
    bool IsFull();
    void Sort();
    void input();
    void output();
    SeqList<T> operator=(SeqList<T> &L);
    friend istream &operator>>(istream &in, SeqList<T> &R)
    {
        R.last = -1; //�����
        while (!in.eof())
        {
            R.last++;
            if (R.last == R.maxSize)
                R.reSize(2 * R.maxSize);
            assert(in >> R.data[R.last]);
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, SeqList<T> &R)
    {
        for (int i = 0; i <= R.last; i++)
        {
            cout << "#" << i + 1 << ":\t" << R.data[i] << endl;
        }
        return out;
    }
};

template <class T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize <= 0)
    {
        cerr << "invalid new size ! " << endl;
        return;
    }
    if (newSize != maxSize)
    {
        T *newdata = new T[newSize];
        if (newdata == NULL)
        {
            cerr << "Memory Error ! " << endl;
            exit(1);
        }
        maxSize = newSize;

        for (int i = 0; i <= last; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
    }
}

template <class T>
SeqList<T>::SeqList(int sz)
{
    if (sz > 0)
    {
        data = new T[sz];
        if (data == NULL)
        {
            cerr << "Memory Error ! " << endl;
            exit(1);
        }
        maxSize = sz;
        last = -1;
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    maxSize = L.Size();
    last = L.Length() - 1;
    data = new T[maxSize];
    if (data == NULL)
    {
        cerr << "Memory Error ! " << endl;
        exit(1);
    }
    for (int i = 1; i <= last + 1; i++)
    {
        data[i - 1] = L.getData(i);
    }
}

template <class T>
SeqList<T>::~SeqList()
{
    delete[] data;
}

template <class T>
int SeqList<T>::Size() const
{
    return maxSize;
}

template <class T>
int SeqList<T>::Length() const
{
    return last + 1;
}

template <class T>
int SeqList<T>::Search(T &x) const
{
    for (int i = 1; i <= last + 1; i++)
    {
        if (data[i - 1] == x)
        {
            return i;
        }
    }
    return 0;
}

template <class T>
int SeqList<T>::Locate(int i) const
{

    if (i >= 1 && i <= last + 1)
    {
        return i;
    }

    return 0;
}

template <class T>
T *SeqList<T>::getData(int i) const
{
    return Locate(i) ? &data[i - 1] : NULL;
}

template <class T>
void SeqList<T>::setData(int i, T &x)
{
    Locate(i) ? data[i - 1] = x : NULL;
}

template <class T>
bool SeqList<T>::Insert(int i, T &x)
{
    if (i >= 0 && i <= last + 1)
    {
        if (last == maxSize - 1)
        {
            reSize(2 * maxSize);
        }
        for (int j = last + 1; j > i; j--)
        {
            data[j] = data[j - 1];
        }
        data[i] = x;
        last++;
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
    if (IsEmpty())
        return false;
    if (Locate(i))
    {
        x = data[i - 1];

        for (int j = i; j < last; j++)
        {
            data[j - 1] = data[j];
        }
        last--;
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::IsEmpty()
{
    return (last == -1);
}

template <class T>
bool SeqList<T>::IsFull()
{
    return (last == maxSize - 1);
}

template <class T>
void SeqList<T>::Sort()
{
    for (int i = 1; i <= last; i++)
    {
        for (int j = last; j >= i; j--)
        {
            if (data[j - 1] > data[j])
            {
                T tmp = data[j - 1];
                data[j - 1] = data[j];
                data[j] = tmp;
            }
        }
    }
}

template <class T>
void SeqList<T>::input()
{
    cout << "Input the size of the list which will be created:";
    while (1)
    {
        assert(cin >> last);
        last--;
        if (last < 0)
        {
            cout << "Input error, the size must be positive!\n";
            cout << "Input the size again:";
        }
        else if (last > maxSize - 1)
        {
            cout << "Input error, the size must be less than maxSize!\n";
            cout << "Input the size again:";
        }
        else
            break;
    }
    cout << "\nInput the data for each element to create the list:" << endl;
    for (int i = 0; i <= last; i++)
    {
        cout << "#" << i + 1 << ":";
        assert(cin >> data[i]);
    }
}

template <class T>
void SeqList<T>::output()
{
    cout << "\nThe size of the list is:" << last + 1 << endl;
    for (int i = 0; i <= last; i++)
        cout << "#" << i + 1 << ":\t" << data[i] << endl;
}

template <class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
    maxSize = L.Size();
    last = L.Length() - 1;
    delete[] data;
    data = new T[maxSize];
    if (data == NULL)
    {
        cerr << "Memory allocating error!" << endl;
        exit(1);
    }
    for (int i = 1; i <= last + 1; i++)
        data[i - 1] = L.getData(i);
    return SeqList<T>();
}

template <class T>
istream &operator>>(istream &in, SeqList<T> &R)
{
    R.last = -1;
    while (!in.eof())
    {
        R.last++;
        if (R.last == R.maxSize)
            R.reSize(2 * R.maxSize);
        assert(in >> R.data[R.last]);
    }
    return in;
}

template <class T>
ostream &operator<<(ostream &out, SeqList<T> &R)
{
    for (int i = 0; i <= R.last; i++)
    {
        cout << "#" << i + 1 << ":\t" << R.data[i] << endl;
    }
    return out;
}

void unionList(SeqList<int> &LA, SeqList<int> &LB)
{
    int n = LA.Length(), m = LB.Length(), k;
    for (int i = 0; i < m; i++)
    {
        int *x = LB.getData(i);
        k = LA.Search(*x);
        if (k == 0)
        {
            LA.Insert(n, *x);
            n++;
        }
    }
}

void intersection(SeqList<int> &LA, SeqList<int> &LB)
{
    int n = LA.Length(), m = LB.Length(), k, i = 1;
    while (i <= n)
    {
        int *x = LA.getData(i);
        k = LB.Search(*x);
        if (k == 0)
        {
            LA.Remove(i, *x);
            n--;
        }
        else
        {
            i++;
        }
    }
}
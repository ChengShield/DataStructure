#include <iostream>
// #include <vector>
using namespace std;

const int SZ = 1 << 20; //快速io
struct fastio
{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio()
    {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;

class Vector
{
  private:
    int *data;
    int size;
    int cap;

  public:
    Vector(int M);
    ~Vector();
    void insert(int e);
    int search(int e);
    bool find(int e);
};

Vector::Vector(int M)
{
    data = new int[M];

    if (!data)
    {
        cerr << "Memory Error!" << endl;
        exit(1);
    }
    size = 0;
    cap = M;
}

Vector::~Vector()
{
    delete[] data;
}

void Vector::insert(int e)
{
    int n = search(e) + 1;
    for (int i = size; i > n; i--)
    {
        data[i] = data[i - 1];
    }
    data[n] = e;
    size++;

    // for (int i = 0; i < size; i++)
    // {
    //     cout << data[i] << " ";
    // }
    // cout << endl;
}

int Vector::search(int e)
{
    int lo = 0, hi = size;
    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        e < data[mid] ? hi = mid : lo = mid + 1;
    }
    // cout << lo - 1 << endl;
    return --lo;
}

bool Vector::find(int e)
{
    return e == data[search(e)];
}

int main(int argc, char const *argv[])
{
    int M, N, e;
    // freopen("aaa.txt", "r", stdin);
    cin >> M >> N;
    // cout << "M: " << M << "; N: " << N << endl;
    Vector v(M);
    for (int i = 0; i < M; i++)
    {
        cin >> e;
        // cout << "e: " << e << endl;
        v.insert(e);
    }
    for (int i = 0; i < N; i++)
    {
        int lo, hi;
        cin >> lo >> hi;
        // cout << "lo: " << lo << "; hi:" << hi << endl;
        cout << v.search(hi) - v.search(lo) + v.find(lo) << endl;
    }
    return 0;
}

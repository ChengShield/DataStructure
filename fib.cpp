#include <iostream>

using namespace std;

int fib(int n, int a[])
{
    a[n]++;

    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1, a) + fib(n - 2, a);
    }
}

long long fib2(int n)
{
    long long f = 1, g = 1;
    // int c;

    if (n == 0 || n == 1)
    {
        return f;
    }

    while (n--)
    {
        f = f + g;
        g = f - g;
    }
    return g;
}

int main(int argc, char const *argv[])
{
    int n = 40;
    int a[n + 1];
    int b[n + 1];
    long long x;

    for (int i = 0; i <= n; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }

    fib(n, a);

    for (int i = 0; i <= n; i++)
    {
        cout << i << ":\t" << a[i] << "\t" << fib2(n - i) << endl;
    }
    cout << "\n";
    x = fib2(100);
    cout << x << endl;

    return 0;
}

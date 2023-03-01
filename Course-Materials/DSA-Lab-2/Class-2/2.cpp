#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int fibo[MAX] = {0};

long long fib(int n)
{
    long long val;
    if (n == 0)
        val = 0;
    else if (n == 1)
        val = 1;
    else
        val = fib(n - 1) + fib(n - 2);
    cout << val << " ";
    return val;
}

int main()
{
    fib(100);
    // cout << fib(4) << endl;
    return 0;
}
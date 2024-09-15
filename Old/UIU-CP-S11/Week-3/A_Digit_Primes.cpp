#include <bits/stdc++.h>

// This damn stupid problem used up almost all my stamina.
// if someone is reading this solution, remember two things,
// it's best to make arrays static and it is necessary to
// call calculate() and sieve() functions at the begining
// of main function (only once) to generate all possible values
// in range. Don't do the same mistake I did and waste time. Good Luck

#ifndef ONLINE_JUDGE
#include "../../../Debugging Tools/dbg.cpp"
#include "../../../Debugging Tools/MemView.cpp"
#endif

typedef long long ll;

#define MAX 1000009

static bool prime[MAX];
static ll cumulativeSum[MAX] = {0};

ll sum(ll n)
{
    ll sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void calculate(int n)
{
    int i = 0;
    for (int i = 2; i <= n; i++)
        if (prime[i] && prime[sum(i)])
            cumulativeSum[i] = cumulativeSum[i - 1] + 1;
        else
            cumulativeSum[i] = cumulativeSum[i - 1]; // so far
}

void sieve(int n)
{
    int count = 0;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
}

int main()
{
    int x, n, m;
    sieve(MAX);
    calculate(MAX);
    scanf("%d", &x);
    while (x--)
    {
        scanf("%d %d", &n, &m);
        printf("%lld\n", cumulativeSum[m] - cumulativeSum[n - 1]);
    }

    return 0;
}
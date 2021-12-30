#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../../Debugging Tools/dbg.cpp"
#include "../../../Debugging Tools/MemView.cpp"
#endif

#define MAX 100001

static int sum[MAX] = {0};
static int num[MAX] = {0};

void cumulativeSum()
{
    int i = 1;
    sum[0] = num[0];
    while (i < MAX)
    {
        sum[i] = num[i] + sum[i - 1];
        i++;
    }
}

int main()
{
    int n;
    int x, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    cumulativeSum();
    scanf("%d", &x);
    while (x--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }

    return 0;
}
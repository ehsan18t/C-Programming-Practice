#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int num[4] = {1, 3, 6, 10};
        scanf("%d", &n);
        int digit = (n % 10) - 1;
        int count = 0;
        while (n > 10)
        {
            n = n / 10;
            count++;
        }
        printf("%d\n", (digit * 10) + num[count]);
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int result = 0;
    int n;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &n);
            if (n == 1)
            {
                result = abs(i - 3) + abs(j - 3);
                break;
            }
        }
    }
    printf("%d", result);
    return 0;
}
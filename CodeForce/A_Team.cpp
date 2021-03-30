#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, decision;
    int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        decision = 0;
        for (int j = 0; j < 3; j++)
        {
            m = 0;
            scanf("%d", &m);
            if (m == 1)
                decision++;
        }
        if (decision > 1)
            result++;
    }
    printf("%d\n", result);
    return 0;
}
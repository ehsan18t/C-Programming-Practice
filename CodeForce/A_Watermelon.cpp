#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    if (n > 3)
    {
        for (int i = 2; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    
    if (flag == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
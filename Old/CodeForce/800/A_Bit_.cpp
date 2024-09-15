#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, result = 0;
    char op[5] = "";
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &op);
        if (op[1] == '-')
        {
            result--;
        }
        else if (op[1] == '+')
        {
            result++;
        }
    }
    printf("%d", result);
    return 0;
}
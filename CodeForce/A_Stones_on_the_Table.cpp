#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int result = 0;
    char colors[100] = "";
    scanf("%d %s", &n, &colors);
    for (int i = 0; i < n-1; i++)
    {
        if (colors[i] == colors[i+1])
            result++;
    }
    printf("%d", result);
    return 0;
}
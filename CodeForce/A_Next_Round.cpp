#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, q;
    int contestant = 0;
    int scores[100];
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
    }
    q = scores[p - 1];
    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= q && scores[i] > 0)
        {
            contestant++;
        }
    }
    printf("%d\n", contestant);
    return 0;
}
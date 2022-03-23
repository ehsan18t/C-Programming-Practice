#include <bits/stdc++.h>

using namespace std;

#define MAX 100;

int main()
{
    stack<char> blade;
    int n, m, si, sj;
    cin >> n >> m;
    char a[n][m];

    // input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
        }

    // find
    int i = si;
    int j = sj;
    while (a[i][j] != 'E')
    {
        while (a[i][j] != 'E')
        {
            blade.push(a[i][j];
        }
    }

    return 0;
}


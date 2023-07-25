#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/633/A

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    for (int i = 1; i < (c / a) + 1; i++)
    {
        if ((c - (i * a)) % b == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    for (int i = 1; i < (c / b) + 1; i++)
    {
        if ((c - (i * b)) % a == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main()
{
    sync;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

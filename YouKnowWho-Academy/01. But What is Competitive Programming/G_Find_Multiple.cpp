#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc220/tasks/abc220_a?lang=en

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
    for (int i = 1; i * c <= b; i++)
    {
        if (i * c <= b && i * c >= a)
        {
            cout << i * c << endl;
            return;
        }
    }
    cout << -1 << endl;
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

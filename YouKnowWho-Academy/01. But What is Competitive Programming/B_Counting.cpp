#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc209/tasks/abc209_a?lang=en

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        cout << 0 << endl;
    else
        cout << (b - a + 1) << endl;
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

#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc125/tasks/abc125_a?lang=en

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    int a, b, t, ans = 0;
    cin >> a >> b >> t;
    for (int i = 1; i * a <= t; i++)
        ans += b;
    cout << ans << endl;
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

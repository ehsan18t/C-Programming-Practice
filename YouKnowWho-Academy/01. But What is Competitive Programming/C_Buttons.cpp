#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc124/tasks/abc124_a?lang=en

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
    cout << max(max(a + (a - 1), b + (b - 1)), a + b) << endl;
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

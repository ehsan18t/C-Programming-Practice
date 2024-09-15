#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc193/tasks/abc193_a?lang=en

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    double a, b;
    cin >> a >> b;
    cout << ((a - b) / a) * 100.00 << endl;
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

#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc199/tasks/abc199_a?lang=en

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
    if ((a * a) + (b * b) < (c * c))
        cout << "Yes" << endl;
    else
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

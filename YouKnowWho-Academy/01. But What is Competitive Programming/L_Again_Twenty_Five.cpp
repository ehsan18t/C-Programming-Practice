#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/630/A

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    int a;
    cin >> a;
    if (a == 0)
        cout << 1 << endl;
    else
        cout << (a == 1 ? 5 : 25) << endl;
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

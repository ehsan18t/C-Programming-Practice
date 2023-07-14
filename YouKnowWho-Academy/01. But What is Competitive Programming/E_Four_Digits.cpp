#include <bits/stdc++.h>

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    string s;
    cin >> s;
    for (int i = s.size(); i < 4; i++)
        cout << 0;
    cout << s << endl;
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

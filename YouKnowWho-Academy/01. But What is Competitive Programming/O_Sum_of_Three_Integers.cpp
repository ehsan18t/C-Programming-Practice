#include <bits/stdc++.h>

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Typedefs
typedef long long ll;

// Solution
void solve()
{
    int s, k, ans = 0;
    cin >> k >> s;
    for (int x = 0; x <= k; x++)
    {
        for (int y = 0; y <= k; y++)
        {
            int z = s - x - y;
            if (z >= 0 && z <= k)
                ans++;
        }
    }
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

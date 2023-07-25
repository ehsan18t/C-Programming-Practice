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
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    ll sum_of_power_of_2 = 0;
    for (ll i = 1; i <= n; i *= 2)
        sum_of_power_of_2 += i;
    cout << sum - 2 * sum_of_power_of_2 << endl;
}

int main()
{
    sync;
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

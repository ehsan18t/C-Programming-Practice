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
bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

bool is_2_prime_div(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && is_prime(i))
            cnt++;
        if (cnt > 2)
            return false;
    }
    return cnt == 2;
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (is_2_prime_div(i))
            ans++;
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

#include <bits/stdc++.h>

#define INF(type) std::numeric_limits<type>::max()

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)
#define FORx(i, x, n) for (int i = x; i < n; i++)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--)
#define for_map(m) for (auto it : m)

// Lazy Map
#define contains(m, k) (m.find(k) != m.end())
#define K it.first
#define V it.second

// Data Manipulation
#define init(A, V) memset(A, V, sizeof(A))

// Math
#define PI 2 * acos(0.0)
#define INF(type) std::numeric_limits<type>::max()
#define sqr(n) (n * n)
#define nCr(n, k) std::exp(std::lgamma(n + 1) - std::lgamma(k + 1) - std::lgamma(n - k + 1))

// In/out
#ifndef ONLINE_JUDGE
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#else
#define in printf("")
#define out printf("")
#endif // !ONLINE_JUDGE

// Data types
#define dbl double
#define ll long long
#define ull unsigned long long
#define umap unordered_map

// Lazy
#define psb push_back
#define ppb pop_back
#define lg length()
#define sz size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Opt
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

using namespace std;

// Solution
#define input(v)       \
    for (auto &it : v) \
        cin >> it;

int diff(int a, int b)
{
    return a > b ? a - b : b - a;
}

void solve()
{
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    int a[n][n];
    FOR(i, n)
    {
        FOR(j, n)
        cin >> a[i][j];
    }

    FOR(i, n)
    {
        sum1 += a[i][i];
        sum2 += a[i][n - i - 1];
    }
    cout << diff(sum1, sum2) << endl;
}

int main()
{
    fastIO;
    // in;
    // out;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

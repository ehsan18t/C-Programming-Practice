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
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void attack(vector<pair<ll, ll>> &data, ll &k, int &conclude)
{
    ll min = INF(ll);
    for (auto &m : data)
    {
        if (m.first == 0)
            break;

        m.first -= k;
        if (m.first <= 0)
            m.first = 0;

        if (m.second < min && m.first > 0)
            min = m.second;
    }

    min = min == INF(ll) ? 0 : min;
    k -= min;

    if (k < 0) // loose
        conclude = -1;
    else if (k >= 0 && data[0].first == 0) // win
        conclude = 1;
    else // continue
        conclude = 0;
}

void solve()
{
    // n == number of monsters
    // k = inital attack power
    ll n, k;
    cin >> n >> k;
    // first = monster's health, second = monster's attack power
    vector<pair<ll, ll>> monsters(n);
    FOR(i, n)
    cin >> monsters[i].first;
    FOR(i, n)
    cin >> monsters[i].second;

    // solutions
    // 1. sort monsters by health DESC
    sort(monsters.begin(), monsters.end(), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.first > b.first; });
    // 2. loop through monsters
    int conclude = 0;
    while (conclude == 0)
    {
        attack(monsters, k, conclude);
    }
    // cout << conclude << " : " << k << endl;

    if (conclude == 1)
        yes;
    else
        no;
}

int main()
{
    sync;
    in;
    out;
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

#include <bits/stdc++.h>

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
#define INF LLONG_MAX
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

struct team
{
    string name;
    int solved;
    int pen;
} typedef team;

#define input(arr, n)                 \
    for (int i = 0; i < n; i++)       \
    {                                 \
        string name;                  \
        int solved;                   \
        int pen;                      \
        cin >> name >> solved >> pen; \
        arr.psb({name, solved, pen}); \
    }

bool comp(team a, team b)
{
    if (a.solved == b.solved)
        return a.pen < b.pen;
    return a.solved > b.solved;
}

// Solution
void solve()
{
    int n;
    cin >> n;
    vector<team> arr;
    input(arr, n);
    sort(arr.begin(), arr.end(), comp);
    cout << arr[0].name << endl;
    // FOR(i, n)
    // cout << arr[i].name << " " << arr[i].solved << " " << arr[i].pen << endl;
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

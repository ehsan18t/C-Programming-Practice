#include <bits/stdc++.h>

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)
#define FORx(i, x, n) for (int i = x; i < n; i++)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--)
#define for_map(m) for(auto it : m)

// Lazy Map
#define contains(m, k) (m.find(k) != m.end())
#define K it.first
#define V it.second

// Data Manupulation
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
#define db double
#define ll long long
#define ull unsigned long long
#define umap unordered_map

// Lazy
#define pb push_back
#define lg length()
#define sz size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* #region(collapsed) FUNCTIONS */
// collected from stackoverflow
// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str)
{
    std::regex regexz(regex_str);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator());
    return list;
}
/* #endregion */

using namespace std;

// Solution
void solve()
{
    ll n;
    cin >> n;
    ll arr1[n];
    ll arr2[n];

    FOR(i, n) cin >> arr1[i];
    FOR(i, n) cin >> arr2[i];

    cout << arr2[0] - arr1[0] << " ";
    FORx(i, 1, n)
        cout << (arr1[i] < arr2[i - 1] ? arr2[i] - arr2[i-1] : (arr2[i] - arr1[i])) << " ";
    cout << endl;
}

int main()
{
    sync;
    in;
    out;
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

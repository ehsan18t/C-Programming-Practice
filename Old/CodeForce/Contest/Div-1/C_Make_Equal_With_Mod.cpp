#include <bits/stdc++.h>

// unsolved

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)
#define FORx(i, x, n) for (int i = x; i < n; i++)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--)

// Data Manupulation
#define init(A, V) memset(A, V, sizeof(A))

// Math
#define PI 2 * acos(0.0)
#define INF LLONG_MAX
#define sqr(n) (n * n)

// In/out
#ifndef ONLINE_JUDGE
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#else
#define in printf("")
#define out printf("")
#endif // !ONLINE_JUDGE

// Data types
#define db double
#define ll long long
#define ull unsigned long long

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
bool contains_key(unordered_map<ll, ll> m, ll key)
{
    if (m.find(key) == m.end())
        return false;
    return true;
}

void solve()
{
    bool flag = true;
    ll n;
    unordered_map<ll, ll> um;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        um[tmp] = tmp;
    }
    if (contains_key(um, 1))
    {
        int prev = um[1];
        for (pair<ll, ll> p : um)
        {
            if (p.first != prev)
            {
                flag = false;
                break;
            }
        }
    }
    (flag) ? yes : no;
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

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

// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str)
{
    std::regex regexz(regex_str);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator());
    return list;
}

using namespace std;

// Solution
void solve()
{
    int n, flag = 1;
    cin >> n;
    vector<string> a(n);
    FOR(i, n)
    {
        cin >> a[i];
    }
    // Compare
    FOR(i, n)
    {
        sort(a[i].begin(), a[i].end());
    }
    FOR(i, n)
    {
        FOR(j, n - 1)
        {
            if (a[j + 1][i] < a[j][i])
            {
                flag = 0;
                cout << a[j + 1][i] << " " << a[j][i];
                break;
            }
        }
        if (!flag)
            break;
    }
    flag ? yes : no;
}

int main()
{
    fastIO;
    // in;
    // out;
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

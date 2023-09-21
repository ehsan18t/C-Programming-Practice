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

// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str)
{
    std::regex regexz(regex_str);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator());
    return list;
}

using namespace std;

static int s[10][10] = {0};

void populate()
{
    FOR(i, 10)
    {
        FOR(j, 10)
        {
            if (i == 0 || i == 9 || j == 0 || j == 9)
                s[i][j] = 1;
            else if (i == 1 || i == 8 || j == 1 || j == 8)
                s[i][j] = 2;
            else if (i == 2 || i == 7 || j == 2 || j == 7)
                s[i][j] = 3;
            else if (i == 3 || i == 6 || j == 3 || j == 6)
                s[i][j] = 4;
            else if (i == 4 || i == 5 || j == 4 || j == 5)
                s[i][j] = 5;
        }
    }

    // FOR(i, 10)
    // {
    //     FOR(j, 10)
    //     cout << s[i][j];
    //     cout << endl;
    // }
    // cout << endl;
}

// Solution
void solve()
{
    char ch;
    int ans = 0;
    vector<pair<int, int>> points;
    FOR(i, 10)
    {
        FOR(j, 10)
        {
            cin >> ch;
            if (ch == 'X')
                points.psb({i, j});
        }
    }

    for (auto p : points)
        ans += s[p.first][p.second];
    cout << ans << endl;
}

int main()
{
    sync;
    in;
    out;
    populate();
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

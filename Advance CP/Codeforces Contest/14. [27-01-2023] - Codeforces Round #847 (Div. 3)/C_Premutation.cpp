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

// Solution
typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

pair<int, int> find_first_last(matrix &mat)
{
    umap<int, int> f, l;
    pair<int, int> first, last;
    int n = mat.sz;
    FOR(i, n)
    {
        if (contains(f, mat[i][0]))
            f[mat[i][0]]++;
        else
            f[mat[i][0]] = 1;

        if (contains(l, mat[i][n - 2]))
            l[mat[i][n - 2]]++;
        else
            l[mat[i][n - 2]] = 1;
    }

    for (auto it : f)
        // cout << it.first << " " << it.second << endl;
        if (it.second > first.second)
            first = it;
    for (auto it : l)
        if (it.second > last.second)
            last = it;
    // cout << it.first << " " << it.second << endl;

    return make_pair(first.first, last.first);
}

pair<int, int> find_arr(matrix &mat, int first, int last)
{
    int n = mat.sz;
    int m = n - 1;
    int i = 0, j = 0;
    while (!(mat[i][0] == first && mat[i][m - 1] != last))
        i++;

    while (!(mat[j][0] != first && mat[j][m - 1] == last))
        j++;
    return make_pair(i, j);
}

void solve()
{
    int n;
    cin >> n;
    matrix m = make_matrix(n, n - 1);
    FOR(i, n)
    FOR(j, n - 1)
    cin >> m[i][j];

    // Find first and last
    auto fl = find_first_last(m);
    // cout << fl.first << " " << fl.second << endl;
    auto res = find_arr(m, fl.first, fl.second);
    // cout << res.first << " " << res.second << endl;
    m[res.first].push_back(m[res.second].back());
    for (auto a : m[res.first])
        cout << a << " ";
    cout << endl;
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

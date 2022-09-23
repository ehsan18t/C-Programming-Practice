#include <bits/stdc++.h>

// Link: https://codeforces.com/contest/1734/problem/C

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

int diff(int a, int b)
{
    return a > b ? a - b : b - a;
}

void solve()
{
    ll n, count = 0, ans = 0;
    string str;
    cin >> n >> str;
    vector<ll> arr(n, 0);
    vector<ll> org(n, 0);
    FOR(i, n)
    {
        arr[i] = str[i] - '0';
        org[i] = str[i] - '0';
        if (str[i] - '0' == 0)
            count++;
    }

    FOR(i, n)
    {
        if (org[i] == 1)
            continue;
        int j = (i + 1);
        if (j == n && arr[j - 1] == 1)
            break;
        while (j <= n)
        {
            if (org[j - 1] == 1)
                break;
            if (arr[j - 1] == 0)
            {
                arr[j - 1] = 1;
                count--;
                if (j != i + 1 || arr[i] != 0)
                    ans += i + 1;
                // if (count == 0)
                //     break;
                // cout << i + 1 << " ";
            }
            j += (i + 1);
        }
        if (count == 0)
            break;
    }
    cout << ans << endl;
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

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
    vector<int> twos;
    int ans = 0;
    bool flag = false;
    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        m[tmp]++;
        if (m[tmp] == 3)
            flag = true;
        if (m[tmp] == 2)
            twos.psb(tmp);
    }

    if (!flag)
    {
        ans = INF(int);
        if (twos.size())
        {
            for (auto two : twos)
            {
                int new_ans = INF(int);
                auto beforeTwo = (--m.find(two));
                auto afterTwo = (++m.find(two));
                if (beforeTwo != (--m.begin()))
                    new_ans = min(ans, diff(two, beforeTwo->first));
                if (afterTwo != m.end())
                    new_ans = min(ans, diff(two, afterTwo->first));
                ans = min(ans, new_ans);
            }
        }
        else
        {
            ans = INF(int);
            int first = m.begin()->first;
            int second = (++m.begin())->first;
            for_map(m)
            {
                if (K == first || K == second)
                    continue;
                int a = diff(second, first);
                int b = diff(K, second);
                if (ans > a + b)
                    ans = a + b;
            }
        }
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

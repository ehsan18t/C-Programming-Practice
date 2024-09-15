#include <bits/stdc++.h>

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

void swap2(ll *a, ll *b)
{
    ll c = *a;
    *a = *b;
    *b = c;
}

ll makePos(ll a)
{
    return (a < 0 ? a * -1 : a);
}

void solve()
{
    int n;
    cin >> n;
    ll arr1[n];
    ll arr2[n];

    // input
    FOR(i, n)
    cin >> arr1[i];
    FOR(i, n)
    cin >> arr2[i];

    ll sum1 = 0, sum2 = 0;
    FOR(i, n - 1)
    {
        if (arr1[i] > arr2[i])
            swap2(&arr1[i], &arr2[i]);
        if (arr1[i + 1] > arr2[i + 1])
            swap2(&arr1[i + 1], &arr2[i + 1]);

        sum1 += makePos(arr1[i] - arr1[i + 1]);
        sum2 += makePos(arr2[i] - arr2[i + 1]);
    }
    cout << sum1 + sum2 << endl;
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

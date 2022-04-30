#include <bits/stdc++.h>

// Wrong Ansawer

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
#define nCr(n, k) std::exp(std::lgamma(n + 1) - std::lgamma(k + 1) - std::lgamma(n - k + 1))

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

int strToNum(string str)
{
    int sum = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        sum += (str[i] - 'a') + 1;
        i++;
    }
    return sum;
}

void solve(bool alice)
{
    bool is_bob = false;
    string str;
    cin >> str;
    int n = str.length();
    int a = 0, b = 0;

    int i = 0;

    if (alice)
    {
        int c = (n % 2 == 0) ? 0 : 1;
        a = strToNum(str.substr(0, n - c));
        b = strToNum(str.substr(n - c, n));
        // cout << str.substr(n - c, n) << endl;
        // cout << n << " " << n - 1 - c << " " << a << " " << b << endl;
    }
    else
    {
        int c = ((n - 1) % 2 == 0) ? 0 : 1;
        b = str[0] - 'a' + 1;
        a = strToNum(str.substr(1, n - c));
        b += strToNum(str.substr(n - c, n));
        // cout << str.substr(0, 1) << endl;
        // cout << n << " " << n - 1 - c << " " << a << " " << b << endl;
    }

    if (a > b)
        cout << "Alice " << a - b << endl;
    else
        cout << "Bob " << b - a << endl;
}

int main()
{
    sync;
    in;
    out;
    int n, i = 0;
    cin >> n;
    while (n--)
    {
        solve(i % 2 == 0);
        i++;
    }
    return 0;
}

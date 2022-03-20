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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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

void print(int arr[], int n)
{
    FOR(i, n)
    cout << arr[i] << " ";
    cout << endl;
}
void solve()
{
    int n, j, count = 0;
    cin >> n;
    int arr[n];
    FOR(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    j = 0;
    while (1)
    {
        j = 0;
        int e = arr[j];
        while (e == arr[j])
            j++;
        if (j >= n - 1)
            break;

        int diff = arr[j] - e;
        diff = (diff == 1 ? 1 : (diff == 2 ? 2 : 5));
        int tmp = j;
        while (tmp--)
            arr[tmp] += diff;
        count++;
        // print(arr, n);
    }
    cout << count << endl;
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

#include <bits/stdc++.h>

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)           // normal loop (0 to n)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)     // normal reverse loop (n to 0)
#define FORx(i, x, n) for (int i = x; i < n; i++)       // loop starts from x (x to n)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--) // reverse loop starts from n to x (n to x)
#define for_map(m) for (auto it : m)                    // iterate map

// Lazy Map
#define contains(m, k) (m.find(k) != m.end()) // checks for k in map and returns boolean value
#define K it.first
#define V it.second

// Data Manipulation
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

using namespace std;

/////////////////////
//                 //
//     Solution    //
//                 //
/////////////////////

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// Input Array
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

#define input2d(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

// Output
struct solution
{
} typedef solution;
static vector<solution> sol; // solution list

void output()
{
    for (auto e : sol)
    {
    }
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

struct dt
{
    int val;
    vector<int> adj;
} typedef dt;

vector<vector<int>> inp(int n)
{
    vector<vector<dt>> v;
    // first half
    FOR(i, n + 1)
    {
        vector<dt> t(i);
        FOR(j, i)
        cin >> t[j].val;
        v.psb(t);
        // adj list
        if ()
    }
    // last half
    FORr(i, n)
    {
        vector<int> t(i, 0);
        FOR(j, i)
        cin >> t[j];
        v.psb(t);
    }
    return v;
}

int divide()
{
}

void buildGraph()
{
}

void solve()
{
    // // Codes
    // solution s;
    int n;
    cin >> n;
    vector<vector<int>> v = inp(n);

    // calculation

    // print
    for (auto l : v)
    {
        for (auto e : l)
            cout << e << " ";
        cout << endl;
    }
    // // push output
    // sol.psb(s);
}

int main()
{
    in;
    out;
    int n = 1;
    cin >> n;
    while (n--)
        solve();

    // print output
    output();
    return 0;
}

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
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

using namespace std;

// Solution
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

struct SubArrInfo
{
    int start;
    int end;
    ll sum;
} typedef SubArrInfo;

// Linear Approach
SubArrInfo maxSubArrSum(vector<int> arr)
{
    int n = arr.size();
    SubArrInfo currentSum = {-1, -1, 0}, maxSum = {-1, -1, 0}, max = {-1, -1, -INF(ll)};

    // Find Largest Sum Sub-array
    for (int i = 0; i < n; i++)
    {
        currentSum.sum += arr[i];
        // Reset if sum is negative
        if (currentSum.sum < 0)
        {
            currentSum.sum = 0;
            currentSum.start = -1;
        }
        else
        {
            // if sum is positive remember details
            currentSum.end = i;
            if (currentSum.start == -1)
                currentSum.start = i;
        }

        // if current sum is bigger store it to maxSum
        if (currentSum.sum > maxSum.sum)
            maxSum = currentSum;

        // maximum element of the array
        if (max.sum < arr[i])
        {
            max.sum = arr[i];
            max.start = i;
            max.end = i;
        }
    }

    // if all elements are negative
    if (maxSum.start == -1)
        maxSum = max;

    return maxSum;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> arr(n);
    input(arr, n);

    // Find Max Sum -> O(n)
    auto maxSum = maxSubArrSum(arr);

    // output
    cout << maxSum.sum << endl;
}

int main()
{
    // in;
    // out;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

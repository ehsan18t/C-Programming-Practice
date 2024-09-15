#include <bits/stdc++.h>

// In/out
#ifndef ONLINE_JUDGE
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#else
#define in printf("")
#define out printf("")
#endif // !ONLINE_JUDGE

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

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void solve()
{
    vector<int> ans;
    // Codes
    int n, m, l, r, k;
    // input
    cin >> n;
    vector<int> wpn(n);
    input(wpn, n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> k;
        // sub arr
        vector<int> arr;
        for (int j = l - 1; j < r; j++)
            arr.push_back(wpn[j]);
        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += arr[j];
        ans.push_back(sum);
    }

    // print
    for (auto a : ans)
        cout << a << endl;
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

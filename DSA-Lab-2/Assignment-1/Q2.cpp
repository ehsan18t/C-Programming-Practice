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

void solve()
{
    int n, count = 0;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (arr.empty() || val > arr.back())
            arr.push_back(val);
        else
        {
            long int index = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
            count += arr.size() - index;
            arr.insert(arr.begin() + index, val);
        }
    }

    // output
    cout << count << endl;
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

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
    int n, k;
    cin >> n;
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    cin >> k;
    k--;
    while (k--)
        pq.pop();

    // output
    cout << pq.top() << endl;
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

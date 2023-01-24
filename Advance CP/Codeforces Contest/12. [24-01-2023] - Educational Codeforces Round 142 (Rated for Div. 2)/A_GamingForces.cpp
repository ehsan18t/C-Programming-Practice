#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    // Remove
    int count = 0;
    int i = 0;
    while (i < n - 1)
    {
        if (a[i] == 1)
        {
            a[i] = 0;
            a[i + 1]--;
            count++;
            i += a[i + 1] == 0 ? 1 : 0;
        }

        i++;
    }

    // Count
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            count++;
    }

    cout << count << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
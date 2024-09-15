#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/271/A

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Typedefs
typedef long long ll;

// Solution
bool is_distinct(int n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    bool flag = true;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (v[i] == v[j])
            {
                flag = false;
                break;
            }
    return flag;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = n + 1; i <= 10000; i++)
    {
        if (!is_distinct(i))
            continue;
        else
        {
            n = i;
            break;
        }
    }
    cout << n << endl;
}

int main()
{
    sync;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

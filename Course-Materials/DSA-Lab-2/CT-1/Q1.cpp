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

void rev(string &str, int start, int end, int count)
{
    if (start < end)
    {
        swap(str[start], str[end]);
        cout << str[start] << pow(count, 3) << str[end - 1] << " ";
        rev(str, start + 1, end - 1, count + 1);
    }
    cout << str[end] << pow(count, 3) << str[start - 1] << " ";
}
vector<string> ans;

void solve()
{
    // Codes
    int n;
    string str;
    cin >> n >> str;

    // reversing
    rev(str, 0, n - 1, 1);
    // vector<string> v = split(str);
    // for (auto st : v)
    //     cout << st << " ";
    cout << endl;
    // v.push_back(ss);
}

int main()
{
    in;
    out;
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

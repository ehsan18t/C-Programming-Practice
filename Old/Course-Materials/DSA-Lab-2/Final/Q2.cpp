#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

#define contains(m, str) (m.find(str) != m.end())
#define compStr(s1, s2) s1.length() > s2.length() ? s2 + " " : s1 + " "

// Output
void solve()
{
    string ans = "";
    unordered_map<string, string> strMap;
    vector<string> strList;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        strMap[s1] = s2;
    }
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        strList.push_back(s1);
    }

    for (auto s : strList)
        ans += compStr(s, strMap[s]);
    cout << ans << endl;
}

int main()
{
    in;
    out;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

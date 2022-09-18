#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define maximum(a, b) (a > b ? a : b)

matrix LCS(string &str1, string &str2)
{
    int m = str1.length();
    int n = str2.length();
    matrix lcs(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = maximum(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    return lcs;
}

string selectedString(matrix &lcs, string &str1, string &str2, int i, int j)
{
    if (i == 0 || j == 0)
        return "";
    if (str1[i - 1] == str2[j - 1])
        return selectedString(lcs, str1, str2, i - 1, j - 1) + str1[i - 1];
    if (lcs[i - 1][j] > lcs[i][j - 1])
        return selectedString(lcs, str1, str2, i - 1, j);
    return selectedString(lcs, str1, str2, i, j - 1);
}

string selected(matrix &lcs, string &str1, string &str2)
{
    return selectedString(lcs, str1, str2, str1.length(), str2.length());
}

// Output
void solve()
{
    string str1 = "abcde";
    string str2 = "bde";
    auto lcs = LCS(str1, str2);
    cout << lcs[str1.length()][str2.length()] << endl;
    cout << selected(lcs, str1, str2) << endl;
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

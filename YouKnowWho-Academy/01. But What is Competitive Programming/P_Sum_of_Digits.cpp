#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/102/B

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
long long sum_of_digit(long long n)
{
    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int str_to_sum(string str)
{
    int sum = 0, i = 0;
    while (str[i] != '\0')
    {
        sum += str[i] - '0';
        i++;
    }
    return sum;
}

void solve()
{
    int ans = 1, n;
    string str;
    cin >> str;
    if (str.size() == 1)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        n = str_to_sum(str);
        while (n > 9)
        {
            n = sum_of_digit(n);
            ans++;
        }
        cout << ans << endl;
    }
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

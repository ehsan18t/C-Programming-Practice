#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc214/tasks/abc214_b?lang=en

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Solution
void solve()
{
    int sum, product, count = 0;
    cin >> sum >> product;
    for (int a = 0; a <= sum; a++)
        for (int b = 0; b <= sum; b++)
            for (int c = 0; c <= sum; c++)
                if (a + b + c <= sum && a * b * c <= product)
                    count++;
    cout << count << endl;
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

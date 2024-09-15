#include <bits/stdc++.h>

#define in freopen("q1.in", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

struct product
{
    int value;
    int price;
};

vector<vector<product>> find_all_subset(vector<product> &products, int n)
{
    vector<vector<product>> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<product> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                subset.push_back(products[j]);
            // cout << "i: " << i << " j: " << j << " " << (1 << j) << " " << (i & (1 << j)) << endl;
        }
        ans.push_back(subset);
    }
    return ans;
}

// Output
int solve()
{
    int n;
    cin >> n;
    vector<product> v(n);
    for (auto &i : v)
        cin >> i.value >> i.price;

    auto subsets = find_all_subset(v, n);
    vector<vector<product>> selected;
    for (auto subset : subsets)
    {
        int sum = 0;
        for (auto i : subset)
            sum += i.value;
        if (sum + subset.size() >= n)
            selected.push_back(subset);
    }

    vector<product> ans;
    int sum = 0, prev = INF(int);
    for (auto subset : selected)
    {
        if (subset.size() == 0)
            continue;
        // find maximum price subset

        for (auto i : subset)
        {
            sum += i.price;
            // cout << i.value << " " << i.price << endl;
        }
        // cout << sum << endl
        //      << endl;

        if (sum <= prev)
        {
            ans = subset;
            prev = sum;
            sum = 0;
        }
    }
    int ans_sum = 0;
    for (auto i : ans)
        ans_sum += i.price;
    // cout << ans_sum << endl;
    return ans_sum;
}

int main()
{
    in;
    out;
    int n = 1;
    cin >> n;
    vector<int> ans;
    while (n--)
        ans.push_back(solve());

    // out
    for (auto i : ans)
        cout << i << endl;
    return 0;
}

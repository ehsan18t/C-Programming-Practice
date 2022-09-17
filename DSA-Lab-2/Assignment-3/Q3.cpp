#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

struct bag
{
    int item;
    int price;
};

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i].item >> arr[i].price;

#define print(arr)     \
    for (auto p : arr) \
        cout << p.item << " " << p.price << endl;

#define maximum(a, b) (a > b ? a : b)

// 0-1 knapsack
matrix knapsack(vector<bag> &items, int w)
{
    matrix dp = make_matrix(items.size() + 1, w + 1);

    for (int i = 0; i <= items.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (items[i - 1].price <= j)
                dp[i][j] = maximum(items[i - 1].price + dp[i - 1][j - items[i - 1].item], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp;
}

// finding selected list
vector<bag> findSelected(matrix m, vector<bag> &items)
{
    vector<bag> selected;
    int i = m.size() - 1, j = m[0].size() - 1;

    while (i > 0 && j > 0)
    {
        if (m[i][j] != m[i - 1][j])
        {
            selected.push_back({items[i - 1].item, items[i - 1].price});
            j -= items[i - 1].item;
        }
        i--;
    }

    return selected;
}

// Output
void solve()
{
    int n, w, k, sum = 0;
    cin >> n >> w >> k;
    vector<bag> products(n);

    // input
    input(products, n);

    // knapsack
    auto dp = knapsack(products, w);

    // find selected
    auto selected = findSelected(dp, products);

    // find sum of items
    for (auto p : selected)
        sum += p.item;

    // output
    if (sum >= k)
        cout << "Yes " << sum << endl;
    else
        cout << "No" << endl;
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

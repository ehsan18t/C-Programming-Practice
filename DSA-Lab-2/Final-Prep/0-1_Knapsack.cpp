#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

struct product
{
    string name;
    int weight;
    double price;
};

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i].name >> arr[i].weight >> arr[i].price;

#define print(arr)     \
    for (auto p : arr) \
        cout << p.name << " " << p.weight << " " << p.price << endl;

#define max(a, b) (a > b ? a : b)

// 0-1 knapsack
matrix knapsack(vector<product> &products, int w)
{
    matrix dp = make_matrix(products.size() + 1, w + 1);

    for (int i = 0; i <= products.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (products[i - 1].weight <= j)
                dp[i][j] = max(products[i - 1].price + dp[i - 1][j - products[i - 1].weight], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp;
}

vector<product> findSelected(matrix m, vector<product> &products)
{
    vector<product> selected;
    int i = m.size() - 1, j = m[0].size() - 1;

    while (i > 0 && j > 0)
    {
        if (m[i][j] != m[i - 1][j])
        {
            selected.push_back({products[i - 1].name, products[i - 1].weight, products[i - 1].price});
            j -= products[i - 1].weight;
        }
        i--;
    }

    return selected;
}

// Output
void solve()
{
    int n, w;
    cin >> n >> w;
    vector<product> products(n);
    input(products, n);
    print(products);
    matrix dp = knapsack(products, w);
    cout << dp[n][w] << endl;
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

/*
Input:
4 5
A 3 4
B 2 3
C 5 6
D 4 5

Output:
A 3 4
B 2 3
C 5 6
D 4 5
7
*/
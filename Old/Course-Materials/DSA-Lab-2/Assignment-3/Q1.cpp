#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

struct ques
{
    int q;
    int marks;
    int time;
};

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i].q >> arr[i].marks >> arr[i].time;

#define print(arr)     \
    for (auto p : arr) \
        cout << p.q << " " << p.marks << " " << p.time << endl;

#define maximum(a, b) (a > b ? a : b)

// 0-1 knapsack
matrix knapsack(vector<ques> &questions, int w)
{
    matrix dp = make_matrix(questions.size() + 1, w + 1);

    for (int i = 0; i <= questions.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (questions[i - 1].marks <= j)
                dp[i][j] = maximum(questions[i - 1].time + dp[i - 1][j - questions[i - 1].marks], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp;
}

// finding selected list
vector<ques> findSelected(matrix m, vector<ques> &questions)
{
    vector<ques> selected;
    int i = m.size() - 1, j = m[0].size() - 1;

    while (i > 0 && j > 0)
    {
        if (m[i][j] != m[i - 1][j])
        {
            selected.push_back({questions[i - 1].q, questions[i - 1].marks, questions[i - 1].time});
            j -= questions[i - 1].marks;
        }
        i--;
    }

    return selected;
}

// Output
void solve()
{
    int n, w, max = -INF(int), sum = 0;
    cin >> n >> w;
    vector<ques> products(n);

    // input
    input(products, n);

    // knapsack
    auto dp = knapsack(products, w);

    // find selected
    auto selected = findSelected(dp, products);

    // find max and sum
    for (auto p : selected)
    {
        if (p.marks > max)
            max = p.marks;
        sum += p.marks;
    }

    // output
    // something * 2 = something + something
    // max is the marks that gives the highest value if doubled
    cout << (sum + max) << endl;
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

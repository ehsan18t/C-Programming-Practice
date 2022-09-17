#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define input(arr)        \
    for (auto &i : arr)   \
        for (auto &j : i) \
            cin >> j;

#define print(arr)     \
    for (auto p : arr) \
        cout << p.first << " " << p.second << endl;

matrix shortestPath(matrix &graph)
{
    matrix dist = make_matrix(graph.size(), graph.size());

    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph.size(); j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < graph.size(); k++)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph.size(); j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    return dist;
}

// Output
void solve()
{
    vector<pair<int, int>> output;
    int n, q;
    cin >> n;
    matrix m = make_matrix(n, n);

    // input
    input(m);

    // query
    auto res = shortestPath(m);
    cin >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int temp = res[x][y] + res[y][z];
        output.push_back({temp, temp - res[x][z]});
    }

    // output
    print(output);
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

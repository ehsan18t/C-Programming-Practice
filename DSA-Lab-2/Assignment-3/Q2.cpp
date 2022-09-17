#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

typedef vector<vector<int>> matrix;

#define make_matrix(m, n) vector<vector<int>>(m, vector<int>(n, 0))

#define inputArray(arr) \
    for (auto &i : arr) \
        cin >> i, i--;

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

// build matrix from u,v,w input
void buildMatrix(matrix &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        m[u - 1][v - 1] = w;
        m[v - 1][u - 1] = w;
    }
}

int solve()
{
    vector<pair<int, int>> output;
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> seq(l);
    matrix mat = make_matrix(m, m);

    // input
    inputArray(seq);
    buildMatrix(mat, m);

    // find all  shortest path
    auto res = shortestPath(mat);

    // find cities count
    int ans = 1;
    for (int i = 0, j = 0; i < l - 1; i = j, ++ans)
    {
        // b[i] to b[j] is shortest while trying to extend j
        while (j + 1 < l)
        {
            // paths between cities in b[i] and b[j+1]
            int e = 0;
            for (int k = i; k + 1 <= j + 1; ++k)
                e += mat[seq[k]][seq[k + 1]];
            if (e > res[seq[i]][seq[j + 1]])
                break; // not shortest path
            ++j;
        }
        if (i == j)
            return -1; // can't extend
    }
    return ans;
}

int main()
{
    // in;
    // out;
    vector<int> ans;
    int n = 1;
    cin >> n;

    // Tests
    while (n--)
        ans.push_back(solve());

    // output
    for (auto p : ans)
        cout << p << endl;

    return 0;
}

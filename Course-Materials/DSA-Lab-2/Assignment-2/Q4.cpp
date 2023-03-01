#include <bits/stdc++.h>

// In/out
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;

// Set
struct DisjointSet
{
    vector<int> parent;
    vector<int> size;

    DisjointSet(int maxSize)
    {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

// Kruskal's algorithm
typedef pair<int, int> e;

vector<e> kruskal(vector<e> edges, int n)
{
    vector<e> spTree;
    DisjointSet ds(n);
    // sort is not needed because weight is not used
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        if (ds.find_set(u) != ds.find_set(v))
        {
            ds.union_set(u, v);
            spTree.push_back(edge);
        }
    }
    return spTree;
}

// Solution
void solve(int cnt)
{
    int n, m;
    cin >> n >> m;
    vector<e> edges(m);

    // Start
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    vector<e> tree = kruskal(edges, n + m);

    // find edge count
    unordered_map<int, int> unique;
    for (auto edge : tree)
        unique[edge.first]++;

    // remove vertexes
    vector<e> ans;
    for (auto edge : unique)
        ans.push_back(edge);
    // sort in descending order of edge count
    sort(ans.begin(), ans.end(), [](e a, e b)
         { return a.second > b.second; });

    int count = 0;
    int size = tree.size();

    // disconnecting edges
    while (size > 0)
    {
        size -= ans[count].second;
        count++;
    }

    // output
    cout << count << endl;
}

int main()
{
    // in;
    // out;
    int n = 1, i = 1;
    // cin >> n;
    while (n--)
        solve(i++);
    return 0;
}

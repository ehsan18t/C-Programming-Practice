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
typedef pair<int, pair<int, int>> e;

vector<e> kruskal(vector<e> edges, int n)
{
    vector<e> spTree;
    DisjointSet ds(n);
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (ds.find_set(u) != ds.find_set(v))
        {
            ds.union_set(u, v);
            cost += w;
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
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_pair(w, make_pair(u, v));
    }

    vector<e> tree = kruskal(edges, m);

    // print tree
    for (auto edge : tree)
    {
        cout << edge.second.first << " " << edge.second.second << endl;
    }
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

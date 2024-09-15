#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

typedef pair<int, int> edge;

class graph
{
private:
    int v;
    list<edge> *adjList;
    vector<int> parent;
    vector<int> dist;

public:
    graph(int v)
    {
        this->v = v;
        vector<int> a(v, -1);
        parent = a;
        vector<int> b(v);
        dist = b;
        adjList = new list<edge>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    void dijk(int src)
    {
        for (int i = 0; i < dist.size(); i++)
            dist[i] = INF(int);

        dist[src] = 0;
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        pq.push({src, dist[src]});
        while (!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
            for (auto i : adjList[u])
            {
                int v = i.first;
                int weight = i.second;
                if (dist[v] > dist[u] + weight)
                {
                    pq.push({v, dist[v]});
                    parent[v] = u;
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // prints ouput for this specific problems
    void print(int a, int k)
    {
        // There are not enough time
        if (dist[a] * 2 > k)
        {
            cout << a << ": -1" << endl;
            return;
        }

        // if there are enough time
        stack<int> s;
        cout << a << " : ";
        int j = parent[a];

        while (j != -1)
        {
            s.push(j);
            j = parent[j];
        }

        // print path
        while (!s.empty())
        {
            int x, y;
            x = s.top();
            s.pop();

            // if last element
            if (s.empty())
            {
                cout << x << " <- " << dist[a] - dist[x] << " -> ";
                continue;
            }
            y = s.top();
            cout << x << " <- " << dist[y] << " -> ";
        }
        // print cost and play time
        cout << a << " = " << dist[a] << " | " << k - (dist[a] * 2) << endl;
    }
};

void solve()
{
    int n, m, q, src;
    cin >> n >> m >> src;
    graph g(n);

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        g.addEdge(x, y, c);
    }

    // generate shortest path tree
    g.dijk(src);

    // Input Queries
    cin >> q;
    vector<pair<int, int>> queries;
    while (q--)
    {
        int a, k;
        cin >> a >> k;
        queries.push_back({a, k});
    }

    // print output
    for (auto i : queries)
        g.print(i.first, i.second);
}

int main()
{
    // fileIO
    in;
    out;

    // codes
    int n = 1;
    cin >> n;
    while (n--)
        solve();
    return 0;
}
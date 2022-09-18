#include <bits/stdc++.h>

#define in freopen("eval.in", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

typedef pair<int, int> edge;

class graph
{
private:
    int v;
    list<edge> *adjList;
    vector<int> dist;
    vector<int> parent;

public:
    graph(int v)
    {
        this->v = v;
        vector<int> a(v);
        vector<int> b(v, -1);
        dist = a;
        parent = b;
        adjList = new list<edge>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    void printAdjList(int v)
    {
        cout << v << " : ";
        for (auto e : adjList[v])
            cout << e.first << " ";
        cout << endl;
    }

    void printList()
    {
        for (int i = 0; i < v; i++)
            printAdjList(i);
    }

    void dijkstra(int src)
    {
        for (int i = 0; i < dist.size(); i++)
            dist[i] = INF(int);

        dist[src] = 0;
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        pq.push(make_pair(src, dist[src]));
        while (!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
            for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)
                {
                    pq.push(make_pair(v, dist[v]));
                    parent[v] = u;
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    void findPath(vector<int> &time, int src, int dest)
    {
        stack<int> s = getpath(src, dest);
        }

    // Universal
    stack<int> getpath(int src, int dest)
    {
        stack<int> path;
        int i = dest;
        while (i != src)
        {
            path.push(i);
            i = parent[i];
        }
        path.push(src);
        return path;
    }

    int getCost(int src, int dest)
    {
        return dist[dest] - dist[src];
    }

    void printDist()
    {
        int i = 0;
        for (auto d : dist)
            cout << i++ << " : " << d << endl;
    }

    void printParent()
    {
        int i = 0;
        for (auto d : parent)
            cout << i++ << " : " << d << endl;
    }

    int getWeight(int src, int dest)
    {
        for (auto w : adjList[src])
        {
            if (w.first == dest)
                return w.second;
        }
        return -1;
    }

    void printPath()
    {
        int i = 0;
        for (auto p : parent)
        {
            stack<int> s;
            cout << i << " : ";
            int j = p;

            while (j != -1)
            {
                s.push(j);
                j = parent[j];
            }

            while (!s.empty())
            {
                int x, y;
                x = s.top();
                s.pop();

                // if last element
                if (s.empty())
                {
                    cout << x << " <- " << dist[i] - dist[x] << " -> ";
                    continue;
                }

                y = s.top();
                cout << x << " <- " << getWeight(y, x) << " -> ";
            }
            cout << i << " = " << dist[i] << endl;
            i++;
        }
    }
};

// Output
void solve()
{
    int v, e, src, dest;
    cin >> src >> dest >> v >> e;
    graph g(v);
    vector<int> time;
    for (int i = 0; i < v; i++)
    {
        int t;
        cin >> t;
        time.push_back(t);
    }
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    // cout << "Adjacency List:" << endl;
    // g.printList();
    // cout << endl;
    g.dijkstra(src);
    g.findPath(time, src, dest);
    // g.printDist();
    // g.printParent();
    // g.printPath();
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
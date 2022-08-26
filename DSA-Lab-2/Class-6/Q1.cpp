#include <bits/stdc++.h>
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
using namespace std;

typedef pair<int, int> dt;

class Graph
{
private:
    int vertex;
    list<dt> *adj;

public:
    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new list<dt>[vertex];
    };

    void addEdge(int node1, int node2, int w)
    {
        adj[node1].push_back({node2, w});
        adj[node2].push_back({node1, w});
    }

    void prims()
    {
        }

    void printList(int x)
    {
        for (auto &it : adj[x])
        {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
    }
};

int main()
{
    in;
    out;
    int v, e;
    cin >> v >> e;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a, b, w);
    }
    int check;
    cin >> check;
    g.printList(check);
    return 0;
}
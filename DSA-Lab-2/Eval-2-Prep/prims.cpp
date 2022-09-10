#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

typedef pair<int, int> edge;

class Graph
{
    int V;
    list<edge> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edge>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printAdjacency(int x)
    {
        list<pair<int, int>>::iterator i;
        for (i = adj[x].begin(); i != adj[x].end(); ++i)
        {
            cout << (*i).first << "(" << (*i).second << ")"
                 << " ";
        }

        // for(auto &i: adj[x])
        // cout<<this->V;
    }

    void primMST()
    {
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        int src = 0;
        vector<int> key(V, INF);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        pq.push(make_pair(0, src));
        key[src] = 0;
        while (!pq.empty()) /// While The PQ is not Empty
        {
            int u = pq.top().second; /// catch the top element of PQ
            pq.pop();                /// Remove the top element of PQ
            if (inMST[u] == true)    /// Sanity check ( if the element is already visited)
                continue;
            inMST[u] = true;
            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) /// Exploring all the adjacency vertex of the element
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (inMST[v] == false && weight < key[v]) /// (if it is already visited and if the current explored weight is less than the previously recorded weight)
                {
                    key[v] = weight;               /// key Update with current explored weight
                    pq.push(make_pair(key[v], v)); /// push the (weight, vertex) PQ
                    parent[v] = u;                 /// parent update
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (i == 0)
                continue;
            cout << parent[i] << " <---- " << key[i] << " ---> " << i << endl;
        }
    }
};

int main()
{
    int V, E;
    cin >> V;
    cin >> E;
    // int V = 9;
    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        // g.printAdjacency(4);
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
        // User Input --> u,v,w;
    }

    // int checkVertex;
    // cin >> checkVertex;

    // g.printAdjacency(checkVertex);
    g.primMST();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int V;
    list<edgeWeightPair> *adj;

public:
    Graph(int V) /// Constructer
    {
        this->V = V;
        adj = new list<edgeWeightPair>[V];
    }

    void addEdge(int u, int v, int w) /// adjacency List Development
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printNeighbour(int chk)
    {
        for (auto i = adj[chk].begin(); i != adj[chk].end(); i++)
        {
            cout << (*i).first << " ";
        }
    }

    int printSelectedNeighbourWeight(int src, int chk)
    {
        int weight=0;
        for (auto i = adj[src].begin(); i != adj[src].end(); i++)
        {
            if((*i).first == chk){
                weight = (*i).second;
                break;
            }
                
        }
        
        return weight;

    }

    void Dijkstra(int src)
    {
        priority_queue<edgeWeightPair, vector<edgeWeightPair>, greater<edgeWeightPair>> pq;
        vector<int> dist(V, INF);
        vector<int> parent(V, -1);
        dist[src] = 0;
        pq.push(make_pair(src, dist[src]));

        while (!pq.empty()) /// while(PQ is not empty)
        {
            int u = pq.top().first; /// u = PQ.top.second() ///u=src
            pq.pop();
            for (auto i = adj[u].begin(); i != adj[u].end(); i++) /// for(all the adjacent pairs  i ----> begin--end)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight) /// Relaxation
                {
                    dist[v] = dist[u] + weight; /// dist[v] UPDATE
                    parent[v] = u;
                    pq.push(make_pair(v, dist[v])); /// PUSH INTO PQ
                }
            }
        }
        printf("Vertex Distance from Source: \n");
        for (int i = 0; i < V; i++)
            printf("%d  ----------->  %d\n", i, parent[i]);

        for (int i = 0; i < V; i++)
        {
            cout << i << ": ";
            stack<int> path;
            path.push(i);
            int temp = parent[i]; // 2
            while (temp != -1)
            {
                path.push(temp);
                temp = parent[temp]; // 1
            }
            while (!path.empty())
            {
                int x = path.top();
                cout << x;
                path.pop();
                if(path.empty()) continue;
                cout<< "<-";
                int w;
                int y = path.top();
                // w = printSelectedNeighbourWeight(x, y);
                w = dist[y]-dist[x];
                cout << w;
                // if (path.empty())
                //     break;
                // cout << " --> ";
            }
            cout << " = " << dist[i] << endl;
        }
    }
};

int main()
{
    int V, E;
    cin >> V;
    Graph g(V);
    cin >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    // g.Dijkstra(0);
    for (int i = 0; i < V; i++)
    {
        cout << "Neighbour of " << i << " :";
        g.printNeighbour(i);
        cout << endl;
    }
    // g.printNeighbour(8);
    g.Dijkstra(0);
    // cout << g.printSelectedNeighbourWeight(1,2);
    return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
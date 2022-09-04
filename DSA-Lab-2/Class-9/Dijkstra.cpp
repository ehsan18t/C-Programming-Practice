// HW: # videos from LMS and implement the code (LCS, KMP)

#include <bits/stdc++.h>

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF 10000000

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
        for(auto e: adjList[v])
            cout << e.first << " ";
        cout << endl;
    }

    void printList()
    {
        for(int i = 0; i < v; i++)
            printAdjList(i);
    }
    
    
    void dijk(int src)
    {
        for(int i = 0; i < dist.size(); i++)
            dist[i] = INF;

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
    
    void printDist()
    {
        int i = 0;
        for(auto d: dist)
            cout << i++ << " : " <<  d << endl;
    }
    
    
    void printParent()
    {
        int i = 0;
        for(auto d: parent)
            cout << i++ << " : " <<  d << endl;
    }

    // need to fixed
    int getWeight(int src, int dest)
    {
        for(auto w: adjList[src])
        {
            if(w.first == dest)
                return w.second; 
        }
        return -1;
    }

    void printPath()
    {
        int i = 0;
        for(auto p: parent)
        {
            stack<int> s;
            cout << i << " : ";
            int j = p;
            
            while(j != -1)
            {
                s.push(j);
                j = parent[j];
            }

            while (!s.empty())
            {
                int x = s.top();
                s.pop();
                cout << x << "<- " << getWeight(x, s.top()) << " -> ";
            }
            cout << i << " = " << dist[i] << endl;
            i++;
        }
    }
};


// Output
void solve()
{
    int v, e, src;
    cin >> v >> e >> src;
    graph g(v);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    // cout << "Adjancy List:" << endl;
    // g.printList();
    // cout << endl;
    g.dijk(src);
    // g.printDist();
    // g.printParent();
    g.printPath();
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
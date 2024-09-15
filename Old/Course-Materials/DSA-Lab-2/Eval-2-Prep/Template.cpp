#include <bits/stdc++.h>
#define INF 99999999

// In/out
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;

/////////////////////
//                 //
//     Solution    //
//                 //
/////////////////////

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// Input Array
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

#define input2d(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define cumulative_sum(arr, out, n) \
    out[0] = arr[0];                \
    for (int i = 1; i < n; i++)     \
        out[i] = out[i - 1] + arr[i];

#define get_sum_i_to_j(out, i, j) (out[j] - out[i - 1])
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

typedef pair<int, int> edge;

class graph
{
    int totalWeight;
    int V;
    list<edge> *adj;
    int weights[100][100];

public:
    graph(int V)
    {
        this->V = V;
        adj = new list<edge>[V];
        totalWeight = 0;
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
                    // cout << "Test: " << v << endl;
                    key[v] = weight;               /// key Update with current explored weight
                    pq.push(make_pair(key[v], v)); /// push the (weight, vertex) PQ
                    parent[v] = u;                 /// parent update
                    totalWeight += weight;         /// total weight update
                }
            }
        }
    }

    void assignZero(int u, int v)
    {
        weights[u][v] = adj[u].front().second;
        weights[v][u] = adj[v].front().second;
        adj[u].front().second = 0;
        adj[v].front().second = 0;
    }

    void assignOriginal(int u, int v)
    {
        adj[u].front().second = weights[u][v];
    }

    int mstWeight()
    {
        return totalWeight;
    }
};

void solve(int cnt)
{
    int v, e, q;
    cin >> v >> e >> q;
    graph g(v);

    // input edges
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }

    // generate tree
    g.primMST();
    // g.printAdjacency(1);

    // query
    while (q--)
    {
        int opt, a, b;
        cin >> opt;
        switch (opt)
        {
        case 1:
            a, b;
            cin >> a >> b;
            g.assignZero(a, b);
            break;
        case 2:
            a, b;
            cin >> a >> b;
            g.assignOriginal(a, b);
            break;
        case 3:
            cout << g.mstWeight() << endl;
            break;
        default:
            break;
        }
    }
}

int main()
{
    in;
    out;
    int n = 1, i = 1;
    // cin >> n;
    while (n--)
        solve(i++);
    return 0;
}

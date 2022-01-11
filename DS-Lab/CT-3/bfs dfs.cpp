#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> bfs(int vertices, int starting_node, vector<int> adjacentList[])
{
    vector<int> result;
    queue<int> Q;
    int visited[vertices] = {0};

    Q.push(starting_node);

    while (!Q.empty())
    {
        int visiting_node = Q.front();
        Q.pop();

        if (visited[visiting_node] == 1)
            continue;

        for (int i = 0; i < adjacentList[visiting_node].size(); i++)
        {
            int child = adjacentList[visiting_node][i];
            if (visited[child] == 0)
                Q.push(child);
        }

        visited[visiting_node] = 1;
        result.push_back(visiting_node);
    }
    return result;
}

vector<int> dfs(int vertices, int starting_node, vector<int> adjacentList[])
{
    vector<int> result;
    stack<int> stk;
    int visited[vertices] = {0};

    stk.push(starting_node);

    while (!stk.empty())
    {
        int visiting_node = stk.top();
        stk.pop();

        if (visited[visiting_node] == 1)
            continue;

        for (int i = 0; i < adjacentList[visiting_node].size(); i++)
        {
            int child = adjacentList[visiting_node][i];
            if (visited[child] == 0)
                stk.push(child);
        }

        visited[visiting_node] = 1;
        result.push_back(visiting_node);
    }
    return result;
}

void print_vec(vector<int> vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertices, edges;
    int starting_node;

    cin >> vertices >> edges;

    // Create an adjacency list
    vector<int> adjacentList[vertices];
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cin >> source >> destination;
        adjacentList[source].push_back(destination);
    }

    // dfs bfs
    cin >> starting_node;
    vector<int> result_dfs = dfs(vertices, starting_node, adjacentList);
    vector<int> result_bfs = bfs(vertices, starting_node, adjacentList);

    // print result
    cout << "DFS for the graph is " << endl;
    print_vec(result_dfs);

    cout << "BFS for the graph is " << endl;
    print_vec(result_bfs);
}
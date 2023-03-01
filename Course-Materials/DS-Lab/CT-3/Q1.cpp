#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int vertices, int starting_node, vector<int> adjacentList[])
{
    vector<int> result;
    stack<int> stk;
    int visited[vertices] = {0};

    stk.push(starting_node);
    int visiting_node;

    while (!stk.empty())
    {
        visiting_node = stk.top();
        stk.pop();

        if (visited[visiting_node] == 1)
            continue;

        for (int i = 0; i < adjacentList[visiting_node].size(); i++)
        {
            int child = adjacentList[visiting_node][i];
            if (visited[child] == 0)
                stk.push(child);
            else
                return true;
        }

        visited[visiting_node] = 1;
        result.push_back(visiting_node);
    }
    return false;
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

    // dfs
    for (int i = 0; i < vertices; i++)
    {
        if (dfs(vertices, i, adjacentList))
        {
            cout << "Cycle found" << endl;
            return 0;
        }
    }
    cout << "No cycle found" << endl;
}
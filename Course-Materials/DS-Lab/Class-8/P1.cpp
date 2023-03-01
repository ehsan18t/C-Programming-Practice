#include <bits/stdc++.h>

#define V 5

void init(int arr[][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

// to indicate an edge from source to destination
void addEdge(int arr[][V], int src, int dest)
{
    arr[src][dest] = 1;
    arr[dest][src] = 1; // only for undirected graph
}

void print(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    int matrix[V][V];
    init(matrix);

    // 0
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 4);

    // 1
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 3);
    addEdge(matrix, 1, 4);

    // 2
    addEdge(matrix, 2, 3);

    // 3
    addEdge(matrix, 3, 4);

    // 4
    // all are connected

    // print
    print(matrix);
    return 0;
}

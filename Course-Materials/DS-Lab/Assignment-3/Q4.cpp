#include <iostream>
using namespace std;

// It's the same code from last class, with a little modification.

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

void printMatrix(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void printAdj(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < V; j++)
            if (arr[i][j] != 0)
                cout << j << " ";
        cout << endl;
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

    // print
    cout << endl
         << "Matrix:" << endl;
    printMatrix(matrix);
    cout << endl
         << "Adjecency List:" << endl;
    printAdj(matrix);
    return 0;
}

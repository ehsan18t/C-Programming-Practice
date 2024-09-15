#include <stdio.h>

int main()
{
    char vertex[26];
    int i, j, number_of_vertex, graph[100][100];

    for (int i = 0; i < 26; i++)
    {
        vertex[i] = i + 65;
        //printf("%c ", vertex[i]);
    }

    printf("Enter the no of vertices: ");
    scanf("%d", &number_of_vertex);

    //making th graph 00
    for (i = 0; i < number_of_vertex; i++)
    {
        for (j = 0; j < number_of_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    //asking the user to initialize ther graph
    for (i = 0; i < number_of_vertex; i++)
    {
        for (j = i + 1; j < number_of_vertex; j++)
        {
            printf("%c-%c: ", vertex[i], vertex[j]);
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
            {
                graph[j][i] = 1;
            }
        }
    }

    char input;
    getchar();
    printf("Input Node: ");
    scanf("%c", &input);

    for (i = 0; i < number_of_vertex; i++)
    {
        if (vertex[i] == input)
        {
            printf("%c=> ", vertex[i]);

            for (j = 0; j < number_of_vertex; j++)
            {
                if (graph[i][j] == 1)
                {
                    printf("%c ", vertex[j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}

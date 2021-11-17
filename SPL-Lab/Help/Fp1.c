#include <stdio.h>

int main()
{
    int M, N;
    int k = 0;
    int arr2D[100][100];
    int arr1D[100];
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr2D[i][j]);
            // suig in this loop insted using snother loop
            arr1D[k] = arr2D[i][j];
            k++;
        }
    }

    for (int i = 0; i < k - 1; i++)
    {
        printf("%d, ", arr1D[i]);
    }
    printf("%d", arr1D[k - 1]);
    return 0;
}
#include <stdio.h>

int main()
{
    int n;
    int min, max_index;

    // input n
    scanf("%d", &n);
    int arr[n][n];

    // input nxn array
    printf("Enter number:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    // initializing min and max
    min = arr[0][0];
    max_index = 0;

    // findig min
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > arr[i][j])
                min = arr[i][j];
        }
    }

    printf("Minimum is: %d\n", min);

    // replacing max with min
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] > arr[max_index][i])
                max_index = j;
        }
        arr[max_index][i] = min;
        max_index = 0;
    }

    // printing array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int n, half;
    int result = 0;
    int arr[100][100];
    scanf("%d", &n);
    half = n / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= half; i++)
    {
        if (i != half)
        {
            result += arr[i][half];
            result += arr[half + i][half];
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                // mid line
                result += arr[half][j];
            }
            for (int j = 0; j <= half; j++)
            {
                // first line
                result += arr[0][j];
                // last line
                result += arr[n - 1][half + j];
            }
            for (int j = 0; j < half; j++)
            {
                // side case
                result += arr[j][n - 1];
            }
            for (int j = 0; j < half; j++)
            {
                // side case
                result += arr[half + 1 + j][0];
            }
        }
    }

    printf("%d", result);
    return 0;
}
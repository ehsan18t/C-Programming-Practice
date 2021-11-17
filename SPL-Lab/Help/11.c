#include <stdio.h>

int main()
{
    int arr[100][100];
    int n, half;
    int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (j % 2 == 1)
                {
                    result += arr[i][j];
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                result += arr[i][j];
            }
        }
    }

    printf("%d", result);
    return 0;
}
#include <stdio.h>

int main()
{
    int arr[4][4];
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] % 2 == 1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("* ", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
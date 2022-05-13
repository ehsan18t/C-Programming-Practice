#include <stdio.h>

int main()
{
    int arr[50][50];
    int n, m, val, flag = 0;
    int row, col;

    // input
    printf("Enter Row Size: ");
    scanf("%d", &n);
    printf("Enter Column Size: ");
    scanf("%d", &m);
    printf("Enter Array: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    printf("Enter Search Value: ");
    scanf("%d", &val);

    // search
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == val)
            {
                row = i;
                col = j;
                flag = 1;
                break;
            }
        }
    }

    if (flag)
        printf("Found at row: %d, col: %d\n", row, col);
    else
        printf("Not Found!");

    return 0;
}
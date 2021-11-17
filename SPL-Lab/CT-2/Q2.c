#include <stdio.h>
int main()
{
    int n, row, col, num;
    scanf("%d", &n);
    num = n + 1;
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= n - row; col++)
        {
            printf("  ");
        }
        for (col = 1; col <= row; col++)
        {
            printf("%d ", num - col);
        }

        for (col = row - 1; col >= 1; col--)
        {
            printf("%d ", num - col);
        }
        printf("\n");
    }
}
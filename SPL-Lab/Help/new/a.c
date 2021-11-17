#include <stdio.h>
int main()
{
    int i, j, k, n;
    scanf("%d", &n);
    k = n;
    for (i = 0; i < (n * 2) - 1; i++)
    {
        for (j = k; j >= 1; j--)
        {
            printf("%d ", j);
        }
        for (j = 0; j < 2 * 2 * (n - k) - 2; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= k; j++)
        {
            if (j != 1 || k != 6)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
        if (i < 5)
            k--;
        if (i >= 5)
            k++;
    }
}
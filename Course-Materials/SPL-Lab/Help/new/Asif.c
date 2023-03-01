#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // Part 1
    for (int i = 0; i < n; i++)
    {
        // first half
        for (int j = n - i; j > 0; j--)
        {
            printf("%d ", j);
        }

        // space
        for (int j = 0; j < i; j++)
        {
            printf("  ");
            if (j < n && j != 0)
                printf("  ");
        }

        // socond half
        if (i != 0)
            printf("1 ");
        for (int j = 2; j <= n - i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    // Part 2
    for (int i = 2; i < n + 1; i++)
    {
        // first half
        for (int j = i; j > 0; j--)
        {
            printf("%d ", j);
        }
        // space
        for (int j = i; j < n; j++)
        {
            printf("  ");
            if (j < n - 1)
                printf("  ");
        }
        // socond half
        if (i != n)
            printf("1 ");
        for (int j = 2; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
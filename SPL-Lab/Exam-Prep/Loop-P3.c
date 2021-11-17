#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        printf("%d, ", i%2);
    }
    printf("%d\n", i%2);
    return 0;
}
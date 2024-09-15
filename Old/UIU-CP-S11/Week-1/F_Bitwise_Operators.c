#include <stdio.h>

int main()
{
    int n, k;
    int max_and = 0, max_or = 0, max_xor = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int tmp = i & j;
            max_and = (tmp > max_and) && tmp < k ? tmp : max_and;

            tmp = i | j;
            max_or = (tmp > max_or) && tmp < k ? tmp : max_or;

            tmp = i ^ j;
            max_xor = (tmp > max_xor) && tmp < k ? tmp : max_xor;
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
    return 0;
}
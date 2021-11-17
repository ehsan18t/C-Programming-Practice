#include <stdio.h>

int main() 
{
    int n;
    int sum = 0, c2 = 1, c1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        c1 += 2;
        c2 += 2;
        sum += c1 * c2;
    }
    printf("%d\n", sum);
    return 0;
}
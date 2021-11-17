#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    int sum = 0;
    scanf("%d", &n);
    m = sqrt(n);
    for (int i = 1; i <= m; i++)
    {
        if (n%i == 0)
            sum +=i;
    }
    if (sum == n)
        printf("%d is a perfect number\n", n);
    else
        printf("%d is not a perfect number\n", n);
    return 0;
}
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    // find the cubic root of n without library function
    double x = n;
    double x1 = x / 3;
    while (x - x1 > 0.005 || x - x1 < -0.005)
    {
        x = x1;
        x1 = (2 * x + n / (x * x)) / 3;
    }
    printf("%.3lf\n", n, x1);
}
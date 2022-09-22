#include <stdio.h>

int main()
{
    int num;
    double a, div;
    printf("Enter the number: ");
    scanf("%d", &num);

    a = num;
    div = a / 3;
    while (a - div > 0.00001 || a - div < -0.00001)
    {
        a = div;
        div = (2 * a + num / (a * a)) / 3;
    }
    printf("%.3lf\n", div);
}
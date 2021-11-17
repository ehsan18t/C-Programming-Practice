#include <stdio.h>

int main()
{
    int n, input;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        sum += input;
    }
    printf("AVG of %d inputs: %lf\n", n, sum/n);
    return 0;
}
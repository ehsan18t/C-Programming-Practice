#include <stdio.h>
#include <math.h>

int main() {
    int x;
    int sum = 0, c = 1;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        c += 2;
        if (i % 2 == 0)
            sum += (int)(pow(x, c));
        else
            sum -= (int)(pow(x, c));
    }
    printf("%d\n", sum);
    return 0;
}
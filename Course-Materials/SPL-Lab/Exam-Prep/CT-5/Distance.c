#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} X;


int main()
{
    double distance;
    X a, b;
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);
    distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
    printf("%.2lf \n", distance);
    return 0;
}
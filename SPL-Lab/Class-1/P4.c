#include <stdio.h>
// Grade Calculator

int main() {
    int x;
    scanf("%d", &x);
    if (x >= 90)
    {
        printf("A\n");
    }
    else if (x >= 86)
    {
        printf("A-\n");
    }
    else if (x >= 80)
    {
        printf("B+\n");
    }
    else if (x >= 70)
    {
        printf("C+\n");
    }
    else
    {
        printf("F\n");
    }
    return 0;
}
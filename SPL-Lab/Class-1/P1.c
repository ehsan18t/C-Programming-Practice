#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x % 15 == 0)
    {
        printf("C\n");
    }
    else if (x % 5 == 0)
    {
        printf("B\n");
    }
    else if (x % 3 == 0)
    {
        printf("A\n");
    }
    return 0;
}
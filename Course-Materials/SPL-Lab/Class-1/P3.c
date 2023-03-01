#include <stdio.h>
// Leap Year Finder

int main() {
    int x;
    scanf("%d", &x);
    if (x % 400 == 0)
    {
        printf("Leap Year\n");
    }
    else
    {
        if (x % 100 == 0)
        {
            printf("Not Leap Year\n");
        }
        else if (x % 4 == 0)
        {
            printf("Leap Year\n");
        }
    }
    return 0;
}
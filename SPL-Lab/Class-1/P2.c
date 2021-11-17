#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x % 30 == 0)
    {
        printf("fi-fie-foo-fum\n");
    }
    else if (x % 6 == 0)
    {
        printf("fi-fie\n");
    }
    else if (x % 15 == 0)
    {
        printf("fie-foo\n");
    }
    else if (x % 10 == 0)
    {
        printf("fi-foo\n");
    }
    else if (x % 2 == 0)
    {
        printf("fi\n");
    }
    else if (x % 3 == 0)
    {
        printf("fie\n");
    }
    else if (x % 5 == 0)
    {
        printf("foo\n");
    }
    return 0;
}
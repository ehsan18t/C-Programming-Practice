#include <stdio.h>

int main()
{
    int a = 123 % 17 + 3; // a: ID % 17 + 3
    int b = 12 % 21 + 5;  // b: ID % 21 + 5
    int c;
    scanf("%d", &c);    // c
    if (c > a && c > b) // d
    {
        if (c % 2 == 0)
            printf("c is the largest and even\n");
        else
            printf("c is the largest and odd\n");
    }
    if (c > a && c > !b) // e
    {
        if (c % 3 == 0)
            printf("c crossed a and divisible by 3\n");
        else
            printf("c is not divisible by 3\n");
    }
    if (c > b && c > !a) // f
    {
        if (c % 5 == 0)
            printf("c crossed b and divisible by 5\n");
        else
            printf("c is not divisible by 5\n");
    }

    return 0;
}
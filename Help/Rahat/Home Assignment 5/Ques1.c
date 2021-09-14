#include <stdio.h>

int is_even(int number)
{
    return (number % 2 == 0);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (is_even(n))
        printf("The number is even.\n");
    else
        printf("The number is odd.\n");
    return 0;
}
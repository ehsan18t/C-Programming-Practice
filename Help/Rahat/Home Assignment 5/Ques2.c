#include <stdio.h>

// function declarations
int calc_power(int, int);

int main()
{
    int x, y, result;
    printf("Enter x and y : ");
    scanf("%d%d", &x, &y);
    result = calc_power(x, y);
    printf("The result is: %d\n", result);
    return 0;
}

int calc_power(int num1, int num2)
{
    // checking if num is negative
    if (num1 < 0 || num2 < 0)
        printf("Negative number not allowed!\n");

    // calculating power
    int result = 1;
    while (num2 > 0)
    {
        result *= num1;
        num2--;
    }
    return result;
}
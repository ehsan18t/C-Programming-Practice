#include <stdio.h>

int main()
{
    int a = 1234;        // last 4 digit of id
    int b = 12 % 21 + 5; // last 2 digit % 21 + 5
    int A[10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        A[i] = a % 7 + (3 * i);

        if (i % 2 == 0)
            sum += A[i];
    }
    printf("Sum: %d\n", sum);
    return 0;
}
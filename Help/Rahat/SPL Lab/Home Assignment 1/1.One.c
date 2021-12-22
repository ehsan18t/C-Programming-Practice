// Write a program that will take 10 positive integers into an array A. Now find all the integers that are
// divisible by 3 and replace them by ‐1 in array A.Finally show all elements of array A.

#include <stdio.h>

int main()
{
    int A[10], i;

    // take 10 integers into an array A
    printf("Enter the numbers: ");
    for (i = 0; i < 10; i++)
        scanf("%d", &A[i]);

    // find all the integers that are divisible by 3 and replace them by ‐1 in array A
    for (i = 0; i < 10; i++)
        if (A[i] % 3 == 0)
            A[i] = -1;

    // show all elements of array A
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
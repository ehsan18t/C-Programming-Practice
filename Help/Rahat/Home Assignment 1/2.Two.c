// Write a program that will take 10 integers into an array A, and then copy all numbers in reverse order
// from array A to another array B.Finally show all elements of both array A and B.

#include <stdio.h>

int main()
{
    int A[10], B[10], i;

    // taking input
    printf("Enter the numbers: ");
    for (i = 0; i < 10; i++)
        scanf("%d", &A[i]);

    // copying input to another array in reverse order
    for (i = 0; i < 10; i++)
        B[i] = A[9 - i];

    // printing all elements of arrays A
    printf("Array A: ");
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);

    // printing all elements of arrays B
    printf("\nArray B: ");
    for (i = 0; i < 10; i++)
        printf("%d ", B[i]);

    return 0;
}
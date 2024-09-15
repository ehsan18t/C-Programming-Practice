// Write a program that will take n integers into an array, and then search a number into that array. If
// found then print its index.If not found then print “NOT FOUND”.

#include <stdio.h>

int main()
{
    int n, i, b;
    int a[100];
    printf("How many numbers: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the search key: ");
    scanf("%d", &b);

    for (i = 0; i < n; i++)
        if (a[i] == b)
        {
            printf("%d\n", i);
            return 0;
        }
    printf("NOT FOUND\n");
    return 0;
}
// Write a program in C to count the frequency of each element of an array of size 15(Assume the
// elements can be from 0 to 9).

#include <stdio.h>

int main()
{
    int arr[15], i;

    // initialize the array with 0
    int count[10] = {0};

    // read the array elements then count the frequency of each element and saving them in count array
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    // print the count array
    for (i = 0; i < 10; i++)
        printf("%d ", count[i]);

    return 0;
}

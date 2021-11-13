#include <stdio.h>

// take some input in an array and
// find the minimum.

int main()
{
    int n = 5;
    int minIndex = 0;
    int arr[n];

    // taking input
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // finding min index
    for (int i = 1; i < n; i++)
        if(arr[1] < arr[minIndex])
            minIndex = i;

    // printing output
    printf("%d", arr[minIndex]);
    return 0;
}

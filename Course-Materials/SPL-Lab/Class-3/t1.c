#include <stdio.h>

int main() {
    int arr[100];
    int n;
    int min, max;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // initializing with first value
        if (i == 0)
        {
            max = arr[i];
            min = arr[i];
        }
        // checking for max value
        if (arr[i] > max)
            max = arr[i];
        // checking for minimum value
        if (arr[i] < min)
            min = arr[i];
    }
    printf("Difference between Max and Min: %d\n", max-min);
    return 0;
}
#include <stdio.h>

// take some input in an array and
// search an element.

int main()
{
    int n, num;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    int arr[n];

    // generating random numbers in array
    generateRandom(arr, n);

    // input number
    printf("Input Number to Search: ");
    scanf("%d", &num);

    // printing all elements
    printf("\n\nArray: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // search
    for (int i = 0; i < n - 1; i++)
    {
        if (num == arr[i])
        {
            printf("\n\nFound on Index %d.\n", i);
            return 0;
        }
    }
    printf("\n\nNot Found!\n");
    return 0;
}

void generateRandom(int arr[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 1000;
    }
}

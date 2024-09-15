#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate Random Number
void generateRand(int arr[], int size)
{
    int start = 1;
    int end = 100;
    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

// print most occurring numbers
void printMostOccurring(int arr[], int size)
{
    int count[100] = {0};
    for (int i = 0; i < size; i++)
        count[arr[i] - 1]++;
    int max = 0;
    for (int i = 0; i < 100; i++)
        if (count[i] > max)
            max = count[i];
    for (int i = 0; i < 100; i++)
        if (count[i] == max)
            printf("%d ", arr[i]);
    printf("occurred %d times\n", max);
}

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    generateRand(arr, size);
    printMostOccurring(arr, size);
    return 0;
}
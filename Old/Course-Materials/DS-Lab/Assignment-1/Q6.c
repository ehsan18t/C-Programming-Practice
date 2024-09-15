#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int[], int);
void swap(int *, int *);
void bubbleSort(int[], int);
void readIntArrayFromFile(int[], char[]);
void writeIntArrayToFile(int[], int, char[]);

int main()
{
    int n = 500;
    int *arr = (int *)malloc(sizeof(char) * n);
    generateArray(arr, 500);
    writeIntArrayToFile(arr, 500, "in.txt");
    readIntArrayFromFile(arr, "in.txt");
    bubbleSort(arr, 500);
    writeIntArrayToFile(arr, 500, "out.txt");
    free(arr);
    return 0;
}

// generate random integer numbers in the range from -249 to 250
void generateArray(int arr[], int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        // formula: rand() % (max_number + 1 - minimum_number) + minimum_number
        arr[i] = rand() % (250 + 1 + 249) - 249;
    }
}

// function to swap two elements using pointer
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to sort a int array using bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// read int from a text file and store it in an array
void readIntArrayFromFile(int arr[], char fileName[])
{
    int i = 0;
    FILE *fp; // File pointer
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d", &arr[i]);
        i++;
    }
    fclose(fp);
}

// write int array to a text file
void writeIntArrayToFile(int arr[], int size, char fileName[])
{
    int i;
    FILE *fp; // File pointer
    fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    for (i = 0; i < size; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

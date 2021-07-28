#include <stdio.h>
#include <stdlib.h>

/*
  Write a program that will randomly generate 500 integer numbers in the range -249 to 250. Write those
  numbers in a text file named “in.txt”. Now Sort (in ascending order) all the integer numbers in the file “in.txt”
  using Bubble Sort. Save the sorted output into another text file named “out.txt”. (Try to write separate
  function for SWAP and BUBBLE_SORT and call them from main function.)
*/

void randomIntGen(int[], int);
void swap(int *, int *);
void bubbleSort(int[], int);
void readIntArrayFromFile(int[], char[]);
void writeIntArrayToFile(int[], int, char[]);

int main()
{
    int arr[500];
    randomIntGen(arr, 500);
    writeIntArrayToFile(arr, 500, "in.txt");
    readIntArrayFromFile(arr, "in.txt");
    bubbleSort(arr, 500);
    writeIntArrayToFile(arr, 500, "out.txt");
    return 0;
}

// generate random integer numbers in the range from -249 to 250
void randomIntGen(int arr[], int size)
{
    int i;
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

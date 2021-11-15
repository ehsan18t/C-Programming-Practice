#include <stdio.h>
#include <stdlib.h>

void generateArray(char arr[], int size);
void insertionSort(char arr[], int n);
void readIntArrayFromFile(char arr[], char fileName[]);
void writeIntArrayToFile(char arr[], char fileName[]);
void printCharArrayToConsole(char arr[]);

int main()
{
    int n = 1001;
    char *arr = (char *)malloc(sizeof(char) * n);
    generateArray(arr, 1000);
    writeIntArrayToFile(arr, "in.txt");
    readIntArrayFromFile(arr, "in.txt");
    insertionSort(arr, 1000);
    printCharArrayToConsole(arr);
    free(arr);
    return 0;
}

// generate random upper case characters
void generateArray(char arr[], int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        arr[i] = (char)(rand() % 26 + 65);
    }
    arr[i] = '\0';
}

//function to sort a char array using insertion sort
void insertionSort(char arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // Storing current element & previous index
        int current = arr[i];
        int j = i - 1;

        // shifting previous element(s) to right if it's bigger than current
        while (j > -1 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        // placing current element to right position
        arr[j + 1] = current;
    }
}

// read char from a text file and store it in an array
void readIntArrayFromFile(char arr[], char fileName[])
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
        fscanf(fp, "%c", &arr[i]);
        i++;
    }
    arr[i] = '\0';
    fclose(fp);
}

// write char array to a text file
void writeIntArrayToFile(char arr[], char fileName[])
{
    FILE *fp; // File pointer
    fp = fopen(fileName, "w");
    while (*arr != '\0')
    {
        fprintf(fp, "%c", *arr);
        arr++;
    }
    fclose(fp);
}

// print out the array to console
void printCharArrayToConsole(char arr[])
{
    int i = 0;
    while (arr[i] != '\0')
    {
        printf("%c", arr[i]);
        i++;
    }
}

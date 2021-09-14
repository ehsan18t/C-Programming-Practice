#include <stdio.h>
#include <math.h>

// funcion declarations
double calc_std(int[], int);
double calc_mean(int[], int);

int main()
{
    int n;
    double mean, dev;

    printf("How many numbers? ");
    scanf("%d", &n);
    int array[n];

    // input array
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    mean = calc_mean(array, n);
    dev = calc_std(array, n);

    printf("Mean: %.2lf\n", mean);
    printf("Standard deviation: %.4lf\n", dev);
    return 0;
}

// calculate mean
double calc_mean(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return sum / size;
}

// calculate std deviation
double calc_std(int array[], int size)
{
    double mean = calc_mean(array, size);
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += (array[i] - mean) * (array[i] - mean);
    return sqrt(sum / size);
}
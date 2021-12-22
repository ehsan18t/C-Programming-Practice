#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sum, avg, max;
    double *ptr;
    int n;
    FILE *fp;

    // open file
    fp = fopen("Q2_Input.txt", "r");
    if (fp == NULL)
    {
        printf("File open failed!\n");
        exit(1);
    }

    // read number of data
    fscanf(fp, "%d", &n);

    // Allocate memory for n elements
    ptr = (double *)malloc(n * sizeof(double));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // read elements
    for (int i = 0; i < n; i++)
        fscanf(fp, "%lf", ptr + i);

    fclose(fp);

    // sum & max
    sum = 0;
    max = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
        if (*(ptr + i) > max)
            max = *(ptr + i);
    }

    // avg
    avg = sum / n;

    // output to file
    fp = fopen("Q2_Output.txt", "w");
    if (fp == NULL)
    {
        printf("File open failed!\n");
        exit(1);
    }

    fprintf(fp, "Sum = %.2lf\n", sum);
    fprintf(fp, "Avg = %.2lf\n", avg);
    fprintf(fp, "Max = %.2lf\n", max);

    fclose(fp);
    return 0;
}

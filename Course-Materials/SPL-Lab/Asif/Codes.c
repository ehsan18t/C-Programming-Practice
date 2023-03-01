#include <stdio.h>
#include <stdlib.h>

// Q1
struct student
{
    char name[50];
    char id[20];
    float marks[3][4];
    float cgpa;
};

// Q2 inside main function

// Q3
void print(struct student st[])
{
    FILE *fp;
    fp = fopen("output.txt", "a");

    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "Student %d:\n", i + 1);
        fprintf(fp, "Name: %s\n", st[i].name);
        fprintf(fp, "Id: %s\n", st[i].id);
        for (int j = 0; j < 3; j++)
        {
            fprintf(fp, "Subject %d: ", j + 1);
            for (int k = 0; k < 4; k++)
            {
                fprintf(fp, "%.0f ", st[i].marks[j][k]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "%.1f", st[i].cgpa);
        fprintf(fp, "\n");
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Q4
void printtotal(struct student st[])
{
    FILE *fp;
    fp = fopen("output.txt", "a");

    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "Student %d: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            float total = 0;
            fprintf(fp, "Subject %d total: ", j + 1);
            for (int k = 0; k < 4; k++)
            {
                total += st[i].marks[j][k];
            }
            fprintf(fp, "%.0f\n\t\t   ", total);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Q5
int maxCGPA(struct student st[])
{
    FILE *fp;
    fp = fopen("output.txt", "a");
    float max = st[0].cgpa;
    for (int i = 1; i < 10; i++)
    {
        if (st[i].cgpa > max)
            max = st[i].cgpa;
    }
    fprintf(fp, "Maximum CGPA: %.1f\n", max);
    fclose(fp);
}

int minCGPA(struct student st[])
{
    FILE *fp;
    fp = fopen("output.txt", "a");
    float min = st[0].cgpa;
    for (int i = 1; i < 10; i++)
    {
        if (st[i].cgpa < min)
            min = st[i].cgpa;
    }
    fprintf(fp, "Minimum CGPA: %.1f\n", min);
    fclose(fp);
}

int main()
{
    FILE *fp;
    struct student st[10];
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("file does not exist\n");
        exit(0);
    }
    // Q2 - input
    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%s", &st[i].name);
        fscanf(fp, "%s", &st[i].id);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                fscanf(fp, "%f", &st[i].marks[j][k]);
            }
        }
        fscanf(fp, "%f", &st[i].cgpa);
    }
    fclose(fp);

    // Clearing output file
    fp = fopen("output.txt", "w");
    fclose(fp);

    // output
    print(st);
    printtotal(st);
    maxCGPA(st);
    minCGPA(st);
    return 0;
}
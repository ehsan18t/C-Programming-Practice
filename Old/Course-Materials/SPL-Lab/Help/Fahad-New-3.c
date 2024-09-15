#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int marks;
    float cgpa;
} student;

int main()
{
    student all[100];
    int count = 0;
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s%d%f", &all[count].name, &all[count].marks, &all[count].cgpa);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %.2f\n", all[i].name, all[i].marks, all[i].cgpa);
    }
    fclose(fp);
    return 0;
}
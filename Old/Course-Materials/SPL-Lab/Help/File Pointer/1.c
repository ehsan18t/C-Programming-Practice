#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[12];
    char name[100];
} Student;

int main()
{
    int n;
    Student all[100];
    FILE *fptr;
    char address[] = "input.txt";
    fptr = fopen(address, "r");

    fscanf(fptr, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fptr, "%s%s", &all[i].id, &all[i].name);
    }

    fclose(fptr);

    for (int i = 0; i < n; i++)
    {
        char address[100] = "output\\";
        strcat(address, all[i].id); // output\\011201122
        strcat(address, ".txt");    // output\\011201122.txt
        fptr = fopen(address, "w");
        fprintf(fptr, "Name: %s\nID: %s\n", all[i].name, all[i].id);
        fclose(fptr);
    }
}

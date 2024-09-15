#include <stdio.h>
#include <stdlib.h>

/*
input.txt
A 1 12 160
B 2 13 170
C 3 11 120
D 4 7 100
E 5 14 180
7 12



output.txt
All students info:
A 1 12 160
B 2 13 170
C 3 11 120
D 4 7 100
E 5 14 180

Top 4 students info:
A 1 12 160
B 2 13 170
C 3 11 120
E 5 14 180

Students in range:
A 1 12 160
C 3 11 120
D 4 7 100
*/

struct student
{
    char name[20];
    int id;
    int age;
    int iq;
} typedef student;

void read_input(student s[], int n, int *start_age, int *end_age);
void write_student_array(student s[], int n, char mode[], char str[]);
void find_top_4_iq(student s[], int n, student top[]);
int find_st_in_range(student s[], int n, int age_start, int age_end, student result[]);

int main()
{
    int n = 5;
    student info[n];
    student top[4];
    student result[n];
    int result_len;
    int age_start;
    int age_end;
    read_input(info, n, &age_start, &age_end);
    write_student_array(info, n, "w", "All students info:\n");
    find_top_4_iq(info, n, top);
    write_student_array(top, 4, "a+", "\nTop 4 students info:\n");

    result_len = find_st_in_range(info, n, age_start, age_end, result);
    write_student_array(result, result_len, "a+", "\nStudents in range:\n");
    return 0;
}

// function to read student array from file
void read_input(student s[], int n, int *start_age, int *end_age)
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d %d %d", s[i].name, &s[i].id, &s[i].age, &s[i].iq);
    }
    fscanf(fp, "%d", start_age);
    fscanf(fp, "%d", end_age);
    fclose(fp);
}

// function to write student array from file
void write_student_array(student s[], int n, char mode[], char str[])
{
    FILE *fp;
    fp = fopen("output.txt", mode);

    fprintf(fp, str);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d %d %d\n", s[i].name, s[i].id, s[i].age, s[i].iq);
    }
    fclose(fp);
}

// function to find 4 students with highest iq
void find_top_4_iq(student s[], int n, student top[])
{
    int lowest = s[0].iq;
    for (int i = 0; i < n; i++)
    {
        if (s[i].iq < lowest)
        {
            lowest = s[i].iq;
        }
    }

    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s[i].iq > lowest)
        {
            top[j] = s[i];
            j++;
        }
        i++;
    }
}

// find student within age range
int find_st_in_range(student s[], int n, int age_start, int age_end, student result[])
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s[i].age >= age_start && s[i].age <= age_end)
        {
            result[j] = s[i];
            j++;
        }
        i++;
    }
    return j;
}

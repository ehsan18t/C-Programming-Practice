#include <stdio.h>

struct student_info
{
    // initialozing values inside structure is invalid
    // so, (ii) is not possible
    char student_ID[20];
    char student_name[20];
    float marks[5];
} typedef student_info;

int main()
{
    int size = 1252 % 11 + 10;
    student_info students[size];

    for (int i = 0; i < size; i++)
    {
        gets(students[i].student_ID);
        gets(students[i].student_name);
        for (int j = 0; j < 5; j++)
            scanf("%f", &students[j].marks);
    }

    return 0;
}
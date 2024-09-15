#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// "stdlib.h" is necessary for "exit()" function.
// IDE gives warning (but compile & works) without it.

//--------------------------------------------------------------------------------------------
#define OUTPUT_FOLDER "Output"
#ifdef _WIN32
// [Windows] This function checks if folder not exist than create one using windows CMD.
void create_folder_if_not_exist(char path[])
{
    char command[256] = "";
    // "IF NOT EXIST" and "MKDIR" are windows CMD statement
    sprintf(command, "IF NOT EXIST \"%s\" MKDIR \"%s\"", path, path);
    system(command);
}
#else
// [Linux] This function checks if folder not exist than create one using Bash Terminal.
// Should works on MacOS as well.
// TESTED ON: UbuntuDDE 20.10
void create_folder_if_not_exist(char path[])
{
    char command[256] = "";
    // "mkdir -p" does the same thing like windows version
    sprintf(command, "mkdir -p %s", path);
    system(command);
}
#endif
//--------------------------------------------------------------------------------------------

struct student_marks
{
    char id[10];
    int bangla;
    int english;
    int math;
};

// making it easier to use by adding an alias.
typedef struct student_marks Student;

float calc_grade(int mark)
{
    // return the grade according to mark
    // 100-80: 4.00     --> 0
    // 79-75: 3.75      --> 1
    // 74-70: 3.50      --> 2
    // 69-65: 3.25      --> 3
    // 64-60: 3.00      --> 4
    // 59-55: 2.75      --> 5
    // 54-50: 2.50      --> 6
    // 49-45: 2.25      --> 7
    // 44-40: 2.00      --> 8
    // 39-0: 0.00       --> 9
    int number[] = {80, 75, 70, 65, 60, 55, 50, 45, 40, 0};
    //               0  1   2   3   4   5   6   7   8   9
    float grade[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00, 00.00};
    //                 0     1     2    3      4     5     6     7     8     9

    // total grades count are 10
    for (int i = 0; i < 10; i++)
    {
        if (mark >= number[i])
        {
            return grade[i];
        }
    }
}

void make_gradesheet(struct student_marks X)
{
    FILE *fp;
    char file_path[100] = "";
    // Checking folder availability. (line 11 & 22)
    create_folder_if_not_exist(OUTPUT_FOLDER);
    // using sprintf() instead of using strcpy() & strcat()
    sprintf(file_path, "%s/%s.txt", OUTPUT_FOLDER, X.id);

    fp = fopen(file_path, "w");
    if (fp == NULL)
    {
        printf("file does not exist\n");
        exit(0);
    }

    // create a text file named after student' id with necessary grading information
    fprintf(fp, "Student ID: %s\n", X.id);
    fprintf(fp, "Bangla: %d (%.2f)\n", X.bangla, calc_grade(X.bangla));
    fprintf(fp, "English: %d (%.2f)\n", X.english, calc_grade(X.english));
    fprintf(fp, "Math: %d (%.2f)\n", X.math, calc_grade(X.math));

    fclose(fp);
}

int main()
{
    int n;
    // Student = student_marks
    // using "typedef" without modifying given codes. (line 41)
    Student all[100];

    FILE *fp;
    fp = fopen("marks.txt", "r");
    if (fp == NULL)
    {
        printf("file does not exist\n");
        exit(0);
    }

    // take input from the input file
    // store it in a structure
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s%d%d%d", &all[i].id, &all[i].bangla, &all[i].english, &all[i].math);
    }

    // and process it with make_gradesheet function
    for (int i = 0; i < n; i++)
    {
        make_gradesheet(all[i]);
    }

    fclose(fp);

    return 0;
}

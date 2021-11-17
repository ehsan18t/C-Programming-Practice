#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_marks {
    char id[10];
    int bangla;
    int english;
    int math;
};

float calc_grade(int MARK) {
    float GRADE;
     if(MARK<=100 && MARK >=80) GRADE = 4.00;
       else if(MARK<80 && MARK>=75) GRADE = 3.75;
        else if(MARK<75 && MARK>=70) GRADE = 3.50;
         else if(MARK<70 && MARK>=65) GRADE = 3.25;
            else if(MARK<65 && MARK>=60) GRADE = 3.00;
                else if(MARK<60 && MARK>=55) GRADE = 2.75;
                    else if(MARK<55 && MARK>=50) GRADE = 2.50;
                        else if(MARK<50 && MARK>=45) GRADE = 2.25;
                            else if(MARK<45 && MARK>=40) GRADE = 2.00;
                else GRADE = 0;

     return GRADE;

}

void make_gradesheet(struct student_marks X) {
    char fileName[13];
     strcpy(fileName, X.id);
       strcat(fileName, ".txt");
        FILE *f = fopen(fileName, "w");
        fprintf(f, "Student ID : %s\n", X.id);
    fprintf(f, "Bangla     : %d (%.2f)\n", X.bangla, calc_grade(X.bangla));
fprintf(f, "English    : %d (%.2f)\n", X.english, calc_grade(X.english));
    fprintf(f, "Math       : %d (%.2f)\n", X.math, calc_grade(X.math));
    fclose(f);
}

int main() {
    FILE*fp = fopen("marks.txt", "r");
        if(fp == NULL) {
           printf("file does not exist\n");
        exit(0);
    }
          else {
        int n;
    fscanf(fp, "%d", &n);
         for (int i = 0; i < n; ++i) {
           struct student_marks s;
            fscanf(fp, "%s\t\t\t %d\t\t\t %d\t\t\t %d", s.id, &s.bangla, &s.english, &s.math);
             make_gradesheet(s);
        }
    }
    fclose(fp);
    return 0;
}
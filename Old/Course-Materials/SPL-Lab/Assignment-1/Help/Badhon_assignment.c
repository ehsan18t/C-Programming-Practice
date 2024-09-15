#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_marks {
    char id[10];
    int bangla;
    int english;
    int math;
};

const int arr[] = {100, 79, 74, 69, 64, 59, 54, 49, 44, 39, 0};
const float n[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00, 0, 0};
float pool[101] = {0};

void garde_maker() {
    for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; ++i) {
        for (int x = arr[i]; x > arr[i + 1]; x--) {
            pool[x] = n[i];
        }
    }
}

float calc_grade(int mark) {
    return pool[mark];

}

void make_gradesheet(struct student_marks str) {

    FILE * pt;
    char name[13];
    sprintf(name, "%s.txt", str.id);;
    pt = fopen(name,"w");
    if(pt==NULL)exit(0);
    fprintf(pt,"Student ID: %s\nBangla: %d (%.2f)\nEnglish: %d (%.2f)\nMath: %d (%.2f)\n", str.id, str.bangla, calc_grade(str.bangla),
    str.english,calc_grade(str.english),
            str.math,calc_grade(str.math));
    fclose(pt);
}

int main() {
    FILE *fp;

    fp = fopen("marks.txt", "r");
    if (fp == NULL) {
        printf("file does not exist\n");
        exit(0);
    }
    int t = 0;
    fscanf(fp, "%d", &t);
    struct student_marks studentMarks;
    garde_maker();
    while (--t > 0) {
        fscanf(fp, "%s%d%d%d", &studentMarks.id, &studentMarks.bangla, &studentMarks.english, &studentMarks.math);
        make_gradesheet(studentMarks);

    }

    fclose(fp);
    return 0;
}

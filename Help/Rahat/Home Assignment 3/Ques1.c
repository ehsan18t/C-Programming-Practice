#include <stdio.h>

int main()
{
    int totalStudents = 5;
    int info[totalStudents][4];
    double avgClass = 0;
    double avgMid = 0;
    double avgFinal = 0;
    int lowestFinalStudentIndex = 0;
    int highestAttendanceStudentIndex = 0;

    // input
    for (int i = 0; i < totalStudents; i++)
    {
        printf("Enter student %d marks:\n", i + 1);
        scanf("%d%d%d%d", &info[i][0], &info[i][1], &info[i][2], &info[i][3]);
    }

    // line break to separate inputs and outputs
    printf("\n");

    // calculations
    for (int i = 0; i < totalStudents; i++)
    {
        // print total marks of each student
        printf("Total marks of student %d: %d\n", i + 1, info[i][0] + info[i][1] + info[i][2] + info[i][3]);

        // sum of marks calculation
        avgClass += info[i][1];
        avgMid += info[i][2];
        avgFinal += info[i][3];

        // lowest mark student in the final exam finding
        if (info[lowestFinalStudentIndex][3] > info[i][3])
            lowestFinalStudentIndex = i;

        // highest attendance student finding
        if (info[highestAttendanceStudentIndex][0] < info[i][0])
            highestAttendanceStudentIndex = i;
    }

    // avarage calculation
    avgClass /= totalStudents;
    avgFinal /= totalStudents;
    avgMid /= totalStudents;

    // print rest of the output
    printf("Avarage marks of Class Test: %.1lf\n", avgClass);
    printf("Avarage marks of Mid: %.1lf\n", avgMid);
    printf("Avarage marks of Final: %.1lf\n", avgFinal);
    printf("Student with lowest marks in final exam: %d\n", lowestFinalStudentIndex + 1); // index to serial
    printf("Student with highest attendance: %d\n", highestAttendanceStudentIndex + 1);   // index to serial

    return 0;
}
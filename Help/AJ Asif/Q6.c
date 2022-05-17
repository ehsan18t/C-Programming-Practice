#include <stdio.h>
struct student
{
    char name[100];
    int completedCredit;
} typedef student;

int main()
{
    int n, sum = 0;
    student arr[100];

    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", &arr[i].name, &arr[i].completedCredit);
        sum += arr[i].completedCredit;
    }

    // Output
    printf("Sum of Completed Credits: %d\n", sum);
    return 0;
}

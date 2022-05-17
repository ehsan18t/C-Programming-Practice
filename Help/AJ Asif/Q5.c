#include <stdio.h>

struct student
{
    char name[100];
    double result;
} typedef student;

int main()
{
    int n;
    student arr[100];
    student s1, s2, s3;

    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %lf", &arr[i].name, &arr[i].result);

    // finding highest
    s3 = arr[0];
    for(int i = 1; i < n; i++)
        if (arr[i].result > s1.result)
            s1 = arr[i];

    // finding 2nd highest
    s2.result = 0;
    for(int i = 0; i < n; i++)
        if (arr[i].result > s2.result && arr[i].result < s1.result)
            s2 = arr[i];
        
    // finding 3rd highest
    s3.result = 0;
    for(int i = 0; i < n; i++)
        if (arr[i].result > s3.result && arr[i].result < s2.result)
            s3 = arr[i];

    // Output
    printf("First: %s %.2lf\n", s1.name, s1.result);
    printf("Second: %s %.2lf\n", s2.name, s2.result);
    printf("Third: %s %.2lf\n", s3.name, s3.result);
    return 0;
}

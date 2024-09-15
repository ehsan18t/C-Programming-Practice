#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int main()
{
    int n;
    Date date[100] = {0};
    Date min = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &date[i].year, &date[i].month, &date[i].day);
    }
    min = date[0];
    for (int i = 0; i < n; i++)
    {
        // use 3 condition insted of 1 is
        // for easily read
        if (min.year > date[i].year)
        {
            min = date[i];
        }
        else if (min.year == date[i].year && min.month > date[i].month)
        {
            min = date[i];
        }
        else if (min.year == date[i].year && min.month == date[i].month && min.day > date[i].day)
        {
            min = date[i];
        }
    }
    printf("year: %d, month %d, day: %d\n", min.year, min.month, min.day);
    return 0;
}
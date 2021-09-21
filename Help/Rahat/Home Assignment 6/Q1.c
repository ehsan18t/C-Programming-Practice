#include <stdio.h>

/*
Input:
Enter 5 dates (dd mm yyyy):
1 8 1998
14 9 2000       
5 09 2020       
7 10 2021       
08 08 2009      

Enter a month: 9



Output:
All Dates:
[1] 01-08-1998
[2] 14-09-2000
[3] 05-09-2020
[4] 07-10-2021
[5] 08-08-2009

The Oldest Date: 01-08-1998

Dates with Leap Year:
14-09-2000
05-09-2020

Dates with Month 09:
14-09-2000
05-09-2020
*/

struct date
{
    int day;
    int month;
    int year;
} typedef date;

void input_date(date[], int);
void print_date(date);
date find_oldest_date(date[], int);
void print_leap_year(date[], int);
void print_month_date(date[], int, int);

int main()
{
    // freopen("Q1.in", "r", stdin); // debug
    // declare
    int n = 5;
    int month;
    date info[n];

    // input
    printf("Enter 5 dates (dd mm yyyy):\n");
    input_date(info, n);
    printf("\n"); // line break
    printf("Enter a month: ");
    scanf("%d", &month);
    printf("\n"); // line break

    // printing the dates
    printf("All Dates:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d] ", i + 1);
        print_date(info[i]);
    }
    printf("\n"); // line break

    //print the oldest dates
    printf("The Oldest Date: ");
    print_date(find_oldest_date(info, n));
    printf("\n"); // line break

    // print the dates of leap years
    printf("Dates with Leap Year:\n");
    print_leap_year(info, n);
    printf("\n"); // line break

    // print the dates of inputted month
    printf("Dates with Month %.2d:\n", month);
    print_month_date(info, n, month);
    printf("\n"); // line break

    return 0;
}

void input_date(date data[], int len)
{
    for (int i = 0; i < len; i++)
        scanf("%d %d %d", &data[i].day, &data[i].month, &data[i].year);
}

void print_date(date data)
{
    // adding '%.2d' to print day and month in 2 digits
    printf("%.2d-%.2d-%d\n", data.day, data.month, data.year);
}

date find_oldest_date(date data[], int len)
{
    int min_index = 0;
    int min = data[min_index].year;
    for (int i = 1; i < len; i++)
    {
        // checking year
        if (data[i].year < min)
        {
            min = data[i].year;
            min_index = i;
        }
        else if (data[i].year == min)
        {
            // checking month
            if (data[i].month < data[min_index].month)
                min_index = i;
            else if (data[i].month == data[min_index].month)
            {
                // checking day
                if (data[i].day < data[min_index].day)
                    min_index = i;
            }
        }
    }
    return data[min_index];
}

// print leap year dates
void print_leap_year(date data[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (data[i].year % 4 == 0 && data[i].year % 100 != 0)
            print_date(data[i]);
        else if (data[i].year % 400 == 0)
            print_date(data[i]);
    }
}

void print_month_date(date data[], int len, int month)
{
    for (int i = 0; i < len; i++)
        if (data[i].month == month)
            print_date(data[i]);
}

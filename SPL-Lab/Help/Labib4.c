#include <stdio.h>

typedef struct
{
    int h;
    int m;
    int s;
} Time;

Time time_input();
void time_diff(Time, Time);

int main()
{
    Time a = time_input();
    Time b = time_input();
    time_diff(a, b);
    return 0;
}

void time_diff(Time a, Time b)
{
    int total_a = (a.h * 60 * 60) + (a.m * 60) + a.s;
    int total_b = (b.h * 60 * 60) + (b.m * 60) + b.s;
    int t = total_a - total_b;
    Time result;
    result.h = t / 3600;
    t -= result.h * 3600;
    result.m = t / 60;
    t -= result.m * 60;
    result.s = t;
    printf("%d %d %d", result.h, result.m, result.s);
}

Time time_input()
{
    Time a;
    scanf("%d%d%d", &a.h, &a.m, &a.s);
    return a;
}
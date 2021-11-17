#include <stdio.h>
#include <math.h>

typedef struct
{
    double r;
    double i;
} Complex;

typedef struct
{
    double a;
    double b;
} TwoNumber;

// Functions for Complex Number
// ------------------------------
Complex add_com(Complex a, Complex b)
{
    Complex result;
    result.r = (a.r + b.r);
    result.i = (a.i + b.i);
    return result;
}

Complex subs_com(Complex a, Complex b)
{
    Complex result;
    result.r = (a.r - b.r);
    result.i = (a.i - b.i);
    return result;
}

Complex mult_com(Complex a, Complex b)
{
    Complex result;
    result.r = (a.r * b.r) - (a.i * b.i);
    result.i = (a.i * b.r) + (a.r * b.i);
    return result;
}

Complex div_com(Complex a, Complex b)
{
    Complex result;
    result.r = ((a.r * b.r) + (a.i * b.i)) / ((b.r * b.r) + (b.i * b.i));
    result.i = ((a.i * b.r) - (a.r * b.i)) / ((b.r * b.r) + (b.i * b.i));
    return result;
}

/// Need to calculate Arugument
double mod_com(Complex a)
{
    return sqrt(pow((a.r), 2) + pow((a.i), 2));
}

// ------------------------------------
//  Meter Centimeter Time Calculation
// -------------------------------------

void meter_centi_print(TwoNumber a)
{
    double meter = a.a + (a.b / 100);
    double centi = (a.a * 100) + a.b;
    printf("Meter: %.2lf \n centi: %.lf\n", meter, centi);
}

TwoNumber meter_centi_cal(TwoNumber a, TwoNumber b)
{
    TwoNumber result;
    int A = a.a + b.a;
    int B = a.b + b.b;
    result.b = B % 100;
    result.a = A + (B / 100);
    return result;
}

typedef struct
{
    int h;
    int m;
    int s;
} Time;

void time_cal(Time a)
{
    double sixty = 60.00;
    double hour = a.h + (a.m / sixty) + (a.s / (sixty*sixty));
    double min = (a.h * sixty) + a.m + (a.s / sixty);
    int sec = (a.h * sixty * sixty) + (a.m * sixty) + a.s;
    printf("%.2lf %.2lf %d", hour, min, sec);
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

int main()
{
    Time a = {3, 45, 48};
    Time b = {1, 55, 50};
    // time_diff(a, b);
    printf("%lf", atan2(4.0, 3.0));
    return 0;
}
//
//
//----------------------------------------------------------

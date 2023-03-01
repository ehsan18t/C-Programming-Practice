#include <stdio.h>
#include <math.h>
// REF: https://www.urionlinejudge.com.br/judge/en/problems/view/1036
// Read 3 floating-point numbers. After, print the roots of bhaskara’s formula.
// If it's impossible to calculate the roots because a division by zero or a square
// root of a negative number, presents the message “Impossivel calcular”.
//
// Input
// Read 3 floating-point numbers A, B and C.
//
// Output
// Print the result with 5 digits after the decimal point or the message if it is impossible to calculate.
//
//---------------------------------------------
// | Input Samples   --->    Output Samples   |
//----------------------------------------------
// 10.0 20.1 5.1    --->    R1 = -0.29788
//                          R2 = -1.71212
//==============================================
// 0.0 20.0 5.0     --->    Impossivel calcular
//==============================================
// 10.3 203.0 5.0   --->    R1 = -0.02466
//                          R2 = -19.68408
//==============================================
// 10.0 3.0 5.0     --->    Impossivel calcular
//==============================================


int main(){
    double a, b, c, x, r1, r2;
    scanf("%lf %lf %lf", &a, &b, &c);
    x = (b*b)-4*a*c;
    if (a == 0 || x < 0)
        printf("Impossivel calcular\n");
    else {
        x = sqrt(x);
        r1 = (-b + x) / (2 * a);
        r2 = (-b - x) / (2 * a);
        printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
    }
    return 0;
}
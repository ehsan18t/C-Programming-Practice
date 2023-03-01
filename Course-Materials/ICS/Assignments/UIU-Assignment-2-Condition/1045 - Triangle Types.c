#include <stdio.h>

int main(){
    double a, b, c, A, B, C;
    scanf("%lf %lf %lf", &b, &a, &c);
    if (a!=0 && b!=0 && c!=0) {
        if (a > b && a > c) {
            A = a;
            B = b;
            C = c;
        } else if (b > a && b > c) {
            A = b;
            B = a;
            C = c;
        } else {
            A = c;
            B = b;
            C = a;
        }
        a = A;
        b = B;
        c = C;
        A = a * a;
        B = b * b;
        C = c * c;

        if (a >= b+c)
            printf("NAO FORMA TRIANGULO\n");
        else if (A == B+C)
            printf("TRIANGULO RETANGULO\n");
        else{
            if (A > B+C)
                printf("TRIANGULO OBTUSANGULO\n");
            else if (A < B+C)
                printf("TRIANGULO ACUTANGULO\n");
            if (a == b && a == c)
                printf("TRIANGULO EQUILATERO\n");
            else if (a==b || b==c || c==a)
                printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}
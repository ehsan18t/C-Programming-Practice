#include <stdio.h>

int main(){
    double x, y;
    scanf("%lf %lf", &x, &y);
    if(x == 0 && y == 0)        // x=0, y=0
        printf("Origem\n");
    else if(x > 0 && y > 0)     // x positive, y positive
        printf("Q1\n");
    else if(x < 0 && y > 0)     // x negative, y positive
        printf("Q2\n");
    else if(x < 0 && y < 0)     // x negative, y negative
        printf("Q3\n");
    else if(x > 0 && y < 0)     // x positive, y negative
        printf("Q4\n");
    else if(x == 0 && y != 0)   // x=0 but y!=0
        printf("Eixo Y\n");
    else if(x != 0 && y == 0)   // y=0 but x!=0
        printf("Eixo X\n");
    return 0;
}

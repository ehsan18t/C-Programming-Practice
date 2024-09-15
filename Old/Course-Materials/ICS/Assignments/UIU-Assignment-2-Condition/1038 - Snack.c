#include <stdio.h>

int main(){
    int X, Y;
    scanf("%d %d", &X, &Y);
    switch(X)
    {
        case 1:
            printf("Total: R$ %.2lf\n", 4.00*Y);
            break;

        case 2:
            printf("Total: R$ %.2lf\n", 4.50*Y);
            break;

        case 3:
            printf("Total: R$ %.2lf\n", 5.00*Y);
            break;

        case 4:
            printf("Total: R$ %.2lf\n", 2.00*Y);
            break;

        case 5:
            printf("Total: R$ %.2lf\n", 1.50*Y);
            break;

        default:
            printf("Error! operator is not correct");
    }
    return 0;
}

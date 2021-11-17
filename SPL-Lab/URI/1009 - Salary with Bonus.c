#include <stdio.h>

typedef struct
{
    char name[100];
    double salary;
    double sale;
    double total;
} data;

int main()
{
    data user = {"", 0, 0, 0};
    scanf("%s", user.name);
    scanf("%lf %lf", &user.salary, &user.sale);
    user.total = user.salary + (0.15 * user.sale);
    printf("TOTAL = R$ %.2lf\n", user.total);
    return 0;
}
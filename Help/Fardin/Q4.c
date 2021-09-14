#include <stdio.h>

double bonus_calculation(double salary, int gender)
{
    // male = 1
    // female = 2
    int bonus_rate;
    if (gender == 1) // for male
        bonus_rate = 9;
    else
        bonus_rate = 10;

    if (salary < 20000)
        bonus_rate += 2;

    return (salary * (bonus_rate / 100.0));
}

int main()
{
    double salary, bonus;
    int gender;
    printf("Input Salary: ");
    scanf("%lf", &salary);
    printf("Input Gender (male=1, female=2): ");
    scanf("%d", &gender);
    bonus = bonus_calculation(salary, gender);
    printf("Salary: %.2lf\nBonus: %.2lf\nTotal: %.2lf\n", salary, bonus, (salary + bonus));
    return 0;
}

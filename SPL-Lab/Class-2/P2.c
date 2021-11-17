#include <stdio.h>

int main()
{
    double input, temp;
    double result = 0;
    double rates[] = {7.00, 6.00, 5.50, 5.00};
    double amounts[] = {300, 200, 100, 0};
    scanf("%lf", &input);
    for (int i = 0; i < sizeof(amounts); i++)
    {
        if (input > amounts[i])
        {
            temp = input - amounts[i];
            input -= temp;
            result += (rates[i] * temp);
        }
    }
    printf("%.2lf\n", result);
}
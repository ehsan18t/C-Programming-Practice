#include <stdio.h>

int main()
{
    double input, temp;
    double result = 0;
    double rates[] = {0.28, 0.18, 0.08};
    double amounts[] = {4500, 3000, 2000};
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
#include <stdio.h>

int main()
{
    int n;
    double a, hw, ct, mt, tf, result;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &a);
        scanf("%lf", &hw);
        scanf("%lf", &ct);
        scanf("%lf", &mt);
        scanf("%lf", &tf);
        result = a + hw + ct + ((mt / 50) * 30) + ((tf / 100) * 40);
        if (result > 89)
            printf("Student %d: A", i);
        else if (result > 85)
            printf("Student %d: A-", i);
        else if (result > 81)
            printf("Student %d: B+", i);
        else if (result > 77)
            printf("Student %d: B", i);
        else if (result > 73)
            printf("Student %d: B-", i);
        else if (result > 69)
            printf("Student %d: C+", i);
        else if (result > 65)
            printf("Student %d: C", i);
        else if (result > 61)
            printf("Student %d: C-", i);
        else if (result > 57)
            printf("Student %d: D+", i);
        else if (result > 54)
            printf("Student %d: D", i);
        else
            printf("Student %d: F", i);
    }
    return 0;
}
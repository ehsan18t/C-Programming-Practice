#include <bits/stdc++.h>

int main()
{
    int milk_solid[] = {15, 10, 3};
    int fat[] = {8, 3, 0};
    int total_milk;
    int a, b;
    int result = 4;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < 3; i++)
    {
        total_milk = a + b;
        if (total_milk >= milk_solid[i] && b >= fat[i])
        {
            result = i + 1;
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}
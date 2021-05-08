#include <bits/stdc++.h>

int main()
{
    int a, b, w;
    int min, max;
    int min_flag = 0;
    int max_flag = 0;
    scanf("%d%d%d", &a, &b, &w);
    w *= 1000;
    if (w % b != 0)
    {
        int i = 1;
        while (b * i < w / 3) i++;

        min = i - 1;
        int extra = w - (min * b);
        i = 10;
        while (min_flag != 1)
        {
            
            if (extra % (b - i) == 0)
            {
                min += extra / (b - i);
                min_flag = 1;
            }
            i += 10;
            if (b + i < extra) break;
        }
    }
    else
    {
        min = w / b;
        min_flag = 1;
    }
    if (w % a != 0)
    {
        int i = 1;
        while (a * i < w / 2) i++;

        max = i - 1;
        int extra = w - (max * a);
        i = 10;
        while (max_flag != 1)
        {
            if (extra % (a + i) == 0)
            {
                max += extra / (a + i);
                max_flag = 1;
            }
            i += 10;
            if (a + i > extra) break;
        }
    }
    else
    {
        max = w / a;
        max_flag = 1;
    }
    if (min_flag == 0 || max_flag == 0)
        printf("UNSATISFIABLE\n");
    else
        printf("%d %d\n", min, max);
    return 0;
}
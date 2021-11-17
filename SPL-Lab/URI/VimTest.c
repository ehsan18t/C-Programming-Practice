#include <stdio.h>

int main()
{
    double n;
    int x, y;
    int note[6] = {0};
    int coin[6] = {0};
    int noteSet[] = {100, 50, 20, 10, 5, 2};
    int coinSet[] = {100, 50, 25, 10, 5, 1};
    scanf("%lf", &n);
    x = n;
    y = 100 * (n - x);
    for (int i = 0; i < 6; i++)
    {
        if (x == 1)
        {
            x--;
            y += 100;
            break;
        }
        else if (x > 0)
        {
            note[i] = x / noteSet[i];
            x = x % noteSet[i];
        }
        else
            break;
    
    for (int i = 0; i < 6; i++)
    {
        if (y > 0)
        {
            coin[i] = y / coinSet[i];

        }
        else break;
        // Print Output.....
        printf("NOTAS:\n%d nota(s) de R$ 100.00\n", note[0]);
        printf("%d nota(s) de R$ 50.00\n", note[1]);
        printf("%d nota(s) de R$ 20.00\n", note[2]);
        printf("%d nota(s) de R$ 10.00\n", note[3]);
        printf("%d nota(s) de R$ 5.00\n", note[4]);
        printf("%d nota(s) de R$ 2.00\n", note[5]);
    }
}
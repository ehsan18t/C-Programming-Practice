#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void pause()
{
    printf("\npress any key to continue...\n");
    getch();
}

// If we enter char in place of int variable an infinite loop occars.
// This function can prevent that problem.
void clearInputStream()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int salary[10000];
    int n = 0;
    while (1)
    {
        system("cls");
        char ch;
        printf("======= Office Pay Roll System =======\n");
        printf("[r] Input Salary Of All Employees\n");
        printf("[s] Search a Salary Amount\n");
        printf("[t] Display Salary Of All Employees In Reverse Index Order\n");
        printf("[q] Exit The Menu\n\n");
        ch = getch();
        switch (ch)
        {
        case 'r':
            printf("======= Input Salary =======\n");
            printf("Total Employee: ");
            scanf("%d", &n);
            clearInputStream();
            for (int i = 0; i < n; i++)
            {
                printf("Salary of Emplaoyee No. %d: ", i + 1);
                scanf("%d", &salary[i]);
                clearInputStream();
            }
            break;
        case 's':
            printf("======= Search Salary =======\n");
            if (n == 0)
            {
                printf("No salary information found. Please populate your salary information first.\n");
                pause();
                break;
            }
            int s;
            printf("Please Input an Amount: ");
            scanf("%d", &s);
            clearInputStream();
            for (int i = 0; i < n; i++)
            {
                if (salary[i] == s)
                {
                    printf("Index No.: %d\n", i);
                    printf("Employee No.: %d\n", i + 1);
                    pause();
                    break;
                }
            }
            printf("Not found\n");
            pause();
            break;
        case 't':
            printf("======= All Salary List =======\n");
            if (n == 0)
            {
                printf("No salary information found. Please populate your salary information first.\n");
                pause();
                break;
            }
            for (int i = 0; i < n; i++)
            {
                printf("Employee No. %d: %d\n", n - i, salary[n - i - 1]);
            }
            pause();
            break;
        case 'q':
            return 0;
        default:
            printf("\nInvalid Input.\n\n");
            pause();
            break;
        }
    }
}
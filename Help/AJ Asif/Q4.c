#include <stdio.h>

int isVowel(char ch)
{
    char v[] = {'a', 'e', 'i', 'o', 'u'};

    // if ch is vowel return 1
    for (int i = 0; i < 5; ++i)
        if (ch == v[i])
            return 1;

    // if not vowel return 0
    return 0;
}

void printToN(int n)
{
    printf("1 to N values: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", i);
    printf("\n");
}

void printTo1(int n)
{
    printf("N to 1 values: ");
    for (int i = n; i > 0; i--)
        printf("%d ", i);
    printf("\n");
}

void printSumToN(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("Sum of 1 to N: %d\n", sum);
}

void printOddCount(int n)
{
    int odd = 0;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 1)
            odd++;
    printf("Sum of odd 1 to N: %d\n", odd);
}

int main()
{
    int n;
    char ch;

    // Input
    printf("Enter a Number: \n");
    scanf("%d", &n);
    printf("Enter a Character: \n");
    getchar();
    scanf("%c", &ch);

    // Outputs
    if (isVowel(ch))
        printToN(n);
    else
        printTo1(n);
    printSumToN(n);
    printOddCount(n);
    return 0;
}
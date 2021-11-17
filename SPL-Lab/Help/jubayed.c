#include <stdio.h>

int isPrime(int);
void GeneratePrime(int, int *);

//global arry for storing Prime number
int prime_numbers[100] = {0};

int main()
{
    int n;
    int j;
    int counter = 0;
    scanf("%d", &n);
    if (n > 1)
    {
        for (int i = 2; i < n; i++)
        {
            GeneratePrime(i, &counter);
        }
    }
    // printing prime numbers
    if (counter > 0)
    {
        printf("Prime less than %d: ", n);
        for (j = 0; j < counter - 1; j++)
        {
            printf("%d, ", prime_numbers[j]);
        }
        // remove the last comma
        printf("%d\n", prime_numbers[j]);
    }
    return 0;
}

void GeneratePrime(int number, int *counter)
{
    int isPr = isPrime(number);
    if (isPr == 1)
    {
        prime_numbers[*counter] = number;
        *counter += 1;
    }
}

int isPrime(int n)
{
    // 1 means the number is prime
    // 0 means it non prime
    int isPrime = 1;
    if (n == 2)
        return isPrime;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}
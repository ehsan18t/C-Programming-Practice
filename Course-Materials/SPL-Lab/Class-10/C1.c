#include <stdio.h>

int fac(int);
int fac_ptr(int *);

int main()
{
    int n, result;
    scanf("%d", &n);
    result = fac(&n);
    printf("%d", result);
    return 0;
}

// factorial recurtion
int fac(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fac(n - 1);
}

// factorial recurtion-pointer
int fac_ptr(int *n)
{
    int m;
    if (*n == 0)
    {
        return 1;
    }
    else
    {
        m = *n - 1;
    }

    return *n * fac(&m);
}

int comb(int n, int r)
{
    if (r == n)
    {
        return 1;
    }
    if (r == 0)
    {
        return 1;
    }
    
    return (n - 1, r) + (n - 1, r - 1);
}
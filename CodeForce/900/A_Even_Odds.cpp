#include <bits/stdc++.h>

int main()
{
    long long n, k, odd_count, even_count, result;
    std::cin >> n >> k;
    if (n % 2 == 1)
        odd_count = (n / 2) + 1;
    else
        odd_count = n / 2;

    even_count = n - odd_count;

    // for odd numbers
    int a = 1;
    n = k;

    // for even numbers
    if (k > odd_count)
    {
        a = 2;
        n = (k - odd_count) + 1;
    }
    std::cout << (2 * n) - a << std::endl;
}
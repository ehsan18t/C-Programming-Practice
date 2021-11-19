#include <bits/stdc++.h>

int max_of_four(int a, int b, int c, int d)
{
    int max = a > b ? a : b;
    max = max > c ? max : c;
    max = max > d ? max : d;
    return max;
}

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << max_of_four(a, b, c, d) << std::endl;
    return 0;
}
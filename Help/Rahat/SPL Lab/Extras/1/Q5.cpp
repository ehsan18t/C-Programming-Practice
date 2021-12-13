#include <iostream>

int main()
{
    int n = 1, sum = 0;
    std::cout << "Series: ";
    for (int i = 0; i < 11; i++)
    {
        sum += n;
        std::cout << n << " + ";
        n = n + i;
    }

    sum += n;
    std::cout << n << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
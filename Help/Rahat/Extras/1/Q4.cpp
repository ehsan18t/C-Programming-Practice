#include <iostream>

int main()
{
    int n = 1, sum = 0;
    std::cout << "Series: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << n << " + ";
        sum += n;
        n *= 2;
    }
    sum += n;
    std::cout << n << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
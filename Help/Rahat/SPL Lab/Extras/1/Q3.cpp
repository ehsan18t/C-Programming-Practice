#include <iostream>

int main()
{
    int n;
    std::cout << "Enter age: ";
    std::cin >> n;
    if (n > 19)
        std::cout << "older than teenagers." << std::endl;
    else if (n > 12)
        std::cout << "Teenagers." << std::endl;
    else
        std::cout << "Younger than teenagers." << std::endl;
    return 0;
}
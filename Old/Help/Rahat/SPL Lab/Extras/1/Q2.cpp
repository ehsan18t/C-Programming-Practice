#include <iostream>

int main()
{
    int hours, days, weeks;
    std::cout << "Enter Hours: ";
    std::cin >> hours;

    days = hours / 24;
    hours %= 24;

    weeks = days / 7;
    days %= 7;

    std::cout << weeks << " weeks, " << days << " days, and " << hours << " hours" << std::endl;
    return 0;
}
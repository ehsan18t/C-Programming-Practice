#include <iostream>

int main()
{
    int days, months, years;
    std::cout << "Enter Days: ";
    std::cin >> days;
    years = days / 365;
    days %= 365;

    months = days / 30;
    days %= 30;
    std::cout << years << " years " << months << " months " << days << " days" << std::endl;
    return 0;
}
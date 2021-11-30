#include <iostream>
#include <string>

//-----------------------------------//
// global variables (for easier use) //
//-----------------------------------//
std::string month_name[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::string day_name[] = {"SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI"};
int week_day[] = {1, 2, 3, 4, 5, 6, 7};

//----------------------//
// function declaration //
//----------------------//
void displayCal(int skip, int total_days);
int start_day(int month, int year);

//-----------------------//
// main/driver functions //
//-----------------------//
int main()
{
    // variables declarations
    int month, year;
    int total_days, skip;

    // input
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;

    // decideing how many days the month have
    total_days = month_day[month - 1];

    // printing month and year before changing (for calculate start date)
    std::cout << std::endl
              << month_name[month - 1] << " " << year
              << std::endl
              << std::endl;

    // calculating starting day of week
    skip = start_day(month, year);

    // display calender
    displayCal(skip, total_days);
    return 0;
}

//------------------------//
// sub-ordinate functions //
//------------------------//

// function to display calender
void displayCal(int skip, int total_days)
{
    int i = 0, skipped = 0, count = 1, loop = 1;
    // printing week names
    for (i = 0; i < 7; i++)
        std::cout << day_name[i] << "   ";
    std::cout << std::endl; // line break

    // skipping days that not included in the selected month
    while (skipped < skip)
    {
        std::cout << "      ";
        skipped++;
    }

    // printing all days of month
    while (loop) // to print all days with week, 5 lines needed
    {
        for (int j = skipped; j < 7; j++)
        {
            // if number is less than 10, 1 extra space will be printed
            if (count < 10)
                std::cout << count << "     ";
            else
                std::cout << count << "    ";

            // loop break condition
            if (count == total_days)
            {
                loop = 0;
                break;
            }
            count++;
        }
        skipped = 0;
        std::cout << std::endl; // line break after every week
        i++;
    }
}

int start_day(int month, int year)
{
    // according to, month JAN and FEB are treated as month 13 and 14 of previous year
    if (month < 3)
    {
        year -= 1;
        month += 12;
    }
    // always calculating the first day, q = 1
    return ((1 + (26 * (month + 1) / 10) + year + (year / 4) + 6 * (year / 100) + (year / 400)) % 7);
}
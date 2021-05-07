#include <iostream>
#include <cmath>

namespace mem
{
    std::string IntToHexa(int num)
    {
        int values[2];
        int rest;
        for (int i = 0; i < 2; i++)
        {
            rest = num % 16;
            if (rest == 0 && num > 0)
            {
                values[i] = num / 16;
            }
            else
            {
                values[i] = num % 16;
            }
            num -= values[i] * std::pow(16, i);

            if (values[i] > 9)
            {
                values[i] = 65 + values[i] - 10;
            }
        }

        std::string output;
        for (int i = 1; i > -1; i--)
        {
            if (values[i] > 10)
            {
                output += char(values[i]);
            }
            else
            {
                output += std::to_string(values[i]);
            }
        }
        return output;
    }

    template <typename POINTER>
    void MemView(POINTER pointer, int length = 10, int lines = 1)
    {
        unsigned char *ptr = (unsigned char *)pointer;
        for (int x = 0; x < lines; x++)
        {
            std::cout << (void *)ptr << "   ";
            for (int i = 0; i < length; i++)
            {
                std::cout << IntToHexa((int)*ptr) << "  ";
                ptr++;
            }
            std::cout << std::endl;
        }
    }
}
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../Debugging Tools/dbg.cpp"
#include "../../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int count = 0;
    // freopen("in.txt", "r", stdin);
    std::string line = "";
    while (std::getline(std::cin, line))
    {
        std::string str = "";
        int i = 0;
        while (i < line.size())
        {
            char ch = line.at(i);
            if (ch == '\"')
                count++;

            if (ch == '\"' && count % 2 == 0)
                str += "''";
            else if (ch == '\"')
                str += "``";
            else
                str += ch;
            i++;
        }
        std::cout << str << std::endl;
    }
    return 0;
}
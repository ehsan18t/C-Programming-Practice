#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int n;
    std::cin >> n;
    while (n--)
    {
        int m;
        std::string str = "";
        int output[10] = {0};
        std::cin >> m;

        // generating string
        for (int i = 1; i <= m; i++)
            str = str + std::to_string(i);

        // counting
        for (int i = 0; i < str.length(); i++)
            output[str.at(i) - '0']++;

        // printing
        for (int i = 0; i < 10; i++)
            std::cout << output[i] << (i == 9 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}
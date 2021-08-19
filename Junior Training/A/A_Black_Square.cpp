#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
    int i = 0;
    int arr[4];
    std::string str;
    int totalCalory = 0;
    for (int i = 0; i < 4; i++)
        std::cin >> arr[i];
    std::cin >> str;
    while (str[i] != '\0')
    {
        int index = str[i] - '0';
        // dbg(index);
        totalCalory += arr[index - 1];
        i++;
    }
    std::cout << totalCalory << std::endl;
    return 0;
}
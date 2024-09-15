#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./Debugging Tools/dbg.cpp"
#include "./Debugging Tools/MemView.cpp"
#endif

int main()
{
    int k;
    unsigned long long n;
    std::string str;
    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        // dbg(n);
        if (n % 200 == 0)
        {
            n /= 200;
        }
        else
        {
            std::ostringstream stringStream;
            stringStream << n << "200";
            str = stringStream.str();
            // dbg(str); //dbg
            n = std::stoull(str);
        }
    }
    std::cout << n << std::endl;

    return 0;
}
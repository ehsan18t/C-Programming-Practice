#include <bits/stdc++.h>

int main()
{
	int n;
    int a = 0, d = 0;
    std::cin >> n;
    char str[n];
    std::cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A')
            a++;
        else
            d++;
    }
    if (a > d)
        std::cout << "Anton" << std::endl;
    else if (d > a)
        std::cout << "Danik" << std::endl;
    else
        std::cout << "Friendship" << std::endl;
	return 0;
}
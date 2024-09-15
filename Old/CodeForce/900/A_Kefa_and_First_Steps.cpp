#include <bits/stdc++.h>

int main()
{
    int n;
    int count = 1;
    int highest = 0;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= arr[i + 1] && i + 1 != n)
            count++;
        else
        {
            if (count > highest)
                highest = count;
            count = 1;
        }
    }
    std::cout << highest << std::endl;
    return 0;
}
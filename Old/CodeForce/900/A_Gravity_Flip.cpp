#include <bits/stdc++.h>

int main()
{
    int n, arr[100];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
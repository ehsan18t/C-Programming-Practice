#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    int i = 0;
    while (i < n / 2)
    {
        int tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
        i++;
    }

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
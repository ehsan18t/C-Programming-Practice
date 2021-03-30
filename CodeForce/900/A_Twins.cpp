#include <bits/stdc++.h>

int main()
{
    int n;
    int i = 0;
    int taken = 0;
    int half = 0;
    int arr[100];
    std::cin >> n;
    for (i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        half += arr[i];
    }
    half /= 2;
    std::sort(arr, arr + n);
    for (i = 0; i < n; i++)
    {
        taken += arr[n - i - 1];
        if (taken > half)
            break;
    }
    std::cout << i+1 << std::endl;
    return 0;
}
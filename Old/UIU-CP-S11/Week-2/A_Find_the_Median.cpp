#include <bits/stdc++.h>

int findMedian(int arr[], int len)
{
    std::sort(arr, arr + len);
    return arr[len / 2];
}

int main()
{
    int n, *arr, result;
    std::cin >> n;
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    result = findMedian(arr, n);
    std::cout << result << std::endl;
    return 0;
}
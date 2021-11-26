#include <bits/stdc++.h>

int main()
{
    int n, *arr, result = 0, count = 1;
    std::cin >> n;
    arr = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + n);
    arr[n] = 0; // adding this extra index to avoid array index out of bound
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        if (arr[i] == arr[i + 1])
        {
            count++;
            flag = 1;
        }

        if (arr[i] == arr[i - 1])
        {
            count++;
            flag = 1;
        }

        if (flag != 1)
            count = 1;

        if (count < 2)
        {
            result = i;
            break;
        }
    }
    std::cout << arr[result] << std::endl;
    return 0;
}
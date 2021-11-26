#include <bits/stdc++.h>

int main()
{
    int i, j;
    int n, *arr1;
    int m, *arr2;

    // input 1st array
    std::cin >> n;
    arr1 = (int *)malloc(sizeof(int) * (n));
    for (i = 0; i < n; i++)
        std::cin >> arr1[i];

    // input 2nd array
    std::cin >> m;
    arr2 = (int *)malloc(sizeof(int) * (m));
    for (i = 0; i < m; i++)
        std::cin >> arr2[i];

    // sort both array
    std::sort(arr1, arr1 + n);
    std::sort(arr2, arr2 + m);

    i = 0;
    j = 0;
    while (i < n)
    {
        if (arr1[i] > arr2[j])
        {
            std::cout << arr2[j] << " ";
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            std::cout << arr1[i] << " ";
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (j < m)
    {
        std::cout << arr2[j] << " ";
        j++;
    }
    return 0;
}
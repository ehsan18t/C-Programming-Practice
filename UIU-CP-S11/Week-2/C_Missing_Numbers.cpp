#include <bits/stdc++.h>

int main()
{
    int n, *arr1;
    int m, *arr2;
    int count1[100] = {0};
    int count2[100] = {0};

    // input 1st array
    std::cin >> n;
    arr1 = (int *)malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i++)
        std::cin >> arr1[i];

    // input 2nd array
    std::cin >> m;
    arr2 = (int *)malloc(sizeof(int) * (m));
    for (int i = 0; i < m; i++)
        std::cin >> arr2[i];

    // sort both array
    // std::sort(arr1, arr1 + n);
    // std::sort(arr2, arr2 + m);

    // generating
    for (int i = 0; i < n; i++)
        count1[arr1[i] % 100]++;
    for (int i = 0; i < m; i++)
        count2[arr2[i] % 100]++;

    // print output
    for (int i = 0; i < size; i++)
        std::cout
            << out[i] << " ";
    std::cout << std::endl;

    // // clearing occupied memory
    // free(arr1);
    // free(arr1);
    // free(out);
    return 0;
}

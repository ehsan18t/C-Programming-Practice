#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;              // input n
    std::string arr[n];         // declare array
    for (int i = 0; i < n; i++) // loop for fill the array
        arr[i] = std::to_string(i + 1);
    std::sort(arr, arr + n);    // sort array

    for (int i = 0; i < n; i++) // print array
        std::cout << arr[i] << " ";
    return 0;
}
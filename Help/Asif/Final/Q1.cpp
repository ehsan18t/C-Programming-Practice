#include <bits/stdc++.h>
// #include "../../Debugging Tools/dbg.cpp"

void input_int_array(int[], int);
void print_int_array(int[], int);
int max_sum(int[], int, int, int[]);
void print_result(int[], int);

int main()
{
    // freopen("input.txt", "r", stdin); // debug
    int w, n, max;
    int result[10] = {0};
    std::cin >> w >> n;
    int arr[n];
    input_int_array(arr, n);
    // print_int_array(arr, n);
    max = max_sum(arr, n, w, result);
    print_result(result, 10);
    std::cout << "Sum: " << max << std::endl;
    return 0;
}

// function to find maximum combination of element with sum less than to w with elements
int max_sum(int arr[], int n, int w, int elements[])
{
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++)
        {
            if (j - arr[i - 1] >= 0)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - arr[i - 1]] + arr[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    int i = n, j = w;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else
        {
            elements[i - 1] = arr[i - 1];
            j -= arr[i - 1];
            i--;
        }
    }
    // dbgA2(dp, n + 1, w + 1);
    // dbgA(elements, n);
    return dp[n][w];
}

void input_int_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void print_int_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void print_result(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            std::cout << arr[i] << " ";
}

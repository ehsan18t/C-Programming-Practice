#include <bits/stdc++.h>

int main()
{
    int t;
    // scanf("%d", &t);
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long x, result;
        // scanf("%lld", &x);
        std::cin >> x;
        long arr[x];
        for (int j = 0; j < x; j++)
        {
            // scanf("%d", &arr[j]);
            std::cin >> arr[j];
        }
        std::sort(arr, arr + x);
        result = arr[0] * arr[x-1];
        if (result == 1)
            result = 2;
        // printf("Case %d: %lld\n", i, result);
        std::cout << "Case " << i << ": " << result << std::endl;
    }
    return 0;
}

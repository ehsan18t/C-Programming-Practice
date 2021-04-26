#include <bits/stdc++.h>

int main()
{
    int n, result;
    scanf("%d", &n);
    int arr[n][4];
    for (int i = 0; i < n; i++)
    {
        result = 0;
        scanf("%d%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);

        for (int j = 0; j <= i; j++)
        {
            if (arr[j][0] < arr[i][2] + 1 && arr[j][1] < arr[i][3] + 1)
                result++;
        }
        printf("%d\n", result);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int n;
    int arr[100][100];
    int result = 0;
    int j = 1;
    int half;
    scanf("%d", &n);
    half = n / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= half; i++)
    {
        if (i != half)
        {
            // first half
            result += arr[i][i];
            result += arr[i][(n-i)-1];
            // last half
            result += arr[half+i][half-j];
            result += arr[half+i][half+j];
            j++;
        }
        else
        {
            // first line
            for (int j = 0; j < n; j++)
            {
                result += arr[0][j];
            }
            // last line
            for (int j = 0; j < n; j++)
            {
                result += arr[n-1][j];
            }
            // middle
            result += arr[i][i];
        }
    }
    printf("%d", result);
    return 0;
}
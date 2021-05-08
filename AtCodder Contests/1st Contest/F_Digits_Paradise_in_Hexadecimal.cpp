#include <bits/stdc++.h>

int hex_to_dec(char str[])
{
    int result = 0;
    int len = strlen(str) - 1;
    char sym[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int num[] = {10, 11, 12, 13, 14, 15};
    int power = 0;
    for (int i = len; i >= 0; i--)
    {
        if (!isdigit(str[i]))
        {
            for (int j = 0; j < 6; j++)
            {
                if (sym[j] == str[i])
                {
                    result += (num[j] * (int)(pow(16, power)));
                    break;
                }
            }
        }
        else
        {
            result += ((str[i] - 0) * (int)(pow(16, power)));
        }
        power++;
    }
    return result;
}

int numPlaces (int n) {
    if (n < 0) n = (n == INT_MIN) ? INT_MAX : -n;
    if (n < 16) return 1;
    if (n < 256) return 2;
    if (n < 4096) return 3;
    if (n < 65536) return 4;
    if (n < 1048576) return 5;
    if (n < 16777216) return 6;
    if (n < 268435456) return 7;
    if (n < 4294967296) return 8;
    if (n < 68719476736) return 9;
    /*      2147483647 is 2^31-1 - add more ifs as needed
       and adjust this final return as well. */
    return 10;
}

int hex_count(int count, int k)
{
    int hex = 0;
    int result = 0;
    for (int i = 1; i < count; i++)
    {
        if (numPlaces(hex) == k)
            result++;
        hex++;
    }
    return result;
}

int main()
{
    int n, k;
    scanf("%x%d", &n, &k);
    printf("%d", hex_count(n, k));
    return 0;
}
#include <stdio.h>

int main() {
    int arr[100];
    int n;
    int even = 0, odd = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("No. of even elements: %d\n", even);
    printf("No. of odd elements: %d\n", odd);
    return 0;
}
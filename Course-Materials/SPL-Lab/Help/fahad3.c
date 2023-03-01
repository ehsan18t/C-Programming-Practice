#include <stdio.h>

int max_index(float[], int);
void sort(float[], int);

int main()
{
    int N;
    float arr[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &arr[i]);
    }
    sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%.0f ", arr[i]);
    }
    return 0;
}

int max_index(float a[], int len)
{
    int m_index = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[m_index] < a[i])
            m_index = i;
    }
    return m_index;
}

void sort(float a[], int len)
{
    // int index;
    // float temp;
    for (int i = len - 1; i > 0; i--)
    {
        int index = max_index(a, i);
        float temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

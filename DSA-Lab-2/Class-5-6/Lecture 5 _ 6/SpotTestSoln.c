#include <stdio.h>

int main()
{

    int n, q;
    scanf("%d %d", &n, &q);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    int ansArray[q], k = 0;
    for (int x = 0; x < q; x++)
    {

        int queryType, i, j, v;
        scanf("%d", &queryType);

        if (queryType == 1)
        {
            scanf("%d", &i);
            ansArray[k] = array[i];
            k++;
            array[i] = 0;
        }
        else if (queryType == 2)
        {
            scanf("%d %d", &i, &v);
            array[i] += v;
        }
        else if (queryType == 3)
        {
            scanf("%d %d", &i, &j);
            int sum = 0;
            for (int a = i; a <= j; a++)
            {
                sum += array[a];
            }
            ansArray[k] = sum;
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d\n", ansArray[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
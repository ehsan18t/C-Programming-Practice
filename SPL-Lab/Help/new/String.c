#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Thpis is his a his string";
    char a[10] = "his";
    int startindex;
    int endindex;
    int successful = 0;
    int asize = strlen(a);
    int count = 0;
    for (int i = 0; i < 25; i++)
    {
        if (str[i] == a[0])
        {
            for (int j = 0; j < asize; j++)
            {
                if (a[j] == str[i+j])
                {
                    if (j == 0)
                        startindex = i + j;
                    if (j == asize - 1)
                    {
                        successful = 1;
                        endindex = i + j;
                    }
                }
                else
                    break;
            }
            // if (successful == 1)
            //     break;
            
        }
    }
    printf("%d %d", startindex, endindex);
    return 0;
}
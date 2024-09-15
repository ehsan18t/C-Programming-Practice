#include <stdio.h>

// The peoples of the country of Lineland live on a strait line. The Locations of the country are numbered from 0 to 107 consecutively from left to right.

// Now, You are the newcomer to this country and neighbour matters to you. You believe that good neighbour brings blessings and bad neighbour brings curse. That's why, before being settled to a location, you want know about the neighbour. Somehow, you collected the data of the locations where currently peoples are living at. You want to live at some location X and and want to find out who is your nearest neighbour.

// Input
// First line contains an integer N(2≤N≤105), the number of peoples living in Lineland. Second line contains N integer locations L0,L1,...,LN (0≤Li≤107) where currently peoples are living at. Third line contains an integer X(0≤X≤107). Multiple people can live on a same location (May be they are family. But you are a stranger).

// Output
// Print the location of nearest neighbour from X. Print -1 if someone already lives at X. If there are multiple such locations print the rightmost one of them.

// Examples
// input
// 5
// 1 2 4 8 9
// 5
// output
// 4

// input
// 5
// 1 2 4 8 9
// 6
// output
// 8

// input
// 5
// 1 2 4 8 9
// 8
// output
// -1

int main()
{
    int N, i, a, x = 0;
    int prev;
    int next;
    scanf("%d", &N);
    int array[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &a);

    for (i = 0; i < N - 1; i++)
    {

        if (array[i] == a)
        {
            x = -1;
            break;
        }

        prev = array[i];
        next = array[i + 1];
        if (a > prev && a < next)
        {
            x = a - prev < next - a ? prev : next;
            break;
        }
    }
    printf("%d\n", x);

    return 0;
}

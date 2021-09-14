#include <stdio.h>
void main()
{
    int x, y, z, p, q;                 // uninitialized
    x = 10, y = z = 3;                 // x = 10, y = 3, z = 3
    printf("%d\n%d\n%d\n", x, y, z);   // 10 3 3
    x = (p = 2) + (q = 8) - (z = 5);   // x = 14, y = 3, z = 5
    p *= z = x - 5;                    // p = 20, y = 3, z = 5
    printf("%d\n %d\n %d\n", x, z, p); // x = 14, z = 5, p = 20
    q *= x + z + p - 2;                // q = 40, y = 3, z = 5
    --q;                               // q = 39, y = 3, z = 5
    --x;                               // x = 9, y = 3, z = 5
    p++;                               // p = 20, y = 3, z = 5
    printf("%d\n", q + x - p + 2);     // 39 + 9 - 21 + 2 = 41, p = 21
    printf("p is %d\n", p);            // p is 21
    if (p == 0)
    {
        p /= 2;          // p = 10
        printf("%d", p); // 10
    }
    else
    {
        p = p * 2;       // p = 20
        printf("%d", p); // 20
    }
}

/* Final Output:
10
3 
3 
5 
0
0
28
p is 1
2
*/
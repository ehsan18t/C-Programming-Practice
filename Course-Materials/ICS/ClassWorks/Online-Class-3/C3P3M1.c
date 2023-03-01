#include <stdio.h>
// REF: problemset-loop.pdf ----->> P10
// Write a program (WAP) that will give the sum of first N th terms for the following series.
//
//      1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14,......
//
//
// Input --->   Output
//-------------------------
//  2    --->   Result: -1
//  3    --->   Result: 2
//  4    --->   Result: -2


int main() {
    int i, n, sum = 0;
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        if(i%2 == 1)
            sum += i;
        else
            sum -= i;
    }
    printf("Result: %d\n", sum);
    return 0;
}
#include <stdio.h>
// Write a program (WAP) that will calculate the result for the first N th terms of the
// following series. [In that series sum, dot sign (.) means multiplication]
//
// 1 2 .2 + 2 2 .3 + 3 2 .4 + 4 2 .5 + .....
//
// Input ---> Output
//   2   --->   14
//   3   --->   50
//   4   --->   130
//   7   --->   924

int main(){
    int a=1, b=2, sum, n, i;
    scanf("%d", &n);
    for(i=1; i<= n; i++){
        sum += (a*a) * b;
        a = b;
        b++;
    }
    printf("Result: %d\n", sum);
    return 0;
}

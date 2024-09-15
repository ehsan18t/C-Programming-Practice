#include <stdio.h>
// Write a program (WAP) that will print following series upto N th terms.
//
//      1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,....
//
//
// Input ---> Output
//----------------------------
// 1 ---> 1
// 2 ---> 1, 0
// 3 ---> 1, 0, 1
// 4 ---> 1, 0, 1, 0
// 7 ---> 1, 0, 1, 0, 1, 0, 1
// 13 ---> 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1


int main() {
    int i, n;
    scanf("%d",&n);
    for(i=1; i<n; i++){
        printf("%d, ", i%2);
    }
    printf("%d\n", n%2);
    return 0;
}

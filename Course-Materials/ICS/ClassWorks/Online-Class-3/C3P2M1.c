#include <stdio.h>
// Write a program (WAP) that will take N numbers as inputs and compute their average.
// (Restriction: Without using any array)
//
//
// Input        --->    Output
//-----------------------------------------------
// 3
// 10 20 30.5   --->  AVG of 3 inputs: 20.166667
//-----------------------------------------------
//-----------------------------------------------
// 2
// 22.4 11.1   --->  AVG of 2 inputs: 16.750000
//-----------------------------------------------


int main() {
    int i, N;
    double inp, sum=0;
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%lf",&inp);
        sum += inp;
    }
    printf("%lf", sum/N);
    return 0;
}

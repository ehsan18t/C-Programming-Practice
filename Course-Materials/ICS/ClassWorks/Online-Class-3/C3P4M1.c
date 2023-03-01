#include <stdio.h>
// Write a program (WAP) that will print Fibonacci series upto N th terms.
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, .......
//
// Input ---> Output
//  1   --->  1
//  2   --->  1, 1
//  4   --->  1, 1, 2, 3
//  7   --->  1, 1, 2, 3, 5, 8, 13

int main(){
    int a=1;
    int b=0;
	int c, n, i;
	scanf("%d", &n);
	for (i=1; i < n; i++){
		c = a + b;
		printf("%d, ", a);
		b = a;
		a = c;
	}
	printf("%d", a);
	return 0;
}

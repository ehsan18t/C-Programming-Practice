#include <stdio.h>
// Write a program that will print series of a odd number upto N th terms. (Without Last Comma)

int main (){
    int i, n;
    scanf("%d", &n);
    for(i = 1; i <= n-1; i++){
        printf("%d, ", 2 * i - 1);
    }
    printf("%d", 2 * i - 1);
    return 0;
}

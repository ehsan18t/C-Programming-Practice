#include <stdio.h>

int main(){
    int c = 0;
    double n, sum = 0;
    for(int i = 1; i <= 6; i++) {
        scanf("%lf", &n);
        if (n > 0) {
            c += 1;
            sum += n;
        }
    }
    printf("%d valores positivos\n", c);
    printf("%.1lf\n", sum/c);
    return 0;
}

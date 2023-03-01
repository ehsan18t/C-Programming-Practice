#include <stdio.h>

int main(){
    int c = 0;
    double n;
    for(int i = 1; i <= 6; i++) {
        scanf("%lf", &n);
        if (n > 0)
            c += 1;
    }
    printf("%d valores positivos\n", c);
    return 0;
}

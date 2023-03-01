#include <stdio.h>

int main(){ int n;
    scanf("%d", &n);
    for(int i = 1; i <= 6; i++) {
        if (n%2!=0) {
            printf("%d\n", n);
            n += 2;
        } else {
            n += 1;
            printf("%d\n", n);
            n += 2;
        }
    }
    return 0;
}

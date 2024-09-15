#include <stdio.h>

int main(){
    int c = 0;
    int n;
    for(int i = 1; i <= 5; i++) {
        scanf("%d", &n);
        if (n%2 == 0)
            c += 1;
    }
    printf("%d valores pares\n", c);
    return 0;
}

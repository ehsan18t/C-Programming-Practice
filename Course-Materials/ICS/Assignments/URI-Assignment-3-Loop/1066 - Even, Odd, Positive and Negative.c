#include <stdio.h>

int main(){
    int c = 0, e = 0, o = 0, p = 0, n = 0;
    int num;
    for(int i = 1; i <= 5; i++) {
        scanf("%d", &num);
        if (num > 0)
            p += 1;
        else if (num < 0)
            n += 1;
        if (num%2 == 0)
            e += 1;
        else
            o += 1;
    }
    printf("%d valor(es) par(es)\n", e);
    printf("%d valor(es) impar(es)\n", o);
    printf("%d valor(es) positivo(s)\n", p);
    printf("%d valor(es) negativo(s)\n", n);
    return 0;
}

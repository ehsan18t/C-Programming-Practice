#include <stdio.h>

int main(){ int i, x, y, s, c;
    scanf("%d %d", &x, &y);
    if (x > y)
        s = 0;
    else {
        s = x;
        x = y;
        y = s;
        s = 0;
    }
    c = (x-y)/2;
    for(i = 1; i <= c; i++) {
        if (y%2!=0) {
            y += 2;
            s += y;
        } else {
            y++;
            s += y;
        }
    }
    printf("%d\n", s);
    return 0;
}

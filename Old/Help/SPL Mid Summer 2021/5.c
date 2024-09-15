#include <stdio.h>

int main()
{
    int a = 1234 + 3;                         // a
    int b = a + 11;                           // b
    b /= 15;                                  // c
    float c = a + b;                          // d
    c++;                                      // e
    printf("A: %d, B: %d, C: %f\n", a, b, c); // d
    return 0;
}
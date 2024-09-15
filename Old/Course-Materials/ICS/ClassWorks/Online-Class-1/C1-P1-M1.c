#include <stdio.h>
// Program that will check whether a triangle is valid or not, when the three angles (angle value should be such that, 0 < value < 180) of the triangle are entered through the keyboard.
// [Hint: A triangle is valid if the sum of all the three angles is equal to 180 degrees.]
// Input ---> Output
// 90 45 45 ---> YES
// 30 110 40 ---> YES
// 160 20 30 ---> NO
// 0 180 0 ---> NO

int main() {
    double a, b, c;

    scanf("%lf%lf%lf", &a, &b, &c);

    if(a <= 0 || a >= 180) {
        printf("No\n");
    } else if (b <= 0 || b >= 180){
        printf("No\n");
    } else if (c <= 0 || c >= 180){
        printf("No\n");
    } else if(a + b + c == 180) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

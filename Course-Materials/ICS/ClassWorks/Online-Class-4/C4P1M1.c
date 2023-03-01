#include <stdio.h>
// Program that will construct a menu for performing arithmetic operations. The user will give
// two real numbers (a, b) on which the arithmetic operations will be performed and an integer
// number (1 <= Choice <= 4) as a choice. Choice-1, 2, 3, 4 are for performing addition,
// subtraction, multiplication, division respectively.
//
// If Choice-4 is selected, the program will check if b is nonzero
//
// If the check is true, the program will ask for another choice (1 <= Case <=2), where Case-1, 2
// evaluate quotient and reminder respectively. If the check is false, it will print an error
// message “Error: Divisor is zero” and halt.
//
//
// Input       --->      Output
//---------------------------------------
//  5 10
//          --->  Multiplication: 50
//  3
//---------------------------------------
//---------------------------------------
// -5 10.5
//  4       --->  Reminder: -48
//  2
//---------------------------------------
//---------------------------------------
// -5 0
//          --->  Error: Divisor is zero
//  4
//---------------------------------------


int main(){
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    if(c == 1)
        printf("Addition: %d\n", a+b);
    else if(c == 2)
        printf("Subtraction: %d\n", a-b);
    else if(c == 3)
        printf("Multiplication: %d\n", a*b);
    else if(c == 4){
            if(b == 0)
                printf("Error: Divisor is zero\n");
            else{
            scanf("%d", &d);
            switch(d){
                    case 1:
                        printf("Quotient: %d\n", a/b);
                        break;
                    case 2:
                        printf("Reminder: %d\n", a%b);
                        break;
                        }
            }
    }
    return 0;
}

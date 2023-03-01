#include <stdio.h>
// Program for “Guessing Game”:
// Player-1 picks a number X and Player-2 has to guess that number within N = 3 tries. For each
// wrong guess by Player-2, the program prints “Wrong, N-1 Chance(s) Left!” If Player-2
// successfully guesses the number, the program prints “Right, Player-2 wins!” and stops
// allowing further tries (if any left). Otherwise after the completion of N = 3 wrong tries, the
// program prints “Player-1 wins!” and halts.
//
// [ Restriction: Without using loop/break/continue
// Hint: Use flag ]
//
// Input 	---> 	    Output
//-------------------------------------------
//-------------------------------------------
//   5              Wrong, 2 Chance(s) Left!
// 12 8 5   --->    Wrong, 1 Chance(s) Left!
//                  Right, Player-2 wins!
//--------------------------------------------
//--------------------------------------------
//   100            Wrong, 2 Chance(s) Left!
// 50 100   --->    Right, Player-2 wins!
//--------------------------------------------
//--------------------------------------------
//   5              Wrong, 2 Chance(s) Left!
// 12 8 5   --->    Wrong, 1 Chance(s) Left!
//                  Player-1 wins!
//--------------------------------------------


int main(){
    int X, n1, n2, n3;
    scanf("%d", &X);
    scanf("%d", &n1);
    if (X == n1)
        printf("Right, Player-2 wins!\n");
    else {
        printf("Wrong, 2 Chance(s) Left!\n");
        scanf("%d", &n2);
        if (X == n2)
            printf("Right, Player-2 wins!\n");
        else {
            printf("Wrong, 1 Chance(s) Left!\n");
            scanf("%d", &n3);
            if (X == n3)
                printf("Right, Player-2 wins!\n");
            else {
                printf("Wrong, 0 Chance(s) Left!\n");
                printf("Player-1 wins!\n");
                }
            }
        }
        return 0;
}

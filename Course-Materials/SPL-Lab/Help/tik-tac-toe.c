#include <stdio.h>

void invalid_move();
int check_result();

int scores[3][3] = {0};

int main()
{
    char player1[100] = "";
    char player2[100] = "";
    char input[4] = "";
    int result = 0;
    int row, col;
    printf("Please enter the name of player 1 (X): ");
    scanf("%s", &player1);
    printf("Please enter the name of player 2 (O): ");
    scanf("%s", &player2);
    for (int i = 0; i < 9; i++)
    {
        // Game Board
        printf("\n\n--- Tik Tac Toe Board ---\n");
        for (int j = 0; j < 3; j++)
        {
            for (int l = 0; l < 3; l++)
            {
                if (l == 0)
                {
                    printf("\t ");
                }
                if (l == 1)
                {
                    printf("|");
                }

                // Part-1
                if (scores[j][l] == 0)
                {
                    printf("   ");
                }
                else if (scores[j][l] == 1)
                {
                    printf(" X ");
                }
                else
                {
                    printf(" Y ");
                }
                if (l == 1)
                {
                    printf("|");
                }
            }
            if (j != 2)
                printf("\n\t-------------\n");
        }
    STARTLOOP:
        if ((i % 2) + 1 == 1)
            printf("\nPlayer 1 (%s), please enter your move: ", player1);
        else
            printf("\nPlayer 2 (%s), please enter your move: ", player2);

        scanf("%s", &input);
        // Input validation
        // index 1 (comma)
        if (input[1] != ',')
        {
            invalid_move();
            goto STARTLOOP;
        }
        // index 0
        if ((input[0] - '0') > 0 && (input[0] - '0') <= 9)
        {
            row = (input[0] - '0') - 1;
        }
        else
        {
            invalid_move();
            goto STARTLOOP;
        }
        // index 2
        if ((input[2] - '0') > 0 && (input[2] - '0') <= 9)
        {
            col = (input[2] - '0') - 1;
        }
        else
        {
            invalid_move();
            goto STARTLOOP;
        }
        // Double input cheching
        if (scores[row][col] != 0)
        {
            invalid_move();
            goto STARTLOOP;
        }
        else
            scores[row][col] = (i % 2) + 1;
        // Checking for winner
        if (i > 3)
        {
            result = check_result();
            if (result != 0)
                break;
        }
    }
    // Unpolished
    // Need Screen recording
    if (result == 1)
        printf("CONGRATS Player 1(%s)!!! You are the WINNER.\n\n", player1);
    else if (result == 2)
        printf("CONGRATS Player 2(%s)!!! You are the WINNER.\n\n", player2);
    else
        printf("Match Draw!\n\n");

    printf("---GAME END---");
    return 0;
}

void invalid_move()
{
    printf("\nINVALID MOVE. PLEASE TRY AGAIN.");
}

int check_result()
{
    int result = 0;
    // Calculating Result
    for (int i = 0; i < 3; i++)
    {
        // Horizonal line
        if (scores[i][0] == scores[i][1] && scores[i][0] == scores[i][2])
        {
            result = scores[i][0];
            break;
        }
        // Vartical line
        if (scores[0][i] == scores[1][i] && scores[0][i] == scores[2][i])
        {
            result = scores[0][i];
            break;
        }
    }
    if (result != 0)
    {
        // '\' line check
        if (scores[0][0] == scores[1][1] && scores[0][0] == scores[2][2])
        {
            result = scores[0][0];
        }
        // '/' Line check
        else if (scores[0][2] == scores[1][1] && scores[0][2] == scores[2][0])
        {
            result = scores[0][2];
        }
    }
    return result;
}
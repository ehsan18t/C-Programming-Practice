#include <stdio.h>

void game_board();
void clear_input_stream();
int input_checker(int);
int check_result();

static int moves[9] = {0};

int main()
{
    int result;
    int input;
    char player1[100];
    char player2[100];
    printf("Please enter the name of player 1 (X): ");
    scanf("%s", &player1);
    printf("Please enter the name of player 1 (O): ");
    scanf("%s", &player2);
    for (int i = 0; i < 9; i++)
    {
        game_board();
        while (1)
        {
            if ((i % 2) + 1 == 1)
                printf("\nPlayer 1 (%s), please enter your move: ", player1);
            else
                printf("\nPlayer 2 (%s), please enter your move: ", player2);

            scanf("%d", &input); // number && 1-9
            clear_input_stream();
            if (input_checker(input))
                break;
            else
                printf("\nINVALID INPUT!\n\n");
        }
        moves[input - 1] = (i % 2) + 1;
        if (i > 3)
        {
            result = check_result();
            if (result)
            {
                game_board();
                break;
            }
        }
    }
    if (result == 1)
        printf("\nCONGRATS Player 1(%s)!!! You are the WINNER.\n", player1);
    else if (result == 2)
        printf("\nCONGRATS Player 2(%s)!!! You are the WINNER.\n", player2);
    else
        printf("\nMatch Draw!\n");

    printf("\n---GAME END---\n");
    return 0;
}

void game_board()
{
    int count = 1;
    printf("\n\n  --- Tik Tac Toe Board ---\n");
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            // Part-1 (Outer left)
            if (k == 0)
                printf("\t ");
            if (k == 1)
                printf("|");

            // Part-2 (Inner)
            if (moves[(j * 3) + k] == 0)
                printf(" %d ", count);
            else if (moves[(j * 3) + k] == 1)
                printf(" X ");
            else
                printf(" O ");

            // Part-3 (Outer right)
            if (k == 1)
                printf("|");
            count++;
        }
        if (j != 2)
            printf("\n\t-------------\n");
    }
    printf("\n");
}

int input_checker(int input)
{
    if (input < 1 || input > 9)
        return 0;
    if (moves[input - 1] != 0)
        return 0;
    return 1;
}

int check_result()
{
    int result = 0;
    // Calculating Result
    for (int i = 0; i < 3; i++)
    {
        // Horizontal line
        if (moves[i * 3] == moves[(i * 3) + 1] && moves[i * 3] == moves[(i * 3) + 2])
        {
            result = moves[i * 3];
            break;
        }
        // Vartical line
        if (moves[i] == moves[3 + i] && moves[i] == moves[6 + i])
        {
            result = moves[i];
            break;
        }
    }
    if (result)
    {
        // '\' line check
        if (moves[0] == moves[4] && moves[0] == moves[8])
            result = moves[0];
        // '/' Line check
        else if (moves[2] == moves[4] && moves[2] == moves[6])
            result = moves[2];
    }
    return result;
}

void clear_input_stream()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
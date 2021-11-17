#include <stdio.h>

typedef struct
{
    int played;
    int won;
    int lost;
    int points;
} Club;

Club takeInput();
void showPointsLessThan60(Club[], int);

int main()
{
    int len;
    Club arr[1000];
    scanf("%d", &len);
    // Taking input
    for (int i = 0; i < len; i++)
        arr[i] = takeInput();
    // printing output with function
    showPointsLessThan60(arr, len);
    return 0;
}

Club takeInput()
{
    Club a;
    scanf("%d%d%d%d", &a.played, &a.won, &a.lost, &a.points);
    return a;
}

void showPointsLessThan60(Club arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        // using given logic to print output
        if (arr[i].points < 60 && arr[i].lost <= 5)
            printf("Team: %d, Played: %d, Won: %d, Lost: %d, Points: %d\n", i+1, arr[i].played, arr[i].won, arr[i].lost, arr[i].points);
    }
}


#include <stdio.h>

typedef struct
{
    char name[50];
    char country[50];
    int runs[3];
    int wickets[3];
    int points[3];
} player;

int count_points(int a)
{
    int runs[] = {100, 75, 50, 25};
    int points[] = {10, 7, 4, 2};
    for (int i = 0; i < 4; i++)
    {
        if (a >= runs[i])
            return points[i];
    }
    return 0;
}
player MOM(player arr[], int count)
{
    int index = 0;
    for (int i = 1; i < 3; i++)
    {
        if (arr[i].points[count] > arr[index].points[count])
            index = i;
    }
    return arr[index];
}

player MOS(player arr[])
{
    // passing array of man of the match of 3 matches
    int index = 0;
    for (int i = 1; i < 3; i++)
    {
        if (arr[i].points[i] > arr[index].points[i])
            index = i;
    }
    return arr[index];
}

int main()
{
    player all[22];
    player mom[3];
    player mos;
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", &all[i].name);
        // gets(all[i].name);
        // fflush(stdin);
        scanf("%s", &all[i].country);
        // run input
        for (int j = 0; j < 3; j++)
            scanf("%d", &all[i].runs[j]);
        // wickets input
        for (int j = 0; j < 3; j++)
            scanf("%d", &all[i].wickets[j]);
        // points count
        for (int j = 0; j < 3; j++)
        {
            all[i].points[j] = count_points(all[i].runs[j]);
            all[i].points[j] += all[i].wickets[j] * 5;
        }
    }
    // man of the matches
    for (int j = 0; j < 3; j++)
    {
        mom[j] = MOM(all, j);
        printf("Man of the match %d: %s\n", j, mom[j].name);
    }
    // man of the series
    mos = MOS(mom);
    printf("Man of the series: %s\n", mos.name);
    return 0;
}

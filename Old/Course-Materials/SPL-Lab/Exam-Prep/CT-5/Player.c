#include <stdio.h>

typedef struct
{
    char name[100];
    char country[50];
    int runs[2];
    int wickets[2];
} Player;

int main()
{
    Player bd[2];
    int total_points[2][2];
    for (int i = 0; i < 2; i++)
    {
        gets(bd[i].name);
        getchar();
        gets(bd[i].country);
        getchar();
        scanf("%d%d", &bd[i].runs[0], &bd[i].runs[1]);
        scanf("%d%d", &bd[i].wickets[0], &bd[i].wickets[1]);
        for (int j = 0; j < 2; j++)
        {
            // Wickets calculation
            total_points[i][j] = (bd[i].wickets[j] * 12);

            // Runs calculation
            if (bd[i].runs[j] >= 100)
            {
                total_points[i][j] += bd[i].runs[j] * 20;
            }
            else if (bd[i].runs[j] >= 75)
            {
                total_points[i][j] += bd[i].runs[j] * 15;
            }
            else if (bd[i].runs[j] >= 50)
            {
                total_points[i][j] += bd[i].runs[j] * 10;
            }
            else if (bd[i].runs[j] >= 25)
            {
                total_points[i][j] += bd[i].runs[j] * 5;
            }
        }
    }
    int max_point_index = -1;
    int max_point = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (total_points[i][j] > max_point)
            {
                max_point = total_points[i][j];
                max_point_index = i;
            }
        }
    }
    printf("%s", bd[max_point_index].name);
    return 0;
}
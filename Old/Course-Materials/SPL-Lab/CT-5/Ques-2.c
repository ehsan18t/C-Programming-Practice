#include <stdio.h>

struct Player
{
    int played_match;
    int total_runs;
    int highest_score;
    float avg;
};

struct Player takeInput()
{
    struct Player a;
    scanf("%d", &a.played_match);
    scanf("%d", &a.total_runs);
    scanf("%d", &a.highest_score);
    scanf("%f", &a.avg);
    return a;
}

void showAvgMoreThan50(struct Player a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i].played_match >= 100 && a[i].avg > 50)
        {
            printf("Played Matchs: %d, Total Runs: %d, Highest Score: %d, Avarage: %.2f\n", a[i].played_match, a[i].total_runs, a[i].highest_score, a[i].avg);
        }
    }
}

int main()
{
    int n;
    struct Player a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i] = takeInput();
    }
    showAvgMoreThan50(a, n);
    return 0;
}

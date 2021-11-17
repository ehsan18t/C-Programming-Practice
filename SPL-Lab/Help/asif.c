#include <stdio.h>

typedef struct
{
    char song_name[100];
} Song;

int take_input(int a, int b)
{
    scanf("%d%d", &a, &b);
    return a + b;
}

void play_song(int a, Song song_list[])
{
    char ch;
    printf("Want to play song %d?", a);
    getchar();
    ch = getchar();
    if (ch == '\n')
    {
        printf("\n%s\n", song_list[a].song_name);
    }
}

int main()
{
    int a, b;
    int song_num;
    Song bts[11] = {"PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!", "CRIPTONIZE", "OFFLINEDAY", "SALT", "ANSWER", "RAR?", "WIFI ANTENNAS"};
    song_num = take_input(a, b);
    play_song(song_num, bts);
    return 0;
}
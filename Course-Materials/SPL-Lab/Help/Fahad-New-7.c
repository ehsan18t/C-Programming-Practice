#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 1;
    char ch;
    FILE *fw = fopen("3_chars.txt", "w");
    FILE *fr = fopen("chars.txt", "r");
    if (fr == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }

    while (!feof(fr))
    {
        fscanf(fr, "%c", &ch);
        if (count % 3 == 0)
            fprintf(fw, "%c", ch);
        count++;
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
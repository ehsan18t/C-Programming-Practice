#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r");
    FILE *sum = fopen("output.txt", "w");

    if (f != NULL)
    {
        while (feof(f) == 0)
        {
            int n1, n2, n3;
            fscanf(f, "%d %d %d", &n1, &n2, &n3);
            // printf("read %d %d %d\n", n1, n2, n3);
            fprintf(sum, "%d\n", n1 + n2 + n3);
        }
    }
    fclose(f);
    fclose(sum);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string_input[5] = "";
    char output[5] = "";
    int count;
    int a = 0, b = 0, c = 0, d = 0;
    printf("\n First Code: ");
    scanf("%s", &string_input);
    printf(" Total Code Count: ");
    scanf("%d", &count);
    sprintf(output, "%s", string_input);
    printf("\n \t Codes: %s\n", output);
    for (int i = 0; i < count; i++)
    {
        switch (i % 4)
        {
            case 0:
                output[a] = (output[a] == '1') ? '0' : '1';
                printf("\t\t%s\n", output);
                break;
            case 1:
                output[b] = (output[b] == '1') ? '0' : '1';
                printf("\t\t%s\n", output);
                break;
            case 2:
                output[c] = (output[c] == '1') ? '0' : '1';
                printf("\t\t%s\n", output);
                break;
            case 3:
                output[d] = (output[d] == '1') ? '0' : '1';
                printf("\t\t%s\n", output);
                a++;
                break;
            default:
                break;
        }
    }
    return 0;
}

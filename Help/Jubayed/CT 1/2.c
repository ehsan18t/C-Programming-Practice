#include <stdio.h>

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int matrix[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);

    // replace duplicate int with -1
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] == matrix[i][j - 1])
                matrix[i][j] = -1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
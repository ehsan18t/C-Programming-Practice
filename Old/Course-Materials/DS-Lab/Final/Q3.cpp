#include <stdbool.h>
#include <stdio.h>

char bag[100], arr[100][100];
int top = -1, a, b, t = 1, u = 0, l = 0, r = 0, d = 0;

void push(char item)
{
    if (top != 100)
    {
        top++;
        bag[top] = item;
    }
}

char pop()
{
    if (top != 1)
    {
        char ch = bag[top];
        top--;
        return ch;
    }
}

bool hasup()
{
    if (arr[a - 1][b] == '.' || arr[a - 1][b] == 'A' || arr[a - 1][b] == 'B' ||
        arr[a - 1][b] == 'C' || arr[a - 1][b] == 'M' || arr[a - 1][b] == 'N' ||
        arr[a - 1][b] == 'O')
    {
        a--;
        return true;
    }
    else
    {
        return false;
    }
}

bool hasdown()
{
    if (arr[a + 1][b] == '.' || arr[a + 1][b] == 'A' || arr[a + 1][b] == 'B' ||
        arr[a + 1][b] == 'C' || arr[a + 1][b] == 'M' || arr[a + 1][b] == 'N' ||
        arr[a + 1][b] == 'O')
    {
        a++;
        return true;
    }
    else
    {
        return false;
    }
}

bool hasleft()
{
    if (arr[a][b - 1] == '.' || arr[a][b - 1] == 'A' || arr[a][b - 1] == 'B' ||
        arr[a][b - 1] == 'C' || arr[a][b - 1] == 'M' || arr[a][b - 1] == 'N' ||
        arr[a][b - 1] == 'O')
    {
        b--;
        return true;
    }
    else
    {
        return false;
    }
}

bool hasright()
{
    if (arr[a][b + 1] == '.' || arr[a][b + 1] == 'A' || arr[a][b + 1] == 'B' ||
        arr[a][b + 1] == 'C' || arr[a][b + 1] == 'M' || arr[a][b + 1] == 'N' ||
        arr[a][b + 1] == 'O')
    {
        b++;
        return true;
    }
    else
    {
        return false;
    }
}

void work()
{
    if (arr[a][b] == 'A' || arr[a][b] == 'B' || arr[a][b] == 'C')
    {
        push(arr[a][b]);
        printf("Blade found: %c\n", arr[a][b]);
    }
    if (arr[a][b] == 'M' || arr[a][b] == 'N' || arr[a][b] == 'O')
    {
        if (pop() == 'A' && arr[a][b] == 'M')
        {
            printf("Enemy M is killed\n");
        }
        else if (pop() == 'B' && arr[a][b] == 'N')
        {
            printf("Enemy N is killed\n");
        }
        else if (pop() == 'C' && arr[a][b] == 'O')
        {
            printf("Enemy O is killed\n");
        }
        else if (arr[a][b] != '.')
        {
            printf("You are killed by enemy %c\n", arr[a][b]);
            t = 0;
        }
    }
    if (top == -1 && arr[a][b] != '.')
    {
        printf("You are killed by enemy %c\n", arr[a][b]);
        t = 0;
    }
    if (arr[a][b] == 'E')
    {
        t = 0;
    }
}

int main()
{
    int i, j, n, m, upordown = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if ('S' == arr[i][j])
            {
                a = i;
                b = j;
                break;
            }
        }
    }

    if (arr[a + 1][b] == '.' || arr[a + 1][b] == 'A' || arr[a + 1][b] == 'B' ||
        arr[a + 1][b] == 'C' || arr[a + 1][b] == 'M' || arr[a + 1][b] == 'N' ||
        arr[a + 1][b] == 'O')
    {
        upordown = 1;
    }

    while (t == 1)
    {
        if (hasup())
        {
            u++;
            d = 0;
            l = 0;
            r = 0;
            work();
        }
        else if (hasdown())
        {
            r = 0;
            d++;
            u = 0;
            l = 0;
            work();
        }
        else if (hasright())
        {
            r++;
            d = 0;
            u = 0;
            l = 0;
            work();
        }
        else if (hasleft())
        {
            l++;
            d = 0;
            u = 0;
            r = 0;
            work();
        }
        else if (hasup())
        {
            u++;
            d = 0;
            l = 0;
            r = 0;
            work();
        }
    }

    return 0;
}
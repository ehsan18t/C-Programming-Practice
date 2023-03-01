#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int data[100];
    int top;
    int size;
    struct stack *next;
} typedef stack;

// global variables
stack s1;

bool is_full()
{
    return (s1.size == s1.top ? true : false);
}

bool is_empty()
{
    return (s1.top == -1 ? true : false);
}

void push(int value)
{
    if (!is_full())
    {
        s1.top++;
        s1.data[s1.top] = value;
    }
    else
        printf("Stack is full!\n");
}

void pop()
{
    if (!is_empty())
        s1.top--;
    else
        printf("Stack is empty!\n");
}

int peek()
{
    if (s1.top != -1)
        return s1.data[s1.top];
    else
        printf("Stack is empty\n");
}

void printStack()
{
    if (!is_empty())
        for (int i = 0; i <= s1.top; i++)
            printf("%d ", s1.data[i]);
    else
        printf("Stack is empty!\n");
    printf("\n");
}

void menu()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. is_full\n");
    printf("4. is_empty\n");
    printf("5. Top_up\n");
    printf("6. Print Stack\n");
    printf("7. Exit\n");
}

int main()
{
    // codes
    int opt;
    int value;
    int loop = 1;
    s1.size = 5;
    s1.top = -1;

    // options
    while (loop)
    {
        // menu
        menu();
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            /* push */
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            /* pop */
            pop();
            break;
        case 3:
            /* is_full */
            if (is_full())
                printf("Yes\n");
            else
                printf("No\n");
            break;
        case 4:
            /* is_empty */
            if (is_empty())
                printf("Yes\n");
            else
                printf("No\n");
            break;
        case 5:
            /* Top_up */
            peek();
            break;
        case 6:
            printStack();
            break;
        case 7:
            loop = 0;
            break;
        }
    }
    return 0;
}

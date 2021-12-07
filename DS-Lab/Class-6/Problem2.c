#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int pop()
{
    if (!is_empty())
    {
        int data = s1.data[s1.top];
        s1.top--;
        return data;
    }
    else
        printf("Stack is empty!\n");
}

bool is_num(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
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

int postFix(char str[])
{
    int i = 0;
    int data;
    while (str[i] != '\0')
    {
        // converting char to int
        if (is_num(str[i]))
        {
            data = str[i] - '0';
            push(data);
        }
        else
        {
            int n1 = pop();
            int n2 = pop();
            switch (str[i])
            {
            case '+':
                /* addition */
                push(n2 + n1);
                break;
            case '-':
                /* substraction */
                push(n2 - n1);
                break;
            case '*':
                /* multiplicatin */
                push(n2 * n1);
                break;
            case '/':
                /* divide */
                push(n2 / n1);
                break;
            default:
                break;
            }
        }
        i++;
    }
    return pop();
}

int main()
{
    /* code */
    int result;
    s1.size = 100;
    s1.top = -1;
    char str[100];
    scanf("%s", str);
    result = postFix(str);
    printf("PostFix: %s\n", str);
    printf("Result: %d\n", result);
    return 0;
}

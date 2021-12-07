#include <stdio.h>

// Stack with array

void push(int stack[], int *top, int size, int value)
{
    if (top + 1 != size)
    {
        top++;
        stack[*top] = value;
    }
    else
        printf("Stack Overflow!\n");
}

int pop(int stack[], int *top)
{
    int data = stack[*top];
    if (stack != -1)
    {
        *top--;
        return stack[*top];
    }
    printf("Stack Underflow!");
}

int main()
{
    // codes
    return 0;
}
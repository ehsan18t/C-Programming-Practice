#include <stdio.h>
#include <stdlib.h>>

struct stack
{
    int data;
    struct stack *next;
} typedef stack;

// pop value in stack
int pop(stack **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int data = (*top)->data;
        stack *temp = *top;
        *top = (*top)->next;
        free(temp);
        return data;
    }
}

// push value in stack
void push(stack **top, int data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int main()
{
    // codes
    return 0;
}
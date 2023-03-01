#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} typedef node;

void print(node *head);

int main()
{
    node *a, *b, *c, *d;

    // Allocation Memory
    a = (node *)malloc(sizeof(node));
    b = (node *)malloc(sizeof(node));
    c = (node *)malloc(sizeof(node));
    d = (node *)malloc(sizeof(node));

    // Linking
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    // Adding data
    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;

    print(a);
    return 0;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} typedef node;

int main()
{
    node *a, *b, *c, *d;
    a = (node *)malloc(sizeof(node));
    a->data = 10;

    b = (node *)malloc(sizeof(node));
    b->data = 20;

    c = (node *)malloc(sizeof(node));
    c->data = 30;

    d = (node *)malloc(sizeof(node));
    d->data = 40;

    // Linking
    a->next = b;
    a->next->next = c;
    a->next->next->next = d;
    a->next->next->next->next = NULL;

    // printing
    printf("a : %d\n", a->data);
    printf("b : %d\n", a->next->data);
    printf("c : %d\n", a->next->next->data);
    printf("d : %d\n", a->next->next->next->data);

    // Link last with first
    a->next->next->next->next = a;
    printf("next : %d\n", a->next->next->next->next->data);

    // removing c
    b->next = c->next;
    printf("After removing c node : %d\n", a->next->next->next->next->data);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
} typedef node;

int main()
{
    node *a, *b, *c;

    a = (node *)malloc(sizeof(node));
    a->data = 10;

    b = (node *)malloc(sizeof(node));
    b->data = 20;

    c = a;
    c->data = 50;

    a = (node *)malloc(sizeof(node));
    a->data = 100;

    printf("a : %d\n", a->data);
    printf("c : %d\n", c->data);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// single linked list
struct node
{
    int data;
    int count;
    struct node *next;
} typedef node;

// print list considering the count
void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        for (int i = 0; i < temp->count; i++)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// search node
node *search_node(node *head, int data)
{
    node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
            return current;
        current = current->next;
    }
    return NULL;
}

// add node
void add_node(node **head, int data)
{
    node *res = search_node(*head, data);
    if (res != NULL)
        res->count++;
    else
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->count = 1;
        new_node->next = *head;
        *head = new_node;
    }
}

// Generate Random Number
node *generateRand(int size)
{
    int start = 1;
    int end = 100;

    node *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int val = (rand() % (end - start + 1)) + start;
        add_node(&head, val);
    }
    return head;
}

void swap(node *a, node *b)
{
    // swap data
    int temp = a->data;
    a->data = b->data;
    b->data = temp;

    // swap count
    temp = a->count;
    a->count = b->count;
    b->count = temp;
}

// order list by count
void order_list(node **head)
{
    node *current = *head;
    node *next = NULL;
    int temp;
    while (current != NULL)
    {
        next = current->next;
        while (next != NULL)
        {
            if (current->count < next->count)
                swap(current, next);
            next = next->next;
        }
        current = current->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node *head = generateRand(n);
    print_list(head);
    order_list(&head);
    print_list(head);
}
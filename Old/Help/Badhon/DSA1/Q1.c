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
node *search(node *head, int data)
{
    node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == data)
            break;
        current = current->next;
    }
    return current;
}

// add node
node *add_node(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    node *temp = search(head, data);

    if (temp->next != NULL)
        temp->next->count++;
    else
        temp->next = new_node;
    return head;
}

// Generate Random Number
node *random(int size)
{
    int start = 1;
    int end = 100;

    node *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        head = add_node(head, ((rand() % (end - start + 1)) + start));
    return head;
}

// selection sort desc by count
void order_list(node **head)
{
    node *temp = *head;
    node *max = NULL;
    while (temp != NULL)
    {
        max = temp;
        node *current = temp->next;
        while (current != NULL)
        {
            if (current->count > max->count)
                max = current;
            current = current->next;
        }
        // swap
        int temp_data = temp->data;
        int temp_count = temp->count;
        temp->data = max->data;
        temp->count = max->count;
        max->data = temp_data;
        max->count = temp_count;

        temp = temp->next;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    node *head = random(N);

    print_list(head);
    order_list(&head);
    print_list(head);
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

// find end of circular linked list
node *find_end(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    return temp;
}

// add node in circular linked list
void add_node(node **head, int data)
{
    node *tail = find_end(*head);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = *head;
    }
    else
    {
        tail->next = new_node;
        new_node->next = *head;
    }
}

// add node at the beginning of circular linked list
void add_node_at_beginning(node **head, int data)
{
    node *tail = find_end(*head);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = *head;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
        tail->next = *head;
    }
}

// length of circular linked list
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// print circular linked list
void print_list(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

// print last node circular linked list
void delete(node **head)
{
    node *tail = find_end(*head);
    node *temp = *head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = *head;
    free(tail);
}

void delete_head(node **head)
{
    node *tail = find_end(*head);
    node *temp = *head;
    *head = (*head)->next;
    tail->next = *head;
    free(temp);
}

// add node after a given node
void add_node_after(node **head, int data, int after_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    node *temp = *head;
    while (temp->data != after_data)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// add node before a given node
void add_node_before(node **head, int data, int before_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    node *temp = *head;
    while (temp->next->data != before_data)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// add node at a given position
void add_node_at_position(node **head, int data, int position)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    node *temp = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// delete node at a given position
void delete_node_at_position(node **head, int position)
{
    node *temp = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

//////////////////////////
// Functions: add node  //
//////////////////////  //

// add a node to the end of the list
void add_node(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// add a node to the beginning of the list
void add_node_front(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// add a node after a given node
void add_node_after(node **head, int data, int after_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

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
    new_node->next = NULL;

    node *temp = *head;
    if (temp->data == before_data)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        while (temp->next->data != before_data)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// add node at a given position
void add_node_at_pos(node **head, int data, int pos)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node *temp = *head;
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// add node before a given position
void add_node_before_pos(node **head, int data, int pos)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node *temp = *head;
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// add node after a given value
void add_node_after_value(node **head, int data, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node *temp = *head;
    while (temp->data != value)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// add node before a given value
void add_node_before_value(node **head, int data, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node *temp = *head;
    if (temp->data == value)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        while (temp->next->data != value)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// print the list
void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/////////////////////////////
// Functions: delete node  //
/////////////////////////////
// delete a node from the end of the list
void delete_node(node **head)
{
    node *temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

// delete a node from the beginning of the list
void delete_node_front(node **head)
{
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

// delete a node after a given value
void delete_node_after(node **head, int data)
{
    node *temp = *head;
    while (temp->data != data)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

// delete a node before a given value
void delete_node_before(node **head, int data)
{
    node *temp = *head;
    if (temp->data == data)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        while (temp->next->data != data)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

// delete a node at a given position
void delete_node_at_pos(node **head, int pos)
{
    node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

// delete a node before a given position
void delete_node_before_pos(node **head, int pos)
{
    node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

// delete a node after a given position
void delete_node_after_pos(node **head, int pos)
{
    node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int main()
{
    node *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);
    return 0;
}
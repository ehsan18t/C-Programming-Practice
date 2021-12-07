#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} typedef node;

// add node
void add_node(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

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
        new_node->prev = temp;
    }
}

// add node at the beginning
void add_node_at_beginning(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

// add node at the end
void add_node_at_end(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

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
        new_node->prev = temp;
    }
}

// add node at the position
void add_node_at_position(node **head, int data, int position)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// add node after a given position
void add_node_after_position(node **head, int data, int position)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// add node before a given position
void add_node_before_position(node **head, int data, int position)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// add node before a given data
void add_node_before_data(node **head, int data, int given_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        while (temp->data != given_data)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// add node after a given data
void add_node_after_data(node **head, int data, int given_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *temp = *head;
        while (temp->data != given_data)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// delete node
void delete_node(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// delete node at the beginning
void delete_node_at_beginning(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

// delete node at the end
void delete_node_at_end(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// delete node at the position
void delete_node_at_position(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// delete node after a given position
void delete_node_after_position(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// delete node before a given position
void delete_node_before_position(node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// delete node after a given data
void delete_node_after_data(node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        while (temp->data != data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// delete node before a given data
void delete_node_before_data(node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = *head;
        while (temp->data != data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// print list
void print_list(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

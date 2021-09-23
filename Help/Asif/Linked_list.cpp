#include <bits/stdc++.h>

typedef struct node node;

struct node
{
    int data;
    node *next;
};

void display(node *head);
node *insert_begin(node *head, int data);
node *insert_end(node *head, int data);
node *insert_after(node *head, int data, int key);
node *insert_before(node *head, int data, int key);
node *delete_begin(node *head);
node *delete_end(node *head);
node *delete_after(node *head, int key);
node *delete_before(node *head, int key);
node *delete_data(node *head, int data);
node *delete_key(node *head, int key);
node *reverse(node *head);
int length(node *head);
node *middle(node *head);
node *nth_from_end(node *head, int n);
node *nth_from_begin(node *head, int n);

int main()
{
    node *head, *a1, *a2, *a3, *a4;
    a1 = new node;
    a1->data = 1;

    a2 = new node;
    a2->data = 2;

    a3 = new node;
    a3->data = 3;

    a4 = new node;
    a4->data = 4;

    a3->next = a4;
    a2->next = a3;
    a1->next = a2;
    a4->next = NULL;

    head = a1;

    display(head);
    head = insert_begin(head, 0);
    display(head);
    head = insert_end(head, 5);
    display(head);
    head = insert_after(head, 6, 2);
    display(head);
    head = insert_before(head, 7, 4);
    display(head);
    head = delete_begin(head);
    display(head);
    head = delete_end(head);
    display(head);
    head = delete_after(head, 2);
    display(head);
    head = delete_before(head, 4);
    display(head);
    head = delete_data(head, 3);
    display(head);
    head = delete_key(head, 2);
    display(head);
    head = reverse(head);
    display(head);

    return 0;
}

// Function to display the linked list
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to insert a node at the beginning
node *insert_begin(node *head, int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

// function to insert a node at the end
node *insert_end(node *head, int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

// Function to insert a node after a given node
node *insert_after(node *head, int data, int key)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    node *temp1 = head;
    while (temp1->data != key)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}

// Function to insert a node before a given node
node *insert_before(node *head, int data, int key)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    node *temp1 = head;
    while (temp1->next->data != key)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}

// Function to delete a node from the beginning
node *delete_begin(node *head)
{
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to delete a node from the end
node *delete_end(node *head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete temp->next;
    return head;
}

// Function to delete a node after a given node
node *delete_after(node *head, int key)
{
    node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

// Function to delete a node before a given node
node *delete_before(node *head, int key)
{
    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

// Function to delete a node with a given data
node *delete_data(node *head, int data)
{
    node *temp = head;
    while (temp->data != data)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

// Function to delete a node with a given key
node *delete_key(node *head, int key)
{
    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

// function to reverse the linked list
node *reverse(node *head)
{
    node *temp = head;
    node *prev = NULL;
    node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

// function to find the length of the linked list
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// function to find the middle of the linked list
node *middle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// function to find the nth node from the end
node *nth_from_end(node *head, int n)
{
    node *slow = head;
    node *fast = head;
    while (n--)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// function to find the nth node from the beginning
node *nth_from_begin(node *head, int n)
{
    node *temp = head;
    while (n--)
    {
        temp = temp->next;
    }
    return temp;
}

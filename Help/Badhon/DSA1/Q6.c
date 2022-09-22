#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

node *add(node *head, int data)
{
    node *temp = head;

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

node *add_head(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    return temp;
}

void print_list(node *head)
{
    node *t;
    t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

// Generate Random Number
void generateRand(int arr[], int size)
{
    int start = 1;
    int end = 100;
    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

node *delete_head(node *head, int value)
{
    // if value found delete
    node *temp = head;
    node *prev = temp;
    while (temp != NULL)
    {
        if (temp->data == value)
            break;
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL)
    {
        if (temp == head)
            head = head->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    return head;
}

node *notMoreThanTwo(node *head, int value)
{
    int count = 0;
    node *temp = head;
    // check if there are 2
    while (temp != NULL)
    {
        if (temp->data == value)
            count++;
        if (count == 2)
            break;
        temp = temp->next;
    }

    if (temp == NULL)
        head = add_head(head, value);
    else
    {
        head = add(head, value);
        head = delete_head(head, value);
    }
    return head;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    node *head = NULL;
    int size, i = 0;
    printf("Enter size of list: ");
    scanf("%d", &size);
    int arr[size];
    generateRand(arr, size);
    printf("Random Array: ");
    printArr(arr, size);
    while (size--)
        head = notMoreThanTwo(head, arr[i++]);
    printf("After Operation: ");
    print_list(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

node *FirstInsertion(node *head, int n)
{
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = head;
    head = temp;
    return head;
}

node *LastInsertion(node *head, int n)
{
    node *temp1 = head;
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void print_list(node *head)
{
    struct node *t;
    t = head;
    while (t != NULL)
    {
        printf("%d   ", t->data);
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

node *deleteFirst(node *head, int value)
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
        head = FirstInsertion(head, value);
    else
    {
        head = LastInsertion(head, value);
        head = deleteFirst(head, value);
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
    print_list(head);
    return 0;
}
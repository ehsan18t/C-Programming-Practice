#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

struct node *head, *temp, *temp1;

void LastInsertion(int n)
{
    temp1 = head;
    temp = (struct node *)malloc(sizeof(struct node));
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
}

void print_list()
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
void generateRand(int size)
{
    int start = 1;
    int end = 100;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int val = (rand() % (end - start + 1)) + start;
        LastInsertion(val);
    }
}

void First_Insertion(int n)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = head;
    head = temp;
}

node *separateOddEven(node *head, int direction)
{
    node *temp = head;
    node *odd = NULL;
    node *even = NULL;
    node *oddTail = odd;
    node *evenTail = even;

    // separate odd and even nodes
    while (temp)
    {
        if (temp->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = temp;
                evenTail = even;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = temp;
                oddTail = odd;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
        if (evenTail != NULL)
            evenTail->next = NULL;
        if (oddTail != NULL)
            oddTail->next = NULL;
    }

    if (direction == 1)
    {
        // connect odd to even nodes
        if (odd != NULL && even != NULL)
        {
            oddTail->next = even;
            head = odd;
        }
    }
    else
    {
        // connect even to odd nodes
        if (odd != NULL && even != NULL)
        {
            evenTail->next = odd;
            head = even;
        }
    }
    return head;
}

int main()
{
    int size, dir;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter direction: ");
    scanf("%d", &dir);
    generateRand(size);
    print_list();
    head = separateOddEven(head, dir);
    printf("\n");
    print_list();
    return 0;
}
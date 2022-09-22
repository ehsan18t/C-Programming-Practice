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

node *removeNode(node *prev, node *curr)
{
    // if head
    if (prev == NULL)
    {
        head = curr->next;
        return head;
    }

    // if not head
    prev->next = curr->next;
    return curr;
}

node *separateOddEven(node *head, int direction)
{
    int size = 0;
    node *temp = head;
    node *tail = head;
    node *prev = NULL;

    // find size and tail
    while (temp != NULL)
    {
        size++;
        tail = temp;
        temp = temp->next;
    }

    temp = head;
    while (--size)
    {
        if (direction == 1)
        {
            // if data is even remove and insert last
            if (temp->data % 2 == 0)
            {
                // remove
                node *l = removeNode(prev, temp);
                temp = prev;

                // insert last
                tail->next = l;
                l->next = NULL;
                tail = l;
            }
        }
        else
        {
            // if data is odd remove and insert last
            if (temp->data % 2 != 0)
            {
                // remove
                node *l = removeNode(prev, temp);
                temp = prev;

                // insert last
                tail->next = l;
                l->next = NULL;
                tail = l;
            }
        }
        prev = temp;
        temp = temp->next;
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
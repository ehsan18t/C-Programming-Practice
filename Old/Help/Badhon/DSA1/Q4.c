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
        printf("%d   ", t->data);
        t = t->next;
    }
}

// Generate Random Number
node *generateRand(node *head, int size)
{
    int start = 1;
    int end = 100;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int val = (rand() % (end - start + 1)) + start;
        head = add(head, val);
    }
    return head;
}

// reverse the list from one node* to another node*
node *reverse(node *head, node *end)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    while (curr != end)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// sort list
node *sort(node *head)
{
    node *curr = head;
    node *next = NULL;
    node *prev = NULL;
    node *end = NULL;
    while (end != head->next)
    {
        prev = NULL;
        curr = head;
        while (curr->next != end)
        {
            next = curr->next;
            if (curr->data > next->data)
            {
                if (prev == NULL)
                {
                    curr->next = next->next;
                    next->next = curr;
                    head = next;
                    prev = next;
                }
                else
                {
                    curr->next = next->next;
                    next->next = curr;
                    prev->next = next;
                    prev = next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        end = curr;
    }
    return head;
}

node *customSort(node *head)
{
    head = sort(head);
    // separate odd and even
    node *odd = NULL;
    node *even = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
            even = add(even, curr->data);
        else
            odd = add(odd, curr->data);
        curr = curr->next;
    }

    // reverse odd
    even = reverse(even, NULL);

    // even tail
    node *evenTail = even;
    while (evenTail->next != NULL)
        evenTail = evenTail->next;

    // merge odd and even
    evenTail->next = odd;
    return even;
}

int main()
{
    int n;
    node *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = generateRand(head, n);
    printf("The list is: ");
    print_list(head);

    head = customSort(head);
    printf("\nThe new list is: ");
    print_list(head);
    return 0;
}
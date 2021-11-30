#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} typedef node;

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

int main()
{
    node *start = NULL, *prev = NULL, *temp;
    int ans;
    printf("Do you want to add data: ");
    scanf("%d", &ans);
    while (ans == 1)
    {
        if (start == NULL)
        {
            start = (node *)malloc(sizeof(node));
            printf("Enter Data: ");
            scanf("%d", &start->data);
            start->next = NULL;
        }
        else
        {
            temp = (node *)malloc(sizeof(node));
            printf("Enter data: ");
            scanf("%d", &temp->data);
            temp->next = start;
            start = temp;
        }
        printf("Do you want to add data: ");
        scanf("%d", &ans);
    }
    display(start);
    return 0;
}

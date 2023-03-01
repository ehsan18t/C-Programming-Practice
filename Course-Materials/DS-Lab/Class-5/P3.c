#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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

void displayInverse(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int sum(node *head)
{
    int sum = 0;
    node *temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void search(node *head, int value)
{
    int flag = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
        printf("Found!\n");
    else
        printf("Not Found!\n");
}

void printEvenOdd(node *head)
{
    int flag = 0;
    node *temp = head;
    printf("\nEven: ");
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nOdd: ");
    temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 1)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{
    freopen("in.txt", "r", stdin);
    node *start = NULL, *temp;
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
    printf("\n");           // line break
    printf("\nElements: "); // line break
    display(start);
    printf("\n"); // line break
    printf("sum : %d", sum(start));
    printf("\n"); // line break
    search(start, 33);
    printf("\n"); // line break
    printEvenOdd(start);
    return 0;
}

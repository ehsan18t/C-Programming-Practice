#include <stdio.h>
#include <stdlib.h>

// Add data to at the end of linked list

struct node
{
    int data;
    struct node *next;
} typedef node;
node *start;
void display()
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void showMenu()
{
    printf("\n1. Insert\n2. Delete\n3. Exit\n");
}

void insert(int item)
{
    node *temp, *temp1;
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        start->data = item;
        start->next = NULL;
    }
    else if (item <= start->data)
    {
        temp->data = item;
        temp->next = start;
        start = temp;
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->next->data >= item)
        {
            temp = temp->next;
        }

        temp1 = (node *)malloc(sizeof(node));
        temp1->data = item;
        temp1->next = temp->next;
        temp->next = temp1;
    }
}

void delete (int item)
{
    node *temp;
    if (start->data == item)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}

int main()
{
    freopen("in1.txt", "r", stdin);
    int choice, item, i = 1;
    do
    {
        showMenu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // codes
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insert(item);
            display();
            break;
        case 2:
            // codes
            printf("Enter item to delete: ");
            scanf("%d", &item);
            delete (item);
            display();
            break;
        case 3:
            i = 0;
        }

    } while (i);

    return 0;
}

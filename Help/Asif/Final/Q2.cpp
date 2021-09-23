#include <bits/stdc++.h>

typedef struct listNode node;

struct listNode
{
    int item;
    listNode *next; // keep address of next node listNode *prev; // keep address of previous node
};
struct listNode *head;  // points to the first node of the list
struct listNode *trail; // points to the last node of the list

/**********************************************************************
DEBUG FUNCTIONS START
**********************************************************************/
// Function to display the linked list
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert to next
node *insert_next(node *current, int item)
{
    node *next_node = new node;
    next_node->item = item;
    next_node->next = NULL;
    current->next = next_node;
    return next_node;
}
/************************************************************************
DEBUG FUNCTIONS END
*************************************************************************/

// main functions
void delete_node(int n);
int find_smallest(node *head);
void substract_n(int n);

int main()
{
    int smallest;
    head = new node;
    trail = new node;

    // inserting data
    head->item = 1;
    head->next = trail;
    trail = insert_next(head, 2);
    trail = insert_next(trail, 3);
    trail = insert_next(trail, 4);
    trail = insert_next(trail, 5);
    trail = insert_next(trail, 6);
    display(head);

    //deleting nodes divisible by 3
    delete_node(3);
    display(head);

    // finding smallest
    smallest = find_smallest(head);
    printf("Smallest: %d\n", smallest);

    // substracting smallest from all nodes
    substract_n(smallest);
    display(head);
    return 0;
}

// Question 1
// delete all nodes divisible by n
void delete_node(int n)
{
    node *temp = head;
    node *prev = head;
    int count = 1;
    while (temp != NULL)
    {
        if (count % n == 0)
        {
            std::cout << "Deleting node " << count << " value = " << temp->item << std::endl;
            prev->next = temp->next;
            delete temp;
            temp = prev;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
}

// Question 2
// function to find smallest element in the linked list
int find_smallest(node *head)
{
    node *temp = head;
    int smallest = temp->item;
    while (temp != NULL)
    {
        if (temp->item < smallest)
            smallest = temp->item;
        temp = temp->next;
    }
    return smallest;
}

// function to substract n from all elements in the linked list
void substract_n(int n)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp->item = temp->item - n;
        temp = temp->next;
    }
}
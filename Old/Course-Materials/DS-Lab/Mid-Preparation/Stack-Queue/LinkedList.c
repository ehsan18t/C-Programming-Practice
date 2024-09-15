#include <stdio.h>
#include <stdlib.h>

////////////////
// STRUCTURES //
////////////////
struct node
{
    int data;
    struct node *next;
} typedef node;

struct stack
{
    node *top;
    node *head;
} typedef stack;

struct queue
{
    node *front;
    node *head;
} typedef queue;

//////////////////////////////////////
// START LINKED LIST IMPLEMENTATION //
//////////////////////////////////////
node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

node *addNode(node *head, int data)
{
    node *new = newNode(data);
    if (head == NULL)
        head = new;
    else
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
    return head;
}

node *removeNode(node *head)
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            node *del = head;
            head = head->next;
            free(del);
        }
        else
        {
            node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
    }
    return head;
}

node *addHead(node *head, int data)
{
    node *new = newNode(data);
    new->next = head;
    head = new;
    return head;
}

node *removeHead(node *head)
{
    if (head != NULL)
    {
        node *del = head;
        head = head->next;
        free(del);
    }
    return head;
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
////////////////////////////////////
// END LINKED LIST IMPLEMENTATION //
////////////////////////////////////

/////////////////////////////////
// START QUEUE IMPLEMENTATION //
////////////////////////////////
queue newQueue()
{
    queue q;
    q.front = NULL;
    q.head = NULL;
    return q;
}

void enqueue(queue *q, int x)
{
    q->head = addNode(q->head, x);
    if (q->front == NULL)
        q->front = q->head;
}

void dequeue(queue *q)
{
    if (q->front == NULL)
        printf("Queue is empty\n");
    else
    {
        q->head = removeHead(q->head);
        q->front = q->head;
    }
}

int front(queue q)
{
    if (q.front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q.front->data;
}

void displayQueue(queue q)
{
    if (q.front == NULL)
        printf("Queue is empty\n");
    else
        printList(q.head);
}
//////////////////////////////
// END QUEUE IMPLEMENTATION //
//////////////////////////////

/////////////////////////////////
// START STACK IMPLEMENTATION //
////////////////////////////////
stack newStack()
{
    stack s;
    s.top = NULL;
    s.head = NULL;
    return s;
}

void push(stack *s, int x)
{
    s->head = addHead(s->head, x);
    s->top = s->head;
}

void pop(stack *s)
{
    if (s->top == NULL)
        printf("Stack is empty\n");
    else
    {
        s->head = removeHead(s->head);
        s->top = s->head;
    }
}

int top(stack s)
{
    if (s.top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s.top->data;
}

void displayStack(stack s)
{
    if (s.top == NULL)
        printf("Stack is empty\n");
    else
        printList(s.head);
}
///////////////////////////////
// END STACK IMPLEMENTATION //
//////////////////////////////

///////////////////
// MAIN FUNCTION //
///////////////////
int main()
{
    /* Sample input:
        5
        1 2 3 4 5
    */

    // freopen("in.txt", "r", stdin);
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // printf("Enter Stack/Queue Capacity: ");
    // scanf("%d", &capacity);
    queue q = newQueue();
    stack s = newStack();

    // Input
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        enqueue(&q, tmp);
        push(&s, tmp);
    }

    // Print
    printf("Queue: ");
    displayQueue(q);
    printf("Stack: ");
    displayStack(s);

    // Remove
    printf("\n\n -> Starting dequeue and pop...\n\n");
    for (int i = 0; i < n; i++)
    {
        dequeue(&q);
        pop(&s);

        printf("Queue: ");
        displayQueue(q);

        printf("Stack: ");
        displayStack(s);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

////////////////
// STRUCTURES //
////////////////
struct stack
{
    int top;
    int capacity;
    int arr[100];
} typedef stack;

struct queue
{
    int front;
    int rear;
    int capacity;
    int arr[100];
} typedef queue;

/////////////////////////////////
// START QUEUE IMPLEMENTATION //
////////////////////////////////
queue newQueue(int capacity)
{
    queue q;
    q.front = 0;
    q.rear = 0;
    q.capacity = capacity;
    return q;
}

void enqueue(queue *q, int x)
{
    if (q->rear == q->capacity)
    {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear] = x;
    q->rear++;
}

void dequeue(queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

int front(queue q)
{
    if (q.front == q.rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q.arr[q.front];
}

void displayQueue(queue q)
{
    if (q.front == q.rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q.front; i < q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}
//////////////////////////////
// END QUEUE IMPLEMENTATION //
//////////////////////////////

/////////////////////////////////
// START STACK IMPLEMENTATION //
////////////////////////////////
stack newStack(int capacity)
{
    stack s;
    s.top = 0;
    s.capacity = capacity;
    return s;
}

void push(stack *s, int x)
{
    if (s->top == s->capacity)
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[s->top] = x;
    s->top++;
}

void pop(stack *s)
{
    if (s->top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    s->top--;
}

int top(stack s)
{
    if (s.top == 0)
    {
        printf("Stack is empty\n");
        return -999;
    }
    return s.arr[s.top - 1];
}

void displayStack(stack s)
{
    if (s.top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i < s.top; i++)
    {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
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
        5
        1 2 3 4 5
    */

    // freopen("in.txt", "r", stdin);
    int n, capacity;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter Stack/Queue Capacity: ");
    scanf("%d", &capacity);
    queue q = newQueue(capacity);
    stack s = newStack(capacity);

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
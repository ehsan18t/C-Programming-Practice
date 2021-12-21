#include <stdio.h>
#include <stdbool.h>

void enqueue(int arr[], int *rear, int size, int value);
int dequeue(int arr[], int *front, int rear);

bool isFull(int size, int rear)
{
    return rear == size - 1;
}

bool isEmpty(int front, int rear)
{
    return front == rear;
}

void printQueue(int arr[], int front, int rear)
{
    for (int i = front; i < rear; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 10;
    int front = -1, rear = -1;
    int queue[n];
    enqueue(queue, &rear, n, 10);
    enqueue(queue, &rear, n, 20);
    enqueue(queue, &rear, n, 30);
    enqueue(queue, &rear, n, 40);
    printQueue(queue, front, rear);
    printf("%d %d\n", isEmpty(front, rear), isFull(n, rear));
    return 0;
}

void enqueue(int arr[], int *rear, int size, int value)
{
    if (isFull(size, *rear))
    {
        printf("Queue is full\n");
        return;
    }
    (*rear)++;
    arr[*rear] = value;
}

int dequeue(int arr[], int *front, int rear)
{
    if (!isEmpty(*front, rear))
    {
        (*front)++;
        return arr[*front];
    }
    printf("Queue is empty\n");
}
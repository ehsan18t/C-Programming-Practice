#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
    int head;
    int tail;
    int a[SIZE];

    queue()
    {
        head = -1;
        tail = -1;
    }

    void enqueue(int value) // insert value at tail position
    {
        if (is_full())
        {
            printf("Queue is full\n");
            return;
        }
        a[++tail] = value;
    }

    int dequeue() // delete and return value at head position
    {
        if (is_empty())
        {
            printf("Queue is empty\n");
            return -1;
        }
        return a[++head];
    }

    bool is_empty()
    {
        return head == tail;
    }

    bool is_full()
    {
        return tail == SIZE - 1;
    }
};

int main()
{
    int data, ch;
    queue q;

    while (1)
    {
        printf("------MENU------\n");
        printf("1)  ENQUEUE\n");
        printf("2)  DEQUEUE\n");
        printf("3)  EXIT\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (!q.is_full())
            {
                scanf("%d", &data);
                q.enqueue(data);
            }
            else
                printf("Queue full.....\n");
            break;
        case 2:
            if (!q.is_empty())
            {
                data = q.dequeue();
                printf("%d\n", data);
            }
            else
                printf("Queue empty.....\n");
            break;
        case 3:
            exit(0);

        default:
            printf("Wrong input\n");
        }
    }
    return 0;
}
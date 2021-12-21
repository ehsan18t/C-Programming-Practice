#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Stack structure
struct stack
{
    int top;
    int data[SIZE];

    stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (!is_full())
            data[++top] = value;
    }

    int pop()
    {
        if (!is_empty())
        {
            return data[top--];
        }
        return -1;
    }

    bool is_full()
    {
        return (SIZE - 1 == top ? true : false);
    }

    bool is_empty()
    {
        return (top == -1 ? true : false);
    }
};

// given queue structure
struct queue
{
    int head;
    int tail;
    stack a;
    stack b;

    queue()
    {
        head = -1;
        tail = -1;
    }

    void enqueue(int value) // insert value at tail position
    {
        if (!is_full())
        {
            tail++;
            a.push(value);
            return;
        }
        printf("Queue is full\n");
    }

    int dequeue() // delete and return value at head position
    {
        if (!is_empty())
        {
            // copy queue to stack b
            for (int i = head; i < tail; i++)
                b.push(a.pop());

            int data = b.pop();

            // copy rest of the data of stack b to stack a (a is queue)
            for (int i = head; i < tail - 1; i++)
                a.push(b.pop());

            head++;
            return data;
        }
        printf("Queue is empty\n");
        return -1;
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
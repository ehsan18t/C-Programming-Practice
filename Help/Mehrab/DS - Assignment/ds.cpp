#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

struct queue
{
    node *head;

    queue()
    {
        head = NULL;
    }

    void enQueue(int val)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->val = val;
        new_node->next = NULL;

        if (isEmpty())
        {
            head = new_node;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    int deQueue()
    {
        node *temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isFull()
    {
        // linked list implementation of queue is never going to be full
    }

    void print()
    {
        node *cur = this->head;
        while (cur != NULL)
        {
            cout << cur->val << "	  ->	";
            cur = cur->next;
        }
        cout << "Null";
        cout << endl;
    }
};

int main()
{

    queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.print();

    int a = q.deQueue();
    cout << a << endl;
    q.print();

    int b = q.deQueue();
    cout << b << endl;
    q.print();

    return 0;
}
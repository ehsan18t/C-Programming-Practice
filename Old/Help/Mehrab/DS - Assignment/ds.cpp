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
        node *new_node = new node(val);

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
        if (isEmpty())
            return -1;
        if (temp->next == NULL)
        {
            int a = head->val;
            head = NULL;
            delete (temp);
            return a;
        }
        else
        {
            int a = head->val;
            head = head->next;
            delete (temp);
            return a;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isFull()
    {
        // linked list implementation of queue is never going to be full
        return false;
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
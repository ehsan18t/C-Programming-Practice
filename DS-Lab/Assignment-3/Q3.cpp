#include <iostream>
using namespace std;

struct node
{
    int data;
    int priority;
    node *next;

    node(int d, int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }

    node(int d)
    {
        data = d;
        priority = 0;
        next = NULL;
    }

    node()
    {
        priority = 0;
        next = NULL;
    }

    node *add(int data)
    {
        node *newNode = new node(data);
        newNode->next = this->next;
        this->next = newNode;
        return newNode;
    }

    node *add(int data, int p)
    {
        node *newNode = new node(data, p);
        newNode->next = this->next;
        this->next = newNode;
        return newNode;
    }

    int remove(node *someNode)
    {
        int data = someNode->data;
        delete someNode;
        return data;
    }
} typedef node;

struct priority_queue
{
    node *head;
    node *list;
    node *tail;

    priority_queue()
    {
        head = NULL;
        list = NULL;
        tail = NULL;
    }

    int rear()
    {
        return tail->data;
    }

    int back()
    {
        return tail->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            head = new node(data);
            list = head;
            tail = head;
        }
        else
            tail = tail->add(data);
    }

    void enqueue(int data, int p)
    {
        if (isEmpty())
        {
            head = new node(data, p);
            list = head;
            tail = head;
        }
        else
        {
            node *temp = head;
            node *prev = temp;
            while (temp != NULL && p <= temp->priority)
            {
                prev = temp;
                temp = temp->next;
            }
            if (prev == head)
            {
                node *temp = new node(data, p);
                temp->next = head;
                head = temp;
            }
            else if (prev == tail)
                tail = prev->add(data, p);
            else
                prev = prev->add(data, p);
        }
    }

    int dequeue()
    {
        if (isEmpty())

        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        node *temp = head;
        head = head->next;
        return temp->remove(temp);
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
} typedef priority_queue;

int main()
{
    priority_queue q;
    q.enqueue(1);
    cout << "Enqueued: 1 (p = 0)" << endl;
    q.enqueue(2, 5);
    cout << "Enqueued: 2 (p = 5)" << endl;
    q.enqueue(3, 8);
    cout << "Enqueued: 3 (p = 8)" << endl;
    q.enqueue(4, 1);
    cout << "Enqueued: 4 (p = 1)" << endl;
    q.enqueue(5, 1);
    cout << "Enqueued: 5 (p = 1)" << endl;
    q.enqueue(50);
    cout << "Enqueued: 50 (p = 0)" << endl;

    cout << endl
         << "Queue: ";
    q.display();
    cout << endl;

    cout << "Dequeued: " << q.dequeue() << endl
         << "Queue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl
         << "Queue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl
         << "Queue: ";
    q.display();
    return 0;
}
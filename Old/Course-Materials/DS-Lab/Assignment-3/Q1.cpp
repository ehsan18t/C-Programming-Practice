#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }

    node()
    {
        next = NULL;
    }

    node *add(int data)
    {
        node *newNode = new node(data);
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

struct queue
{
    node *head;
    node *list;
    node *tail;

    queue()
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
} typedef queue;

int main()
{
    queue q;
    q.enqueue(1);
    cout << "Enqueued: " << q.back() << endl;
    q.enqueue(2);
    cout << "Enqueued: " << q.back() << endl;
    q.enqueue(3);
    cout << "Enqueued: " << q.back() << endl;
    q.enqueue(4);
    cout << "Enqueued: " << q.back() << endl;
    q.enqueue(50);
    cout << "Enqueued: " << q.back() << endl;

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
}
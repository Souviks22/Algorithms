#include <iostream>
#include "Queue.h"
using namespace std;

size_t CAPACITY = 10;

Queue::Queue(int value) : head{nullptr}, tail{nullptr}, size{}
{
    head = new Node(value);
    tail = head;
    size++;
}

void Queue::enqueue(int value)
{
    if (size >= CAPACITY)
    {
        cout << ">> Queue Overflowed" << endl;
        return;
    }
    Node *new_node = new Node(value);
    if (!head)
    {
        tail = new_node;
        head = tail;
        size++;
        return;
    }
    tail->next = new_node;
    tail = tail->next;
    size++;
    cout << ">> " << value << " is enqueued" << endl;
}

void Queue::dequeue()
{
    if (!head)
    {
        cout << ">> Nothing to Delete" << endl;
        return;
    }
    Node *temp{head};
    int dequeued_data = head->data;
    head = head->next;
    delete temp;
    size--;
    cout << ">> " << dequeued_data << " removed" << endl;
}

void Queue::print()
{
    if (!head)
    {
        cout << ">> Queue is empty" << endl;
        return;
    }
    Node *temp{head};
    cout << "[ ";
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Back ]" << endl;
}
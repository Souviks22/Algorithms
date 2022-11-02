#include <iostream>
#include "Stack.h"
using namespace std;

size_t CAPACITY = 10;

Stack::Stack(int value) : head{nullptr}, size{}
{
    head = new Node(value);
    size++;
}

void Stack::push(int value)
{
    if (size >= CAPACITY)
    {
        cout << ">> Stack Overflowed" << endl;
        return;
    }
    Node *new_node = new Node(value);
    if (!head)
    {
        head = new_node;
        size++;
        return;
    }
    new_node->next = head;
    head = new_node;
    size++;
    cout << ">> " << value << " is injected" << endl;
}
void Stack::pop()
{
    if (!head)
    {
        cout << ">> Nothing to Delete" << endl;
        return;
    }
    Node *temp{head};
    int popped_data = head->data;
    head = head->next;
    delete temp;
    size--;
    cout << ">> " << popped_data << " removed" << endl;
}
int Stack::top()
{
    return head->data;
}
void Stack::print()
{
    if (!head)
    {
        cout << ">> Stack is empty" << endl;
        return;
    }
    Node *temp{head};
    cout << "[ ";
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Bottom ]" << endl;
}
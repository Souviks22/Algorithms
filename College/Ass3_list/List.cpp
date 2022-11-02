#include <iostream>
#include "List.h"
using namespace std;

List::List(int value) : head{nullptr}, size{}
{
    head = new Node(value);
    size++;
}

void List::push_front(int value)
{
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

void List::push_back(int value)
{
    Node *new_node = new Node(value);
    if (!head)
    {
        head = new_node;
        size++;
        return;
    }
    Node *temp{head};
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
    size++;
    cout << ">> " << value << " is injected" << endl;
}

void List::push(int value, size_t position)
{
    if (position < 0 || position > size)
    {
        cout << ">> Index is Out of range" << endl;
        return;
    }
    Node *new_node = new Node(value);
    if (!head)
    {
        head = new_node;
        size++;
        return;
    }
    Node *temp{head};
    size_t index{};
    while (index != position)
    {
        temp = temp->next;
        index++;
    }
    Node *next_node = temp->next;
    temp->next = new_node;
    new_node->next = next_node;
    size++;
    cout << ">> " << value << " is injected" << endl;
}

void List::pop(size_t position)
{
    if (position < 0 || position >= size)
    {
        cout << ">> Index is Out of range" << endl;
        return;
    }
    if (!head)
    {
        cout << "Nothing to Delete" << endl;
        return;
    }
    int popped_data{};
    if (!position)
    {
        popped_data = head->data;
        head = head->next;
    }
    else
    {
        Node *temp{head};
        size_t index{};
        while (index != position - 1)
        {
            temp = temp->next;
            index++;
        }
        Node *next_node = temp->next->next;
        popped_data = temp->next->data;
        delete temp->next;
        temp->next = next_node;
    }
    cout << "> " << popped_data << " removed" << endl;
}

size_t List::find(int value)
{
    if (!head)
        return -1;
    Node *temp{head};
    size_t index{};
    while (temp->data != value)
    {
        if (!temp)
            return -1;
        temp = temp->next;
        index++;
    }
    return index;
}

List List::reverse()
{
    if (!head)
        return *this;
    List reversed{};
    Node *temp{head};
    while (temp)
    {
        reversed.push_front(temp->data);
        temp = temp->next;
    }
    return reversed;
}

void List::print()
{
    Node *temp{head};
    cout << "[ ";
    while (temp)
    {
        cout << temp->data << " -> ";
        if (!temp->next)
            cout << "NULL";
        temp = temp->next;
    }
    cout << " ]" << endl;
}

void List::print_reverse()
{
    List reversed = this->reverse();
    reversed.print();
}

void List::clear()
{
    if (!head)
        return;
    Node *temp{head}, *cleanup_node{nullptr};
    while (temp)
    {
        cleanup_node = temp;
        temp = temp->next;
        delete cleanup_node;
    }
    head = nullptr;
}

List List::sort()
{
    if (!head)
        return *this;
    Node *temp{head};
    int arr[size], index{};
    while (temp)
    {
        arr[index++] = temp->data;
        temp = temp->next;
    }
    for (size_t i{}; i < size; i++)
    {
        for (size_t j{i}; j >= 0; j--)
        {
            if (arr[j] >= arr[j - 1])
                break;
            swap(arr[j], arr[j - 1]);
        }
    }
    List sorted{};
    for (size_t i{}; i < size; i++)
        sorted.push_back(arr[i]);
    return sorted;
}
#include "Queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue() : front{nullptr}, back{nullptr}, size{} {}

template <typename T>
bool Queue<T>::is_empty()
{
    return size == 0;
}

template <typename T>
int Queue<T>::get_size()
{
    return size;
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    Node<T> *new_node = new Node<T>(value);
    if (is_empty())
    {
        front = new_node;
        back = new_node;
    }
    else
    {
        back->set_next(new_node);
        back = new_node;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (is_empty())
    {
        throw NULL;
    }
    T popped = front->get_data();
    Node<T> *temp{front};
    front = front->get_next();
    delete temp;
    size--;
    return popped;
}

template <typename T>
Iterator<T> *Queue<T>::begin()
{
    return front;
}

template <typename T>
Iterator<T> *Queue<T>::end()
{
    return nullptr;
}
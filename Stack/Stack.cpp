#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack() : top{nullptr}, size{} {}

template <typename T>
bool Stack<T>::is_empty()
{
    return size == 0;
}

template <typename T>
const T &Stack<T>::get_top()
{
    if (is_empty())
    {
        throw NULL;
    }
    return top->get_data();
}

template <typename T>
int Stack<T>::get_size()
{
    return size;
}

template <typename T>
void Stack<T>::push(T value)
{
    Node<T> *new_node = new Node<T>(value);
    new_node->set_next(top);
    top = new_node;
    size++;
}

template <typename T>
T Stack<T>::pop()
{
    if (is_empty())
    {
        throw NULL;
    }
    T popped = top->get_data();
    Node<T> *temp{top};
    top = top->get_next();
    delete temp;
    size--;
    return popped;
}

template <typename T>
Iterator<T> *Stack<T>::begin()
{
    return top;
}

template <typename T>
Iterator<T> *Stack<T>::end()
{
    return nullptr;
}
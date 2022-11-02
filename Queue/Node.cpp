#include "Node.h"
using namespace std;

template <typename T>
Node<T>::Node(T value) : data{value}, next{nullptr} {}

template <typename T>
const T &Node<T>::get_data()
{
    return data;
}

template <typename T>
Node<T> *Node<T>::get_next()
{
    return next;
}

template <typename T>
void Node<T>::set_next(Node<T> *new_next)
{
    next = new_next;
}

template <typename T>
bool Node<T>::operator!=(const Iterator<T> *it)
{
    return this != it;
}

template <typename T>
const Iterator<T> *Node<T>::operator++()
{
    return next;
}

template <typename T>
const T &Node<T>::operator*()
{
    return data;
}
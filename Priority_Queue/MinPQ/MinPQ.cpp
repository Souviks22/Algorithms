#include "MinPQ.h"
using namespace std;

// Binary Heap Configuration
// Heap Order - Parent will be no smaller than children
// Parent of k is k/2 and Children of k are 2k and 2k+1

template <class T>
MinPQ<T>::MinPQ() : capacity(1), size{}
{
    arr = new T[capacity];
}

template <class T>
bool MinPQ<T>::greater(int i, int j)
{
    return arr[i - 1].compare_to(arr[j - 1]) > 0;
}

template <class T>
void MinPQ<T>::exchange(int i, int j)
{
    T temp{arr[i - 1]};
    arr[i - 1] = arr[j - 1];
    arr[j - 1] = temp;
}

template <class T>
void MinPQ<T>::resize(double factor)
{
    Comparable<T> *temp = arr;
    arr = new T[capacity * factor];
    for (int i{}; i < capacity; i++)
    {
        arr[i] = temp[i];
    }
    capacity *= factor;
    delete[] temp;
}

template <class T>
void MinPQ<T>::swim(int k)
{
    while (k > 1 && greater(k / 2, k))
    {
        exchange(k, k / 2);
        k /= 2;
    }
}

template <class T>
void MinPQ<T>::sink(int k)
{
    while (2 * k <= size)
    {
        int j = 2 * k;
        if (j < size && greater(j, j + 1))
        {
            j++;
        }
        if (!greater(k, j))
        {
            break;
        }
        exchange(k, j);
        k = j;
    }
}

template <class T>
void MinPQ<T>::insert(const Comparable<T> &obj)
{
    if (size == capacity)
    {
        resize(2);
    }
    arr[size++] = obj;
    swim(size);
}

template <class T>
T MinPQ<T>::discard()
{
    T min = arr[0];
    exchange(1, size);
    arr[--size] = (T)NULL;
    sink(1);
    if (size == capacity / 4)
    {
        resize(0.5);
    }
    return min;
}
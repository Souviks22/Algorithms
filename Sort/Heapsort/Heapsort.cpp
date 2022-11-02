#include "Heapsort.h"
using namespace std;

template <typename T>
bool Heapsort<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i - 1].compare_to(arr[j - 1]) < 0;
}

template <typename T>
void Heapsort<T>::exchange(Comparable<T> *arr, int i, int j)
{
    T temp{arr[i - 1]};
    arr[i - 1] = arr[j - 1];
    arr[j - 1] = temp;
}

template <typename T>
void Heapsort<T>::sink(Comparable<T> *arr, int size, int k)
{
    while (2 * k <= size)
    {
        int j = 2 * k;
        if (j < size && less(arr, j, j + 1))
        {
            j++;
        }
        if (!less(arr, k, j))
        {
            break;
        }
        exchange(arr, k, j);
        k = j;
    }
}

template <typename T>
void Heapsort<T>::heap_order(Comparable<T> *arr, int size)
{
    for (int i{size / 2}; i > 0; i--)
    {
        sink(arr, size, i);
    }
}

template <typename T>
void Heapsort<T>::sort(Comparable<T> *arr, int size)
{
    heap_order(arr, size);
    while (size > 0)
    {
        exchange(arr, 1, size--);
        sink(arr, size, 1);
    }
}
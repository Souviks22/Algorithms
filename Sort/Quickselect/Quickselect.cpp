#include "Quickselect.h"
using namespace std;

template <typename T>
bool Quickselect<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Quickselect<T>::exchange(Comparable<T> *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
int Quickselect<T>::partition(Comparable<T> *arr, int lo, int hi)
{
    int i{lo + 1}, j{hi};
    while (true)
    {
        while (!less(arr, lo, i++))
        {
            if (i == hi)
            {
                break;
            }
        }
        while (!less(arr, j--, lo))
        {
            if (j == lo)
            {
                break;
            }
        }
        if (i > j)
        {
            break;
        }
        exchange(arr, i, j);
    }
    exchange(arr, lo, j);
    return j;
}

template <typename T>
const T &Quickselect<T>::smallest(Comparable<T> *arr, int size, int k)
{
    int pos = k - 1, i{0}, j{size - 1};
    while (true)
    {
        int p = partition(arr, i, j);
        if (p < pos)
        {
            i = p + 1;
        }
        else if (p > pos)
        {
            j = p - 1;
        }
        else
        {
            break;
        }
    }
    return arr[pos];
}

template <typename T>
const T &Quickselect<T>::largest(Comparable<T> *arr, int size, int k)
{
    return smallest(arr, size - k + 1);
}
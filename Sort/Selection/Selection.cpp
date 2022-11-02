#include "Selection.h"
using namespace std;

template <typename T>
bool Selection<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Selection<T>::exchange(Comparable<T> *arr, int i, int j)
{
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void Selection<T>::sort(Comparable<T> *arr, int size)
{
    for (int i{}; i < size; i++)
    {
        int min = i;
        for (int j{i}; j < size; j++)
        {
            if (less(arr, j, min))
            {
                min = j;
            }
        }
        exchange(arr, i, min);
    }
}

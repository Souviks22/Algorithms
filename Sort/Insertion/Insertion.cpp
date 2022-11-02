#include "Insertion.h"
using namespace std;

template <typename T>
bool Insertion<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Insertion<T>::exchange(Comparable<T> *arr, int i, int j)
{
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void Insertion<T>::sort(Comparable<T> *arr, int size)
{
    for (int i{}; i < size; i++)
    {
        for (int j{i}; j > 0; j--)
        {
            if (!less(arr, j, j - 1))
            {
                break;
            }
            exchange(arr, j, j - 1);
        }
    }
}
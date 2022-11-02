#include "Shellsort.h"
using namespace std;

template <typename T>
bool Shellsort<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Shellsort<T>::exchange(Comparable<T> *arr, int i, int j)
{
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void Shellsort<T>::sort(Comparable<T> *arr, int size)
{
    int h{};
    while (h < size / 3)
    {
        h = 3 * h + 1;
    }
    while (h > 0)
    {
        for (int i{}; i < size; i += h)
        {
            for (int j{i}; j > h; j -= h)
            {
                if (!less(arr, j, j - h))
                {
                    break;
                }
                exchange(arr, j, j - h);
            }
        }
        h /= 3;
    }
}

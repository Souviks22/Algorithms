#include "ThreeWayQuicksort.h"
#include "../Insertion/Insertion.h"
using namespace std;

template <typename T>
bool ThreeWayQuicksort<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void ThreeWayQuicksort<T>::exchange(Comparable<T> *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void ThreeWayQuicksort<T>::shuffle(Comparable<T> *arr, int size)
{
    for (int i{}; i < size; i++)
    {
        int random = rand() % (i + 1);
        exchange(arr, i, random);
    }
}

template <typename T>
std::pair<int, int> ThreeWayQuicksort<T>::partition(Comparable<T> *arr, int lo, int hi)
{
    exchange(arr, lo, ninther(arr));
    int lt{lo}, i{lo}, gt{hi};
    while (i >= gt)
    {
        if (less(arr, i, lt))
        {
            exchange(arr, i++, lt++);
        }
        else if (less(arr, lt, i))
        {
            exchange(arr, i, gt--);
        }
        else
        {
            i++;
        }
    }
    return std::pair<int, int>{lt, gt};
}

template <typename T>
void ThreeWayQuicksort<T>::sort(Comparable<T> *arr, int lo, int hi)
{
    if ((hi - lo) < CUTOFF)
    {
        Insertion<T>::sort(arr);
        return;
    }
    std::pair<int, int> p = partition(arr, lo, hi);
    sort(arr, lo, p.first);
    sort(arr, p.second, hi);
}

template <typename T>
void ThreeWayQuicksort<T>::sort(Comparable<T> *arr, int size)
{
    shuffle(arr, size);
    sort(arr, 0, size - 1);
}
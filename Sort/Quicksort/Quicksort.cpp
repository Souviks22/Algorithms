#include "Quicksort.h"
#include "../Insertion/Insertion.h"
using namespace std;

template <typename T>
bool Quicksort<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Quicksort<T>::exchange(Comparable<T> *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void Quicksort<T>::shuffle(Comparable<T> *arr, int size)
{
    for (int i{}; i < size; i++)
    {
        int random = rand() % (i + 1);
        exchange(arr, i, random);
    }
}

template <typename T>
int Quicksort<T>::median_of_3(Comparable<T> *arr, int lo, int mid, int hi)
{
    if (less(arr, lo, mid))
    {
        if (less(arr, mid, hi))
        {
            return mid;
        }
        else if (less(arr, lo, hi))
        {
            return hi;
        }
        else
        {
            return lo;
        }
    }
    else
    {
        if (less(arr, lo, hi))
        {
            return lo;
        }
        else if (less(arr, mid, hi))
        {
            return hi;
        }
        else
        {
            return mid;
        }
    }
}

template <typename T>
int Quicksort<T>::ninther(Comparable<T> *arr, int size)
{
    int gap = size / 9;
    return median_of_3(arr,
                       median_of_3(arr, gap, gap * 2, gap * 3),
                       median_of_3(arr, gap * 4, gap * 5, gap * 6),
                       median_of_3(arr, gap * 7, gap * 8, gap * 9));
}

template <typename T>
int Quicksort<T>::partition(Comparable<T> *arr, int lo, int hi)
{
    exchange(arr, lo, ninther(arr, size));
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
void Quicksort<T>::sort(Comparable<T> *arr, int lo, int hi)
{
    if ((hi - lo) < CUTOFF)
    {
        Insertion<T>::sort(arr);
        return;
    }
    int p = partition(arr, lo, hi);
    sort(arr, lo, p);
    sort(arr, p + 1, hi);
}

template <typename T>
void Quicksort<T>::sort(Comparable<T> *arr, int size)
{
    shuffle(arr, size);
    sort(arr, 0, size - 1);
}
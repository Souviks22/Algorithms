#include "Mergesort.h"
#include "../Insertion/Insertion.h"
using namespace std;

template <typename T>
bool Mergesort<T>::less(Comparable<T> *arr, int i, int j)
{
    return arr[i].compare_to(arr[j]) < 0;
}

template <typename T>
void Mergesort<T>::exchange(Comparable<T> *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void Mergesort<T>::merge(Comparable<T> *arr, Comparable<T> *aux, int lo, int mid, int hi)
{
    for (int i{lo}; i <= hi; i++)
    {
        aux[i] = arr[i];
    }
    int i{lo}, j{mid + 1};
    for (int k{lo}; k <= hi; k++)
    {
        if (i > mid)
        {
            arr[k++] = aux[j++];
        }
        else if (j > hi)
        {
            arr[k++] = aux[i++];
        }
        else if (less(aux, j, i))
        {
            arr[k++] = aux[j++];
        }
        else
        {
            arr[k++] = aux[i++];
        }
    }
}

template <typename T>
void Mergesort<T>::sort(Comparable<T> *arr, Comparable<T> *aux, int lo, int hi)
{
    if ((hi - lo) < CUTOFF)
    {
        Insertion<T>::sort(arr);
        return;
    }
    int mid = (lo + hi) / 2;
    sort(arr, aux, lo, mid);
    sort(arr, aux, mid + 1, hi);
    if (!less(arr, mid + 1, mid))
    {
        return;
    }
    merge(arr, aux, lo, mid, hi);
}

template <typename T>
void Mergesort<T>::sort(Comparable<T> *arr, int size)
{
    Comparable<T> *aux = new T[size];
    sort(arr, aux, 0, size - 1);
    delete[] aux;
}
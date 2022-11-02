#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

template <typename T>
class Heapsort
{
private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);
    static void sink(Comparable<T> *, int, int);
    static void heap_order(Comparable<T> *, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
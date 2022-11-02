#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __MERGESORT_H__
#define __MERGESORT_H__

template <typename T>
class Mergesort
{
    const static int CUTOFF = 10;

private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);
    static void merge(Comparable<T> *, Comparable<T> *, int, int, int);
    static void sort(Comparable<T> *, Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
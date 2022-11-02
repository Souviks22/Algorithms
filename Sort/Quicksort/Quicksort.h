#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

template <typename T>
class Quicksort
{
    const static int CUTOFF = 10;

private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);
    static void shuffle(Comparable<T> *, int);
    static int median_of_3(Comparable<T> *, int, int, int);
    static int ninther(Comparable<T> *, int);
    static int partition(Comparable<T> *, int, int);
    static void sort(Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
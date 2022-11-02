#include <iostream>
#include "../../Compare/Comparable.h"s

#ifndef __QUICKSELECT_H__
#define __QUICKSELECT_H__

// k-th smalllest/largest element selection
template <typename T>
class Quickselect
{
    const static int CUTOFF = 10;

private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);
    static int partition(Comparable<T> *, int, int);

public:
    static const T &smallest(Comparable<T> *, int, int);
    static const T &largest(Comparable<T> *, int, int);
};

#endif
#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __THREEWAYQUICKSORT_H__
#define __THREEWAYQUICKSORT_H__

template <typename T>
class ThreeWayQuicksort
{
    const static int CUTOFF = 10;

private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);
    static void shuffle(Comparable<T> *, int);
    static std::pair<int, int> partition(Comparable<T> *, int, int);
    static void sort(Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
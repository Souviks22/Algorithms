#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

template <typename T>
class Shellsort
{
private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
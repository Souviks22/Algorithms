#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __SELECTION_H__
#define __SELECTION_H__

template <typename T>
class Selection
{
private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
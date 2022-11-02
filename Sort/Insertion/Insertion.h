#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __INSERTION_H__
#define __INSERTION_H__

template <typename T>
class Insertion
{
private:
    static bool less(Comparable<T> *, int, int);
    static void exchange(Comparable<T> *, int, int);

public:
    static void sort(Comparable<T> *, int);
};

#endif
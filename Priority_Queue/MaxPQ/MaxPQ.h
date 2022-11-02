#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __MAXPQ_H__
#define __MAXPQ_H__

template <class T>
class MaxPQ
{
    Comparable<T> *arr;
    int capacity;
    int size;

private:
    bool less(int, int);
    void exchange(int, int);
    void resize(double);
    void swim(int);
    void sink(int);

public:
    MaxPQ();
    void insert(const Comparable<T> &);
    T discard();
};

#endif
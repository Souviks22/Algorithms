#include <iostream>
#include "../../Compare/Comparable.h"

#ifndef __MINPQ_H__
#define __MINPQ_H__

template <class T>
class MinPQ
{
    Comparable<T> *arr;
    int capacity;
    int size;

private:
    bool greater(int, int);
    void exchange(int, int);
    void resize(double);
    void swim(int);
    void sink(int);

public:
    MinPQ();
    void insert(const Comparable<T> &);
    T discard();
};

#endif
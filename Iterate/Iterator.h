#include <iostream>

#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class Iterator
{
public:
    virtual bool operator!=(Iterator<T> *) = 0;
    virtual Iterator<T> *operator++() = 0;
    virtual const T &operator*() = 0;
};

#endif
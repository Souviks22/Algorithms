#include <iostream>
#include "Iterator.h"

#ifndef __ITERABLE_H__
#define __ITERABLE_H__

template <typename T>
class Iterable
{
public:
    virtual Iterator<T> *begin() = 0;
    virtual Iterator<T> *end() = 0;
};

#endif
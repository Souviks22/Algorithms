#include <iostream>

#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class Iterator
{
public:
    virtual operator T() = 0;
};

#endif
#include <iostream>

#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

template <typename T>
class Comparator
{
public:
    virtual static int compare(const T &, const T &) = 0;
};

#endif
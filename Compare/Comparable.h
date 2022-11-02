#include <iostream>

#ifndef __COMPARABLE_H__
#define __COMPARABLE_H__

template <typename T>
class Comparable
{
public:
    virtual int compare_to(const T &) = 0;
};

#endif
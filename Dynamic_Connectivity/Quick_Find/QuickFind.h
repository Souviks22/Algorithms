#include <iostream>
#include "../Person/Person.h"

#ifndef __QUICKFIND_H__
#define __QUICKFIND_H__

class QuickFind
{
private:
    int *arr;
    int size;

public:
    QuickFind(int);
    void connect(Person &, Person &);
    bool is_connected(Person &, Person &);
};

#endif
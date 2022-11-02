#include <iostream>
#include "../Person/Person.h"

#ifndef __QUICKUNION_H__
#define __QUICKUNION_H__

class QuickUnion
{
private:
    int *arr;
    int *connection;
    int size;
    int root(Person &);
    int comunity(Person &);

public:
    QuickUnion(int);
    void connect(Person &, Person &);
    bool is_connected(Person &, Person &);
};

#endif
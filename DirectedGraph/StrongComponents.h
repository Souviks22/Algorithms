#include <iostream>
#include "Digraph.h"

#ifndef __STRONGCOMPONENTS_H__
#define __STRONGCOMPONENTS_H__

class StrongComponents
{
private:
    bool *marked;
    int **sc;
    int count;
    void dfs(const Digraph &, int);

public:
    StrongComponents(const Digraph &);
    int id(int);
    int components();
};

#endif
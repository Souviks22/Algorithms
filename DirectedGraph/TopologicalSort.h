#include <iostream>
#include "Digraph.h"
#include "../Stack/Stack.h"

#ifndef __TOPOLOGICALSORT_H__
#define __TOPOLOGICALSORT_H__

class TopologicalSort
{
private:
    bool *marked;
    Stack<int> *reversePostOrder;
    void dfs(const Digraph &, int);

public:
    TopologicalSort(const Digraph &);
    Stack<int> *rpo();
};

#endif
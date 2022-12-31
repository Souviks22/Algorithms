#include <iostream>
#include "../Stack/Stack.h"

#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__

class Digraph
{
private:
    int vertices;
    int edges;
    Stack<int> *adj;

public:
    Digraph(int);
    int V() const;
    int E() const;
    void addEdge(int, int);
    Stack<int> &adjacent(int) const;
    int outDegree(int);
    Digraph *reverse() const;
};

#endif
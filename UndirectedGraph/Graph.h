#include <iostream>
#include "../Stack/Stack.h"

#ifndef __GRAPH_H__
#define __GRAPH_H__

class Graph
{
private:
    int vertices;
    int edges;
    Stack<int> *adj;

public:
    Graph(int);
    int V() const;
    int E() const;
    void addEdge(int, int);
    Stack<int> &adjacent(int) const;
    int degree(int);
};

#endif
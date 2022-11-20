#include <iostream>
#include "../Stack/Stack.h"

#ifndef __GRAPH_H__
#define __GRAPH_H__

class Graph
{
private:
    const int vertices;
    Stack<int> *adj;

public:
    Graph(const int);
    const int get_vertices();
    void add_edge(int, int);
    Stack<int> &edges(int);
};

#endif
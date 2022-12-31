#include <iostream>
#include "Graph.h"
#include "../Stack/Stack.h"

#ifndef __DEPTHFIRSTSEARCH_H__
#define __DEPTHFIRSTSEARCH_H__

class DepthFirstSearch
{
private:
    int s;
    bool *marked;
    int **edgeTo;
    void dfs(const Graph &, int);

public:
    DepthFirstSearch(const Graph &, int);
    bool hasPathTo(int);
    Stack<int> *pathTo(int);
};

#endif
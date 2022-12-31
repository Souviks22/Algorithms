#include <iostream>
#include "./Graph.h"
#include "../Stack/Stack.h"

#ifndef __BREADTHFIRSTSEARCH_H__
#define __BREADTHFIRSTSEARCH_H__

class BreadthFirstSearch
{
private:
    int s;
    bool *marked;
    int **edgeTo;
    void bfs(const Graph &, int);

public:
    BreadthFirstSearch(const Graph &, int);
    bool hasPathTo(int);
    Stack<int> *pathTo(int);
};

#endif
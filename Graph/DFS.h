#include <iostream>
#include "Graph.h"
#include "../Stack/Stack.h"

#ifndef __DFS_H__
#define __DFS_H__

class DFS
{
private:
    Graph graph;
    const int vertex;
    bool *marked;
    int *edge_to;
    void dfs(int);

public:
    DFS(Graph, const int);
    bool has_path_to(int);
    Stack<int> path_to(int);
};

#endif
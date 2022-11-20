#include <iostream>
#include "Graph.h"
#include "../Stack/Stack.h"

#ifndef __BFS_H__
#define __BFS_H__

class BFS
{
private:
    Graph graph;
    const int vertex;
    bool *marked;
    int *edge_to;
    void bfs(int);

public:
    BFS(Graph, const int);
    bool has_path_to(int);
    Stack<int> path_to(int);
};

#endif
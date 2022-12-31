#include <iostream>
#include "./Graph.h"

#ifndef __CONNECTEDCOMPONENTS_H__
#define __CONNECTEDCOMPONENTS_H__

class ConnectedComponents
{
private:
    bool *marked;
    int **cc;
    int count;
    void dfs(const Graph &, int);

public:
    ConnectedComponents(const Graph &);
    int id(int);
    int components();
};

#endif
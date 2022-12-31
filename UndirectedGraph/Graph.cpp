#include "Graph.h"
using namespace std;

Graph::Graph(int v) : vertices{v}, edges{}
{
    adj = new Stack<int>[v];
}

int Graph::V() const
{
    return vertices;
}

int Graph::E() const
{
    return edges;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push(w);
    adj[w].push(v);
    edges++;
}

Stack<int> &Graph::adjacent(int v) const
{
    return adj[v];
}

int Graph::degree(int v)
{
    return adj[v].get_size();
}
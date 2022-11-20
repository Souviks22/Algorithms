#include "Graph.h"
using namespace std;

Graph::Graph(const int v) : vertices{v}
{
    adj = new Stack<int>[v] {};
}

const int Graph::get_vertices()
{
    return vertices;
}

void Graph::add_edge(int v, int w)
{
    if (v >= vertices || w >= vertices)
    {
        return;
    }
    adj[v].push(w);
    adj[w].push(v);
}

Stack<int> &Graph::edges(int v)
{
    return adj[v];
}

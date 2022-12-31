#include "Digraph.h"
using namespace std;

Digraph::Digraph(int v) : vertices{v}, edges{}
{
    adj = new Stack<int>[v];
}

int Digraph::V() const
{
    return vertices;
}

int Digraph::E() const
{
    return edges;
}

void Digraph::addEdge(int v, int w)
{
    adj[v].push(w);
    edges++;
}

Stack<int> &Digraph::adjacent(int v) const
{
    return adj[v];
}

int Digraph::outDegree(int v)
{
    return adj[v].get_size();
}

Digraph *Digraph::reverse() const
{
    Digraph *rev = new Digraph(vertices);
    for (int i{}; i < vertices; i++)
    {
        for (int v : adj[i])
        {
            rev->addEdge(v, i);
        }
    }
    return rev;
}
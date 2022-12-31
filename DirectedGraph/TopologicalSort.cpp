#include "TopologicalSort.h"
using namespace std;

TopologicalSort::TopologicalSort(const Digraph &g)
{
    marked = new bool[g.V()];
    reversePostOrder = new Stack<int>();
    for (int i{}; i < g.V(); i++)
    {
        marked[i] = false;
    }
    for (int i{}; i < g.V(); i++)
    {
        if (!marked[i])
        {
            dfs(g, i);
        }
    }
}

void TopologicalSort::dfs(const Digraph &g, int v)
{
    marked[v] = true;
    for (int w : g.adjacent(v))
    {
        if (!marked[v])
        {
            dfs(g, w);
        }
    }
    reversePostOrder->push(v);
}

Stack<int> *TopologicalSort::rpo()
{
    return reversePostOrder;
}

#include "DepthFirstSearch.h"
using namespace std;

DepthFirstSearch::DepthFirstSearch(const Graph &g, int v) : s{v}
{
    marked = new bool[g.V()];
    edgeTo = new int *[g.V()];
    for (int i{}; i < g.V(); i++)
    {
        marked[i] = false;
        edgeTo[i] = nullptr;
    }
    dfs(g, v);
}

void DepthFirstSearch::dfs(const Graph &g, int v)
{
    marked[v] = true;
    for (int w : g.adjacent(v))
    {
        if (!marked[w])
        {
            dfs(g, w);
            edgeTo[w] = new int{v};
        }
    }
}

bool DepthFirstSearch::hasPathTo(int v)
{
    return marked[v];
}

Stack<int> *DepthFirstSearch::pathTo(int v)
{
    if (!hasPathTo(v))
    {
        return nullptr;
    }
    Stack<int> *path = new Stack<int>();
    for (int i{v}; i != s; i = *(edgeTo[i]))
    {
        path->push(i);
    }
    path->push(s);
    return path;
}
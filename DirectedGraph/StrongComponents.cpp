#include "StrongComponents.h"
#include "TopologicalSort.h"
using namespace std;

StrongComponents::StrongComponents(const Digraph &g) : count{}
{
    marked = new bool[g.V()];
    sc = new int *[g.V()];
    for (int i{}; i < g.V(); i++)
    {
        marked[i] = false;
        sc[i] = nullptr;
    }
    TopologicalSort *ts = new TopologicalSort(*g.reverse());
    while (!ts->rpo()->is_empty())
    {
        int v = ts->rpo()->pop();
        if (!marked[v])
        {
            dfs(g, v);
            count++;
        }
    }
}

void StrongComponents::dfs(const Digraph &g, int v)
{
    marked[v] = true;
    for (int w : g.adjacent(v))
    {
        if (!marked[w])
        {
            dfs(g, w);
            sc[w] = new int{count};
        }
    }
}

int StrongComponents::id(int v)
{
    return *(sc[v]);
}

int StrongComponents::components()
{
    return count;
}
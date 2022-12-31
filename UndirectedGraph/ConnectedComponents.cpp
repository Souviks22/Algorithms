#include "ConnectedComponents.h"
using namespace std;

ConnectedComponents::ConnectedComponents(const Graph &g) : count{}
{
    marked = new bool[g.V()];
    cc = new int *[g.V()];
    for (int i{}; i < g.V(); i++)
    {
        marked[i] = false;
        cc[i] = nullptr;
    }
    for (int i{}; i < g.V(); i++)
    {
        if (!marked[i])
        {
            dfs(g, i);
            count++;
        }
    }
}

void ConnectedComponents::dfs(const Graph &g, int v)
{
    marked[v] = true;
    for (int w : g.adjacent(v))
    {
        if (!marked[w])
        {
            dfs(g, w);
            cc[w] = new int{count};
        }
    }
}

int ConnectedComponents::id(int v)
{
    return *(cc[v]);
}

int ConnectedComponents::components()
{
    return count;
}
#include "DFS.h"
using namespace std;

DFS::DFS(Graph g, const int v) : graph{g}, vertex{v}
{
    if (v >= graph.get_vertices())
    {
        throw NULL;
    }
    marked = new bool[v]{};
    edge_to = new int[v]{};
    dfs(v);
}

void DFS::dfs(int v)
{
    marked[v] = true;
    for (int w : graph.edges(v))
    {
        if (!marked[w])
        {
            dfs(w);
            edge_to[w] = v;
        }
    }
}

bool DFS::has_path_to(int w)
{
    if (w >= graph.get_vertices())
    {
        return false;
    }
    return marked[w];
}

Stack<int> DFS::path_to(int w)
{
    if (!has_path_to(w))
    {
        throw NULL;
    }
    Stack<int> path{};
    for (int i{w}; i != vertex; i = edge_to[i])
    {
        path.push(i);
    }
    path.push(vertex);
    return path;
}
#include "BFS.h"
#include "../Queue/Queue.h"
using namespace std;

BFS::BFS(Graph g, const int v) : graph{g}, vertex{v}
{
    if (v >= graph.get_vertices())
    {
        throw NULL;
    }
    marked = new bool[v]{};
    edge_to = new int[v]{};
    bfs(v);
}

void BFS::bfs(int v)
{
    Queue<int> q{};
    q.enqueue(v);
    marked[v] = true;
    while (!q.is_empty())
    {
        int s = q.dequeue();
        for (int w : graph.edges(s))
        {
            if (!marked[w])
            {
                marked[w] = true;
                edge_to[w] = s;
                q.enqueue(w);
            }
        }
    }
}

bool BFS::has_path_to(int w)
{
    if (w >= graph.get_vertices())
    {
        return false;
    }
    return marked[w];
}

Stack<int> BFS::path_to(int w)
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
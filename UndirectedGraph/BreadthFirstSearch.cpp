#include "BreadthFirstSearch.h"
#include "../Queue/Queue.h"
using namespace std;

BreadthFirstSearch::BreadthFirstSearch(const Graph &g, int v) : s{v}
{
    marked = new bool[g.V()];
    edgeTo = new int *[g.V()];
    for (int i{}; i < g.V(); i++)
    {
        marked[i] = false;
        edgeTo[i] = nullptr;
    }
    bfs(g, v);
}

void BreadthFirstSearch::bfs(const Graph &g, int v)
{
    Queue<int> q;
    marked[v] = true;
    q.enqueue(v);
    while (!q.is_empty())
    {
        int p = q.dequeue();
        for (int w : g.adjacent(p))
        {
            if (!marked[w])
            {
                marked[w] = true;
                q.enqueue(w);
                edgeTo[w] = new int{v};
            }
        }
    }
}

bool BreadthFirstSearch::hasPathTo(int v)
{
    return marked[v];
}

Stack<int> *BreadthFirstSearch::pathTo(int v)
{
    if (!hasPathTo(v))
    {
        return nullptr;
    }
    Stack<int> *path = new Stack<int>();
    for (int i{v}; i != s; i = *edgeTo[i])
    {
        path->push(i);
    }
    path->push(s);
    return path;
}
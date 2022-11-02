#include "QuickUnion.h"
using namespace std;

QuickUnion::QuickUnion(int sz) : size{sz}
{
    arr = new int[size];
    for (int i{}; i < size; i++)
    {
        arr[i] = i;
        connection[i] = 1;
    }
}

int QuickUnion::root(Person &obj)
{
    int index = obj.get_index();
    while (arr[index] != index)
    {
        arr[index] = arr[arr[index]];
        index = arr[index];
    }
    return index;
}
int QuickUnion::comunity(Person &obj)
{
    return connection[root(obj)];
}
void QuickUnion::connect(Person &obj1, Person &obj2)
{
    int a = root(obj1), b = root(obj2);
    if (comunity(obj1) > comunity(obj2))
    {
        arr[b] = a;
        connection[a] += connection[b];
    }
    else
    {
        arr[a] = b;
        connection[b] += connection[a];
    }
}
bool QuickUnion::is_connected(Person &obj1, Person &obj2)
{
    return root(obj1) == root(obj2);
}

#include "QuickFind.h"
using namespace std;

QuickFind::QuickFind(int sz) : size{sz}
{
    arr = new int[size];
    for (int i{}; i < size; i++)
    {
        arr[i] = i;
    }
}

void QuickFind::connect(Person &obj1, Person &obj2)
{
    for (int i{}; i < size; i++)
    {
        if (arr[i] == arr[obj1.get_index()])
        {
            arr[i] = arr[obj2.get_index()];
        }
    }
}

bool QuickFind::is_connected(Person &obj1, Person &obj2)
{
    return arr[obj1.get_index()] == arr[obj2.get_index()];
}
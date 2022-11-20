#include "Node.h"
using namespace std;

template <typename Key, typename Value>
Node<Key, Value>::Node(Key k, Value v) : left{nullptr}, right{nullptr}
{
    key = new Key{k};
    value = v;
    color = RED;
}
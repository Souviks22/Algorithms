#include "Node.h"
using namespace std;

template <typename Key, typename Value>
Node<Key, Value>::Node(Key k, Value v) : left{nullptr}, right{nullptr}, size{1}
{
    key = new Key{k};
    value = v;
}
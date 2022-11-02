#include <iostream>
#include "../Compare/Comparable.h"

#ifndef __NODE_H__
#define __NODE_H__

template <typename Key, typename Value>
class Node
{
public:
    Comparable<Key> *key;
    Value value;
    Node *left, *right;
    int size;
    Node(Key, Value);
};

#endif
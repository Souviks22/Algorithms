#include <iostream>
#include "../Compare/Comparable.h"

#ifndef __NODE_H__
#define __NODE_H__

template <typename Key, typename Value>
class Node
{
public:
    static const bool RED = true;
    static const bool BLACK = false;

    Comparable<Key> *key;
    Value value;
    Node *left, *right;
    bool color;
    Node(Key, Value);
};

#endif
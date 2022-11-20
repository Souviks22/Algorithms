#include "Node.h"

#ifndef __REDBLACKBST_H__
#define __REDBLACKBST_H__

template <typename Key, typename Value>
class RedBlackBST
{
private:
    static const bool RED = true;
    static const bool BLACK = false;
    Node<Key, Value> *root;
    Node<Key, Value> *rotate_left(Node<Key, Value> *);
    Node<Key, Value> *rotate_right(Node<Key, Value> *);
    void flip_colour(Node<Key, Value> *);
    Node<Key, Value> *put(Node<Key, Value> *, const Key &, const Value &);

public:
    RedBlackBST();
    bool is_empty();
    const Value &get(const Key &);
    void put(const Key &, const Value &);
};

#endif
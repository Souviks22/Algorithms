#include "Node.h"
#include "../Queue/Queue.h"

#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

template <typename Key, typename Value>
class SymbolTable
{
    Node<Key, Value> *root;

private:
    Node<Key, Value> *put(Node<Key, Value> *, const Key &, const Value &);
    Node<Key, Value> *extreme(Node<Key, Value> *, bool);
    Node<Key, Value> *floor(Node<Key, Value> *, const Key &);
    Node<Key, Value> *ceil(Node<Key, Value> *, const Key &);
    int size(Node<Key, Value> *);
    int rank(Node<Key, Value> *, const Key &);
    Node<Key, Value> *cut(Node<Key, Value> *, const Key &);
    Node<Key, Value> *detach_min(Node<Key, Value> *);
    void inorder(Node<Key, Value> *, Queue<Key> &);

public:
    SymbolTable();
    bool is_empty();
    const Value &get(const Key &);
    void put(const Key &, const Value &);
    const Key &min();
    const Key &max();
    const Key &floor(const Key &);
    const Key &ceil(const Key &);
    int size();
    int rank(const Key &);
    void cut(const Key &);
    Queue<Key> keys();
};

#endif
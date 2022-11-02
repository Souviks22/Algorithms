#include "SymbolTable.h"
using namespace std;

/****************************************************************************************
 *
 * Binary Search Tree Implementation of Symbol Table
 * nodes at the left are smaller and nodes at the right are greater than the root node
 *
 ****************************************************************************************/

template <typename Key, typename Value>
SymbolTable<Key, Value>::SymbolTable() : root{nullptr} {}

template <typename Key, typename Value>
bool SymbolTable<Key, Value>::is_empty()
{
    return root == nullptr;
}

template <typename Key, typename Value>
const Value &SymbolTable<Key, Value>::get(const Key &key)
{
    if (is_empty())
    {
        throw NULL;
    }
    Node<Key, Value> *temp{root};
    while (temp)
    {
        int cmp = temp->key->compare_to(key);
        if (cmp > 0)
        {
            temp = temp->left;
        }
        else if (cmp < 0)
        {
            temp = temp->right;
        }
        else
        {
            return temp->value;
        }
    }
    return NULL;
}

template <typename Key, typename Value>
void SymbolTable<Key, Value>::put(const Key &key, const Value &value)
{
    root = put(root, key, value);
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::put(Node<Key, Value> *x, const Key &key, const Value &value)
{
    if (!x)
    {
        return new Node<Key, Value>(key, value);
    }
    int cmp = x->key->compare_to(key);
    if (cmp > 0)
    {
        x->left = put(x->left, key, value);
    }
    else if (cmp < 0)
    {
        x->right = put(x->right, key, value);
    }
    else
    {
        x->value = value;
    }
    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
const Key &SymbolTable<Key, Value>::min()
{
    return extreme(root, true)->key;
}

template <typename Key, typename Value>
const Key &SymbolTable<Key, Value>::max()
{
    return extreme(root, false)->key;
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::extreme(Node<Key, Value> *x, bool need_min)
{
    if (is_empty())
    {
        throw NULL;
    }
    Node<Key, Value> *temp{x};
    if (need_min)
    {
        while (temp->left)
        {
            temp = temp->left;
        }
    }
    else
    {
        while (temp->right)
        {
            temp = temp->right;
        }
    }
    return temp;
}

template <typename Key, typename Value>
const Key &SymbolTable<Key, Value>::floor(const Key &key)
{
    Node<Key, Value> *floor_node = floor(root, key);
    if (!floor_node)
    {
        return NULL;
    }
    return *(floor_node->key);
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::floor(Node<Key, Value> *x, const Key &key)
{
    if (!x)
    {
        return nullptr;
    }
    int cmp = x->key->compare_to(key);
    if (cmp == 0)
    {
        return x;
    }
    if (cmp > 0)
    {
        return floor(x->left, key);
    }
    Node<Key, Value> *f = floor(x->right, key);
    if (f)
    {
        return f;
    }
    return x;
}

template <typename Key, typename Value>
const Key &SymbolTable<Key, Value>::ceil(const Key &key)
{
    Node<Key, Value> *ceil_node = ceil(root, key);
    if (!ceil_node)
    {
        return NULL;
    }
    return *(ceil_node->key);
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::ceil(Node<Key, Value> *x, const Key &key)
{
    if (!x)
    {
        return nullptr;
    }
    int cmp = x->key->compare_to(key);
    if (cmp == 0)
    {
        return x;
    }
    if (cmp < 0)
    {
        return ceil(x->right, key);
    }
    Node<Key, Value> *c = ceil(x->left, key);
    if (c)
    {
        return c;
    }
    return x;
}

template <typename Key, typename Value>
int SymbolTable<Key, Value>::size()
{
    return size(root);
}

template <typename Key, typename Value>
int SymbolTable<Key, Value>::size(Node<Key, Value> *x)
{
    if (!x)
    {
        return 0;
    }
    return x->size;
}

template <typename Key, typename Value>
int SymbolTable<Key, Value>::rank(const Key &key)
{
    return rank(root, key);
}

template <typename Key, typename Value>
int SymbolTable<Key, Value>::rank(Node<Key, Value> *x, const Key &key)
{
    if (!x)
    {
        return 0;
    }
    int cmp = x->key->compare_to(key);
    if (cmp > 0)
    {
        return rank(x->left, key);
    }
    if (cmp < 0)
    {
        return 1 + size(x->left) + size(x->right);
    }
    return size(x->left);
}

template <typename Key, typename Value>
void SymbolTable<Key, Value>::cut(const Key &key)
{
    if (is_empty())
    {
        throw NULL;
    }
    root = cut(root, key);
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::cut(Node<Key, Value> *x, const Key &key)
{
    if (!x)
    {
        return nullptr;
    }
    int cmp = x->key->compare_to(key);
    if (cmp > 0)
    {
        x->left = cut(x->left, key);
    }
    else if (cmp < 0)
    {
        x->right = cut(x->right, key);
    }
    else
    {
        if (!x->left)
        {
            return x->right;
        }
        if (!x->right)
        {
            return x->left;
        }
        // Highly compact and concise Hibbard Deletion
        Node<Key, Value> *n = x;
        x = extreme(n->right, true);
        x->right = detach_min(n->right);
        x->left = n->left;
        delete n;
    }
    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
Node<Key, Value> *SymbolTable<Key, Value>::detach_min(Node<Key, Value> *x)
{
    if (!x->left)
    {
        return x->right;
    }
    x->left = detach_min(x->left);
    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
Queue<Key> SymbolTable<Key, Value>::keys()
{
    Queue<Key> q{};
    inorder(root, q);
    return q;
}

template <typename Key, typename Value>
void SymbolTable<Key, Value>::inorder(Node<Key, Value> *x, Queue<Key> &q)
{
    if (!x)
    {
        return;
    }
    inorder(x->left, q);
    q.push(x->key);
    inorder(x->right, q);
}
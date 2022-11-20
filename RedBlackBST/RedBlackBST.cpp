#include "RedBlackBST.h"
using namespace std;

template <typename Key, typename Value>
RedBlackBST<Key, Value>::RedBlackBST() : root{nullptr} {}

template <typename Key, typename Value>
bool RedBlackBST<Key, Value>::is_empty()
{
    return root == nullptr;
}

template <typename Key, typename Value>
Node<Key, Value> *RedBlackBST<Key, Value>::rotate_left(Node<Key, Value> *x)
{
    Node<Key, Value> *h = x->right;
    x->right = h->left;
    h->left = x;
    h->color = x->color;
    x->color = RED;
    return h;
}

template <typename Key, typename Value>
Node<Key, Value> *RedBlackBST<Key, Value>::rotate_right(Node<Key, Value> *x)
{
    Node<Key, Value> *h = x.left;
    x->left = h->right;
    h->right = x;
    h->color = x->color;
    x->color = RED;
    return h;
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::flip_colour(Node<Key, Value> *x)
{
    x->color = RED;
    x->left->color = BLACK;
    x->right->color = BLACK;
}

template <typename Key, typename Value>
const Value &RedBlackBST<Key, Value>::get(const Key &key)
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
void RedBlackBST<Key, Value>::put(const Key &key, const Value &value)
{
    root = put(root, key, value);
}

template <typename Key, typename Value>
Node<Key, Value> *RedBlackBST<Key, Value>::put(Node<Key, Value> *x, const Key &key, const Value &value)
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

    if (x->right->color == RED)
    {
        x = rotate_left(x);
    }
    if (x->left->color == RED && x->left->left->color == RED)
    {
        x = rotate_right(x);
    }
    if (x->left->color == RED && x->right->color == RED)
    {
        flip_colour(x);
    }

    return x;
}
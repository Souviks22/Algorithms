#include <iostream>
#include "../Iterate/Iterator.h"

#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node : public Iterator<T>
{
private:
    T data;
    Node *next;

public:
    Node(T);
    const T &get_data();
    Node<T> *get_next();
    void set_next(Node<T> *);
    virtual bool operator!=(const Iterator<T> *) override;
    virtual const Iterator<T> *operator++() override;
    virtual const T &operator*() override;
};

#endif
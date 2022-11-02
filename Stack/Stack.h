#include <iostream>
#include "Node.h"
#include "../Iterate/Iterable.h"

#ifndef __STACK_H__
#define __STACK_H__

template <typename T>
class Stack : public Iterable<T>
{
private:
    Node<T> *top;
    int size;

public:
    Stack();
    bool is_empty();
    const T &get_top();
    int get_size();
    void push(T);
    T pop();
    virtual Iterator<T> *begin() override;
    virtual Iterator<T> *end() override;
};

#endif
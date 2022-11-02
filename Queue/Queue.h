#include <iostream>
#include "Node.h"
#include "../Iterate/Iterable.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

template <typename T>
class Queue : public Iterable<T>
{
private:
    Node<T> *front;
    Node<T> *back;
    int size;

public:
    Queue();
    bool is_empty();
    int get_size();
    void push(T);
    T pop();
    virtual Iterator<T> *begin() override;
    virtual Iterator<T> *end() override;
};

#endif
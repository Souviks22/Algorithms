#include <iostream>
#include "Node.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue
{
public:
    Node *head, *tail;
    size_t size;
    Queue(int value = 0);
    void enqueue(int);
    void dequeue();
    void print();
};

#endif
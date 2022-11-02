#include <iostream>
#include "Node.h"

#ifndef __STACK_H__
#define __STACK_H__

class Stack
{
public:
    Node *head;
    size_t size;
    Stack(int value = 0);
    void push(int);
    void pop();
    int top();
    void print();
};

#endif
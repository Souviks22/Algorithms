#include <iostream>
#include "Node.h"
using namespace std;

#ifndef __LIST_H__
#define __LIST_H__

class List
{
public:
    Node *head;
    size_t size;
    List(int value = 0);
    void push_front(int);
    void push_back(int);
    void push(int, size_t);
    void pop(size_t);
    size_t find(int);
    List reverse();
    void print();
    void print_reverse();
    void clear();
    List sort();
};

#endif
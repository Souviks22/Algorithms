#include <iostream>

#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
    int data;
    Node *next;
    Node(int value = 0) : data{value}, next{nullptr} {}
};

#endif
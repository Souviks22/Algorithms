#include <iostream>

#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
    int coeff;
    int power;
    bool isPicked;
    Node *next;
    Node(int c_value, int p_value) : coeff{c_value}, power{p_value}, isPicked{false}, next{nullptr} {}
};

#endif
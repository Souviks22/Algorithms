#include <iostream>
#include "Node.h"

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

class Polynomial
{
public:
    Node *init;
    Polynomial(std::string);
    void print();
    Polynomial add(const Polynomial &);
    Polynomial multiply(const Polynomial &);
};

#endif
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
    string p1{}, p2{};
    cout << ">> Enter Two Polynomials on each line -" << endl;
    cout << "> ";
    getline(cin, p1);
    cout << "> ";
    getline(cin, p2);

    Polynomial pol1{p1}, pol2{p2};
    Polynomial add = pol1.add(pol2), mult = pol1.multiply(pol2);
    cout << ">> Addition - ";
    add.print();
    cout << endl;
    cout << ">> Multiplication - ";
    mult.print();
    cout << endl;

    return 0;
}
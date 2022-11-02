#include "Polynomial.h"
#include <string>
#include <sstream>
using namespace std;

Polynomial::Polynomial(string expr) : init{nullptr}
{
    stringstream ss1{expr};
    string str{};
    int coeff{}, power{};
    bool negetion{false};
    while (ss1 >> str)
    {
        if (str == "+")
        {
            continue;
        }
        else if (str == "-")
        {
            negetion = true;
        }
        else
        {
            stringstream ss2{str};
            ss2 >> coeff;
            if (negetion)
            {
                coeff *= -1;
                negetion = false;
            }
            char c{};
            ss2 >> c >> c; // for x and ^
            ss2 >> power;
            if (!init)
            {
                init = new Node(coeff, power);
            }
            else
            {
                Node *temp{init};
                while (temp->next)
                {
                    temp = temp->next;
                }
                temp->next = new Node(coeff, power);
            }
        }
    }
}

void Polynomial::print()
{
    Node *temp{init};
    while (temp)
    {
        if (temp->coeff < 0)
        {
            cout << " - ";
        }
        else if (temp != init)
        {
            cout << " + ";
        }
        cout << temp->coeff << "x^" << temp->power;
        temp = temp->next;
    }
}

Polynomial Polynomial::add(const Polynomial &pol)
{
    string expr{};
    Node *temp1{init};
    while (temp1)
    {
        bool is1Picked{false};
        Node *temp2{pol.init};
        while (temp2)
        {
            if (temp1->power == temp2->power)
            {
                expr += to_string(temp1->coeff + temp2->coeff) + "x^" + to_string(temp1->power) + " ";
                is1Picked = true;
                temp2->isPicked = true;
                break;
            }
            temp2 = temp2->next;
        }
        if (!is1Picked)
        {
            expr += to_string(temp1->coeff) + "x^" + to_string(temp1->power) + " ";
        }
        temp1 = temp1->next;
    }
    Node *temp2{pol.init};
    while (temp2)
    {
        if (!temp2->isPicked)
        {
            expr += to_string(temp2->coeff) + "x^" + to_string(temp2->power) + " ";
            temp2->isPicked = false;
        }
        temp2 = temp2->next;
    }
    return Polynomial{expr};
}

Polynomial Polynomial::multiply(const Polynomial &pol)
{
    Polynomial mult{""};
    Node *temp1{init};
    while (temp1)
    {
        Node *temp2{pol.init};
        string expr{};
        while (temp2)
        {
            expr += to_string(temp1->coeff * temp2->coeff) + "x^" + to_string(temp1->power + temp2->power) + " ";
            temp2 = temp2->next;
        }
        mult = mult.add(Polynomial{expr});
    }
    return mult;
}
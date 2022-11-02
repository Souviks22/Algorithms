#include <iostream>
using namespace std;

#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
    static int people;
    int index;
    string first_name;
    string last_name;
    int age;

public:
    Person(string, int);
    Person(string, string, int);
    int get_index();
    string get_name();
    int get_age();
};

#endif
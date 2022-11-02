#include "Person.h"
#include <string>
#include <sstream>
using namespace std;

int Person::people = 0;

Person::Person(string full_name, int age) : age{age}
{
    string name{};
    stringstream ss{full_name};
    ss >> name;
    first_name = name;
    ss >> name;
    last_name = name;
    index = ++people;
}

Person::Person(string f_name, string l_name, int age) : first_name{f_name}, last_name(l_name), age{age}
{
    index = ++people;
}

int Person::get_index() { return index; }

string Person::get_name() { return first_name + last_name; }

int Person::get_age() { return age; }

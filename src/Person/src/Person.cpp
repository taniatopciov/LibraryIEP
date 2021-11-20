#include "Person.hpp"

// constructor with member initialization list
// deep copy for name
Person::Person(char *name, int age)
    : age(age)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    cout << "Person constructor" << endl;
}

Person::~Person()
{
    delete[] name;
    cout << "Person destructor" << endl;
}
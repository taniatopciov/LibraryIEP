#include "Person.hpp"

// constructor with member initialization list
// deep copy for name
Person::Person(char *name, int age)
    : age(age)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    cout << "Base class constructor was called" << endl;
}

Person::~Person()
{
    delete[] name;
    cout << "Base class destructor was called" << endl;
}
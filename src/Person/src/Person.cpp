#include "Person.hpp"

Person::Person(char *name, int age)
    : age(age)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::~Person()
{
    delete[] name;
}
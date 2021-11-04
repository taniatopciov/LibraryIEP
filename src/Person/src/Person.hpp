#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    char *name;
    int age;

    //allow construction and destruction of derived objects
    Person(char *name, int age);
    virtual ~Person();

private:
    //prevent copying
    Person(const Person &);
    Person &operator=(const Person &);
};

#endif // PERSON_H
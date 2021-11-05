#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include "Person.hpp"
using namespace std;

class Author : private Person
{
public:
    Author(char *name, int age, int numberOfWrittenBooks);
    void printPresentation();
    char *getAuthorName();

private:
    int numberOfWrittenBooks;

    Author(const Author &);
    Author &operator=(const Person &);
};

#endif // AUTHOR_H
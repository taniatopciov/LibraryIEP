#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <memory>

#include "Person.hpp"
#include "Encyclopedia.hpp"

using namespace std;

class Author : private Person
{
public:
    Author(char *name, int age, int numberOfWrittenBooks);
    void printPresentation();
    char *getAuthorName();
    void writeInCollaboration(Book *b);

private:
    int numberOfWrittenBooks;
    char *write();

    Author(const Author &);
    Author &operator=(const Person &);
};

#endif // AUTHOR_H
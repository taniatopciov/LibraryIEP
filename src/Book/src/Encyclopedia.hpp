#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include "Book.hpp"

#include <iostream>

using namespace std;

class Encyclopedia : public Book
{

public:
    Encyclopedia();
    Encyclopedia(int numberOfPages, char *title, char *references);

    //copy constructor
    Encyclopedia(const Encyclopedia &encyclopedia);

    ~Encyclopedia();

    //copy assignment operator
    Encyclopedia &operator=(const Encyclopedia &encyclopedia);

    void printDetails();
    char *getReferences();
    void setReferences(char *references);

protected:
    char *references;
};

#endif //ENCYCLOPEDIA_H
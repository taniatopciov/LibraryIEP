#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include "Book.hpp"

#include <iostream>

using namespace std;

class Encyclopedia : public Book
{

public:
    Encyclopedia();
    Encyclopedia(int numberOfPages, char *title, char *text);

    //copy constructor
    Encyclopedia(const Encyclopedia &encyclopedia);

    ~Encyclopedia();

    //copy assignment operator
    Encyclopedia &operator=(const Encyclopedia &encyclopedia);

    void printDetails();
    char *getText();
    void setText(char *text);

protected:
    char *text;
};

#endif //ENCYCLOPEDIA_H
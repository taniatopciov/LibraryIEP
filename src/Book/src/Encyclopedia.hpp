#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include "Book.hpp"

#include <iostream>

using namespace std;

#define MAX_AUTHORS 5

class Encyclopedia : public Book
{
public:
    Encyclopedia();
    Encyclopedia(int numberOfPages, char *title, int numberOfAuthors, Author *authors[MAX_AUTHORS], char *text);

    //copy constructor
    Encyclopedia(const Encyclopedia &encyclopedia);

    ~Encyclopedia();

    //copy assignment operator
    Encyclopedia &operator=(const Encyclopedia &encyclopedia);

    void printDetails();
    void writeInCollaboration(char *additionalText);

protected:
    Author *authors[5];
    int numberOfAuthors;
    char *text;
};

#endif //ENCYCLOPEDIA_H
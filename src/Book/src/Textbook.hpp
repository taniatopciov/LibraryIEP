#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Book.hpp"

#include <iostream>

using namespace std;

class Textbook : public Book
{

public:
    Textbook();
    Textbook(int numberOfPages, char *title, char *subject);

    ~Textbook();

    void printDetails();

protected:
    char *subject;
};

#endif //TEXTBOOK_H
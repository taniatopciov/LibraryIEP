#ifndef NOVEL_H
#define NOVEL_H

#include "Book.hpp"
#include "Author.hpp"

#include <iostream>

using namespace std;

class Novel : public Book
{
public:
    Novel();
    Novel(int numberOfPages, char *title, Author *author, char *literary_movement);

    //copy constructor
    Novel(const Novel &novel);

    ~Novel();

    //copy assignment operator
    Novel &operator=(const Novel &novel);

    void printDetails();

protected:
    Author *author;
    char *literary_movement;
};

#endif //NOVEL_H
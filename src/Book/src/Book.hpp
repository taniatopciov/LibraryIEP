#ifndef BOOK_H
#define BOOK_H

#include "../../Person/src/Author.hpp"

#include <iostream>

using namespace std;

class Book
{
public:
    Book();
    Book(int numberOfPages, char *title, char *genre, Author *author);

    //copy constructor
    Book(const Book &);

    ~Book();

    //copy assignment operator
    Book &operator=(const Book &);

    void printDetails();

private:
    int numberOfPages;
    char *title;
    char *genre;
    Author *author;
};

#endif //BOOK_H
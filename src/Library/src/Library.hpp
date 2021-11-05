#ifndef LIBRARY_H
#define LIBRARY_H

#include "../../Book/src/Book.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Library
{
public:
    void addBook(Book &book);
    void removeBook(char *title);
    void printBooks();

private:
    vector<Book> books;
};

#endif //LIBRARY_H
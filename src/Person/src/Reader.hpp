#ifndef READER_H
#define READER_H

#include <iostream>
#include "Person.hpp"
#include "../../Book/src/Book.hpp"
using namespace std;

class Reader : private Person
{
public:
    Reader(char *name, int age, Book *book);
    void printPresentation();
    char *getReaderName();
    void readBook();
    void readAnotherBook(Book *book);

private:
    Book *book;

    Reader(const Reader &);
    Reader &operator=(const Person &);
};

#endif // READER_H
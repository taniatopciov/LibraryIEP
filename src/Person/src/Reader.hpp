#ifndef READER_H
#define READER_H

#include <iostream>
#include <memory>

#include "Person.hpp"
#include "Book.hpp"

using namespace std;

class Reader : private Person
{
public:
    Reader(char *name, int age);

    void printPresentation();
    char *getReaderName();

    void readBookAndShare(Book *book, Reader *reader);
    void readBookAndTransfer(Book *book, Reader *reader);

private:
    Reader(const Reader &);
    Reader &operator=(const Person &);
};

#endif // READER_H
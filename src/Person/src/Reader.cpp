#include "Reader.hpp"

// constructor with member initialization list
Reader::Reader(char *name, int age, Book *book)
    : Person(name, age)
{
    cout << "Reader constructor" << endl;
}

void Reader::printPresentation()
{
    cout << "Hello! My name is " << this->name
         << ". I am " << this->age << " years old." << endl;
}

char *Reader::getReaderName()
{
    return this->name;
}

void Reader::readBook()
{
    cout << this->name << " is currently reading " << this->book->getTitle() << endl;
}

void Reader::readAnotherBook(Book *book)
{
    this->book = book;
}
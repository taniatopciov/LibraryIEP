#include "Author.hpp"

// constructor with member initialization list
Author::Author(char *name, int age, int numberOfWrittenBooks)
    : Person(name, age),
      numberOfWrittenBooks(numberOfWrittenBooks) {}

void Author::printPresentation()
{
    cout << "Hello! My name is " << this->name
         << ". I am " << this->age << " years old and I have written "
         << this->numberOfWrittenBooks << " books." << endl;
}

char *Author::getAuthorName()
{
    return this->name;
}
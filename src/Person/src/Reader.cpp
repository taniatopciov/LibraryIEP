#include "Reader.hpp"

// constructor with member initialization list
Reader::Reader(char *name, int age)
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

void Reader::readBookAndShare(Book *book, Reader *anotherReader)
{
    unique_ptr<Book> pBook(book);
    cout << this->name << " is currently reading " << pBook.get()->getTitle() << endl;

    // unique_ptr<Book> pBook2 = pBook;

    // anotherReader->readBook(pBook2.get());
}

void Reader::readBookAndTransfer(Book *book, Reader *anotherReader)
{
    unique_ptr<Book> pBook(book);
    cout << this->name << " is currently reading " << pBook.get()->getTitle() << endl;

    unique_ptr<Book> pBook2 = move(pBook);

    cout << this->name << " cannot read that book anymore because the book's address canged to " << pBook.get() << endl;

    cout << anotherReader->getReaderName() << " is currently reading " << pBook2.get()->getTitle() << endl;
}
#include "Book.hpp"

Book::Book()
    : numberOfPages(0)
{
    this->title = new char[strlen("") + 1];
    this->genre = new char[strlen("") + 1];

    strcpy(this->title, "");
    strcpy(this->genre, "");

    this->author = NULL;
}

Book::Book(int numberOfPages, char *title, char *genre, Author *author)
    : numberOfPages(numberOfPages)
{
    this->title = new char[strlen(title) + 1];
    this->genre = new char[strlen(genre) + 1];

    strcpy(this->title, title);
    strcpy(this->genre, genre);

    this->author = author;
}

Book::Book(const Book &book)
{
    this->numberOfPages = book.numberOfPages;

    this->title = new char[strlen(book.title) + 1];
    this->genre = new char[strlen(book.genre) + 1];

    strcpy(this->title, book.title);
    strcpy(this->genre, book.genre);

    this->author = book.author;
}

Book::~Book()
{
    delete[] title;
    delete[] genre;
}

Book &Book::operator=(const Book &book)
{
    this->numberOfPages = book.numberOfPages;

    this->title = new char[strlen(book.title) + 1];
    this->genre = new char[strlen(book.genre) + 1];

    strcpy(this->title, book.title);
    strcpy(this->genre, book.genre);

    this->author = book.author;

    return *this;
}

void Book::printDetails()
{
    if (this->author != NULL && this->numberOfPages != 0 && strcmp(this->title, "") != 0 && strcmp(this->title, "") != 0)
    {
        char *name = (this->author)->getAuthorName();
        cout << "The book \"" << this->title << "\", written by " << name
             << ", has " << this->numberOfPages << " pages and it's genre is "
             << this->genre << "." << endl;
    }
    else
    {
        cout << "This book has no valid details to show" << endl;
    }
}
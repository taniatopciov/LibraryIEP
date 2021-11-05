#include "Book.hpp"

// constructor with member initialization list
Book::Book()
    : numberOfPages(0),
      author(NULL)
{
    this->title = new char[strlen("") + 1];
    this->genre = new char[strlen("") + 1];

    strcpy(this->title, "");
    strcpy(this->genre, "");
}

// constructor with member initialization list
// deep copy for title and genre
Book::Book(int numberOfPages, char *title, char *genre, Author *author)
    : numberOfPages(numberOfPages),
      author(author)
{
    this->title = new char[strlen(title) + 1];
    this->genre = new char[strlen(genre) + 1];

    strcpy(this->title, title);
    strcpy(this->genre, genre);
}

// copy constructor
// deep copy for title and genre
Book::Book(const Book &book)
{
    this->numberOfPages = book.numberOfPages;

    this->title = new char[strlen(book.title) + 1];
    this->genre = new char[strlen(book.genre) + 1];

    strcpy(this->title, book.title);
    strcpy(this->genre, book.genre);

    this->author = book.author;
}

// deallocate memory
Book::~Book()
{
    delete[] title;
    delete[] genre;
}

//copy assignment operator
// deep copy for title and genre
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

void Book::makeTitleUppercase()
{
    int i;

    for (i = 0; i < strlen(title); i++)
    {
        title[i] = toupper(title[i]);
    }
}

void Book::makeTitleLowercase()
{
    int i;
    for (i = 0; i < strlen(title); i++)
    {
        title[i] = tolower(title[i]);
    }
}

char *Book::getTitle()
{
    return this->title;
}
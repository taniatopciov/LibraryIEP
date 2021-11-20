#include "Book.hpp"

// constructor with member initialization list
Book::Book()
    : numberOfPages(0),
      author(NULL)
{
    this->title = new char[strlen("") + 1];
    strcpy(this->title, "");
}

// constructor with member initialization list
// deep copy for title
Book::Book(int numberOfPages, char *title, Author *author)
    : numberOfPages(numberOfPages),
      author(author)
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

// copy constructor
// deep copy for title
Book::Book(const Book &book)
{
    this->numberOfPages = book.numberOfPages;

    this->title = new char[strlen(book.title) + 1];
    strcpy(this->title, book.title);

    this->author = book.author;

    logCall("Book copy constructor");
}

// deallocate memory
Book::~Book()
{
    if (strcmp(title, "") != 0)
    {
        delete[] title;
    }

    logCall("Book destructor");
}

//copy assignment operator
// deep copy for title
Book &Book::operator=(const Book &book)
{
    if (this == &book)
    {
        logCall("Book copy assignment operator - self assignment");
        return *this;
    }

    this->numberOfPages = book.numberOfPages;

    char *oldTitle = this->title;
    this->title = new char[strlen(book.title) + 1];
    strcpy(this->title, book.title);
    delete[] oldTitle;

    this->author = book.author;

    logCall("Book copy assignment operator");

    return *this;
}

void Book::printDetails()
{
    if (this->author != NULL && this->numberOfPages != 0 && strcmp(this->title, "") != 0)
    {
        char *name = (this->author)->getAuthorName();
        cout << "The book \"" << this->title << "\", written by " << name
             << ", has " << this->numberOfPages << " pages." << endl;
    }
    else
    {
        cout << "This book has no valid details to show" << endl;
    }
}

void Book::logCall(const string funcName)
{
    cout << funcName << endl;
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
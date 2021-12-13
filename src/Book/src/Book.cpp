#include "Book.hpp"

// constructor with member initialization list
Book::Book()
    : numberOfPages(0)
{
    this->title = new char[strlen("") + 1];
    strcpy(this->title, "");

    this->text = new char[strlen("") + 1];
    strcpy(this->text, "");
}

Book::Book(int numberOfPages, char *title)
    : numberOfPages(numberOfPages)
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->text = new char[strlen("") + 1];
    strcpy(this->text, "");
}

// constructor with member initialization list
// deep copy for title
Book::Book(int numberOfPages, char *title, char *text)
    : numberOfPages(numberOfPages)
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

// copy constructor
// deep copy for title
Book::Book(const Book &book)
    : numberOfPages(book.numberOfPages)
{
    this->title = new char[strlen(book.title) + 1];
    strcpy(this->title, book.title);

    this->text = new char[strlen(book.text) + 1];
    strcpy(this->text, book.text);

    logCall("Book copy constructor");
}

// deallocate memory
Book::~Book()
{
    if (strcmp(title, "") != 0)
    {
        delete[] title;
    }

    if (strcmp(text, "") != 0)
    {
        delete[] text;
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

    char *oldText = this->text;
    this->text = new char[strlen(book.text) + 1];
    strcpy(this->text, book.text);
    delete[] oldText;

    logCall("Book copy assignment operator");

    return *this;
}

void Book::printDetails()
{
    if (this->numberOfPages != 0 && strcmp(this->title, "") != 0)
    {
        cout << "\"" << this->title << " has " << this->numberOfPages << " pages." << endl;
    }
    else
    {
        cout << "No valid details to show" << endl;
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

char *Book::getText()
{
    return this->text;
}

void Book::setText(char *text)
{
    this->text = text;
}
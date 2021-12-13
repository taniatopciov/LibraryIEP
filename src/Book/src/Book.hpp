#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

using namespace std;

class Book
{
public:
    Book();
    Book(int numberOfPages, char *title);
    Book(int numberOfPages, char *title, char *text);

    //copy constructor
    Book(const Book &book);

    virtual ~Book();

    //copy assignment operator
    Book &operator=(const Book &book);

    char *getTitle();

    virtual void printDetails();

    char *getText();
    void setText(char *text);

    void logCall(const string funcName);
    void makeTitleUppercase();
    void makeTitleLowercase();

protected:
    int numberOfPages;
    char *title;
    char *text;
};

#endif //BOOK_H
#include "src/Person/src/Author.hpp"
#include "src/Book/src/Book.hpp"

#include <iostream>
using namespace std;

int main()
{
    char *name;
    name = new char[20];
    strcpy(name, "Ioana Pirvulescu");
    Author author1(name, 61, 30);
    author1.printPresentation();

    char *name2;
    name2 = new char[20];
    strcpy(name, "Mircea Cartarescu");
    Author author2(name, 63, 42);
    author2.printPresentation();

    /*Author author3 = author1; // not allowed because the copy constructor is private and has no implementation */

    /*Author author4; // Author has no default constructor ()*/

    /*Author author5 = author2; // not allowed because the copy assignment operator is private and has no implementation*/

    Book book1; // calls the default constuctor
    book1.printDetails();

    char *title;
    title = new char[20];
    strcpy(title, "Inocentii");

    char *genre;
    genre = new char[20];
    strcpy(genre, "Beletristica");

    Author *author;
    author = &author1;

    Book book2(400, title, genre, author); // calls the constructor with arguments

    book2.printDetails();

    book1 = book2; // calls the copy assignment operator

    book1.printDetails();

    Book book3(book1); //calls the copy constructor

    book3.printDetails();

    book2.makeTitleUppercase();

    book3.makeTitleLowercase();

    book1.printDetails();

    book2.printDetails();

    book3.printDetails();

    return 0;
}
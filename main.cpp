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

    Book book1;
    book1.printDetails();

    char *title;
    title = new char[20];
    strcpy(title, "Inocentii");

    char *genre;
    genre = new char[20];
    strcpy(genre, "Beletristica");

    Author *author;
    author = &author1;

    Book book2(400, title, genre, author);

    book2.printDetails();

    book1 = book2;

    book1.printDetails();

    Book book3(book1);

    book3.printDetails();

    return 0;
}
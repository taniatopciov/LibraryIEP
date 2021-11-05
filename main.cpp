#include "src/Person/src/Author.hpp"
#include "src/Book/src/Book.hpp"
#include "src/Library/src/Library.hpp"

#include <iostream>
using namespace std;

int main()
{
    char name1[20] = "Ioana Pirvulescu";
    Author author1(name1, 61, 30);
    author1.printPresentation();

    char name2[20] = "Mircea Cartarescu";
    Author author2(name2, 63, 42);
    author2.printPresentation();

    /*Author author4; // Author has no default constructor ()*/

    /*Author author3 = author1; // not allowed because the copy constructor is private and has no implementation */

    /*Author author5 = author2; // not allowed because the copy assignment operator is private and has no implementation*/

    Book book1; // calls no args constuctor
    book1.printDetails();

    char title[15] = "Inocentii";
    char genre[15] = "Beletristica";

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

    /*-----------------------------*/

    Library library; // calls default constructor

    Author *a;
    a = &author2;

    char title2[10] = "Solenoid";
    char genre2[20] = "Literary fiction";

    Book book4(350, title2, genre2, a);

    library.addBook(book1);

    library.addBook(book4);

    library.addBook(book2);

    cout << "All books before removal:" << endl;

    library.printBooks();

    library.removeBook(title2);

    cout << "Books left after removal" << endl;

    library.printBooks();

    return 0;
}
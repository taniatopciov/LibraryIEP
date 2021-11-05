#include "Library.hpp"

void Library::addBook(Book &book)
{
    cout << "SIZE " << books.size() << endl;

    books.push_back(book);
}

void Library::removeBook(char *title)
{
    int i = 0;
    for (Book b : books)
    {
        if (strcmp(b.getTitle(), title) == 0)
        {
            books.erase(books.begin() + i);
            break;
        }

        i++;
    }
}

void Library::printBooks()
{
    for (Book b : books)
    {
        cout << b.getTitle() << endl;
    }
}
#include "Textbook.hpp"

Textbook::Textbook() : Book()
{
    this->subject = new char[strlen("") + 1];
    strcpy(this->subject, "");
}

Textbook::Textbook(int numberOfPages, char *title, char *subject)
    : Book(numberOfPages, title)
{
    this->subject = new char[strlen(subject) + 1];
    strcpy(this->subject, subject);
}

Textbook::~Textbook()
{
    if ((this->subject, "") != 0)
    {
        delete[] subject;
    }

    logCall("Textbook destructor");
}

void Textbook::printDetails()
{
    Book::printDetails();

    int i;

    if (strcmp(this->subject, "") != 0)
    {
        cout << "Subject: " << this->subject << endl;
    }
    else
    {
        cout << "This textbook has no other details to show" << endl;
    }
}
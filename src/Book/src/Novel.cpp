#include "Novel.hpp"

Novel::Novel() : Book()
{
    this->literary_movement = new char[strlen("") + 1];
    strcpy(this->literary_movement, "");
}

Novel::Novel(int numberOfPages, char *title, Author *author, char *literary_movement)
    : Book(numberOfPages, title, author)
{
    this->literary_movement = new char[strlen(literary_movement) + 1];
    strcpy(this->literary_movement, literary_movement);
}

Novel::Novel(const Novel &novel)
    : Book(novel)
{
    this->literary_movement = new char[strlen(novel.literary_movement) + 1];
    strcpy(this->title, novel.title);

    logCall("Novel copy constructor");
}

Novel::~Novel()
{
    if ((literary_movement, "") != 0)
    {
        delete[] literary_movement;
    }

    logCall("Novel destructor");
}

Novel &Novel::operator=(const Novel &novel)
{
    Book::operator=(novel);

    char *oldLiteraryMovement = this->literary_movement;
    this->literary_movement = new char[strlen(novel.literary_movement) + 1];
    strcpy(this->literary_movement, novel.literary_movement);
    delete[] oldLiteraryMovement;

    logCall("Novel copy assignment operator");

    return *this;
}

void Novel::printDetails()
{
    if (strcmp(this->literary_movement, "") != 0)
    {
        Book::printDetails();
        char *name = (this->author)->getAuthorName();
        cout << "Literary movement: " << this->literary_movement << endl;
    }
    else
    {
        cout << "This novel has no valid details to show" << endl;
    }
}
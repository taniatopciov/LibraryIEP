#include "Novel.hpp"

Novel::Novel() : Book()
{
    this->author = NULL;

    this->literary_movement = new char[strlen("") + 1];
    strcpy(this->literary_movement, "");
}

Novel::Novel(int numberOfPages, char *title, Author *author, char *literary_movement)
    : Book(numberOfPages, title),
      author(author)
{
    this->literary_movement = new char[strlen(literary_movement) + 1];
    strcpy(this->literary_movement, literary_movement);

    logCall("Novel constructor");
}

Novel::Novel(const Novel &novel)
    : Book(novel)
{
    this->author = novel.author;

    this->literary_movement = new char[strlen(novel.literary_movement) + 1];
    strcpy(this->literary_movement, novel.literary_movement);

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
    if (this == &novel)
    {
        logCall("Novel copy assignment operator - self assignment");
        return *this;
    }

    Book::operator=(novel);

    this->author = novel.author;

    char *oldLiteraryMovement = this->literary_movement;
    this->literary_movement = new char[strlen(novel.literary_movement) + 1];
    strcpy(this->literary_movement, novel.literary_movement);
    delete[] oldLiteraryMovement;

    logCall("Novel copy assignment operator");

    return *this;
}

void Novel::printDetails()
{
    Book::printDetails();

    if (this->author != NULL && strcmp(this->literary_movement, "") != 0)
    {
        char *name = (this->author)->getAuthorName();
        cout << "Author: " << name << endl;
        cout << "Literary movement: " << this->literary_movement << endl;
    }
    else
    {
        cout << "This novel has no other details to show" << endl;
    }
}
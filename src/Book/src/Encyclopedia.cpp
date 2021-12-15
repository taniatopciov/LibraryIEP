#include "Encyclopedia.hpp"

Encyclopedia::Encyclopedia() : Book()
{
    this->references = new char[strlen("") + 1];
    strcpy(this->references, "");
}

Encyclopedia::Encyclopedia(int numberOfPages, char *title, char *references)
    : Book(numberOfPages, title)
{
    this->references = new char[strlen(references) + 1];
    strcpy(this->references, references);

    logCall("Encyclopedia constructor");
}

Encyclopedia::Encyclopedia(const Encyclopedia &encyclopedia)
    : Book(encyclopedia)
{
    this->references = new char[strlen(encyclopedia.references) + 1];
    strcpy(this->references, encyclopedia.references);

    logCall("Encyclopedia copy constructor");
}

Encyclopedia::~Encyclopedia()
{
    if ((this->references, "") != 0)
    {
        delete[] references;
    }

    logCall("Encyclopedia destructor");
}

Encyclopedia &Encyclopedia::operator=(const Encyclopedia &encyclopedia)
{
    if (this == &encyclopedia)
    {
        logCall("Encyclopedia copy assignment operator - self assignment");
        return *this;
    }

    Book::operator=(encyclopedia);

    char *oldReferences = this->references;
    this->references = new char[strlen(encyclopedia.references) + 1];
    strcpy(this->references, encyclopedia.references);
    delete[] oldReferences;

    logCall("Encyclopedia copy assignment operator");

    return *this;
}

void Encyclopedia::printDetails()
{
    Book::printDetails();

    int i;

    if (strcmp(this->references, "") != 0)
    {
        cout << "References: " << this->references << endl;
    }
    else
    {
        cout << "This encyclopedia has no other details to show" << endl;
    }
}

char *Encyclopedia::getReferences()
{
    return this->references;
}

void Encyclopedia::setReferences(char *references)
{
    this->references = references;
}
#include "Encyclopedia.hpp"

Encyclopedia::Encyclopedia() : Book()
{
    this->text = new char[strlen("") + 1];
    strcpy(this->text, "");
}

Encyclopedia::Encyclopedia(int numberOfPages, char *title, char *text)
    : Book(numberOfPages, title)
{
    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

Encyclopedia::Encyclopedia(const Encyclopedia &encyclopedia)
    : Book(encyclopedia)
{
    this->text = new char[strlen(encyclopedia.text) + 1];
    strcpy(this->text, encyclopedia.text);

    logCall("Encyclopedia copy constructor");
}

Encyclopedia::~Encyclopedia()
{
    if ((this->text, "") != 0)
    {
        delete[] text;
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

    char *oldText = this->text;
    this->text = new char[strlen(encyclopedia.text) + 1];
    strcpy(this->text, encyclopedia.text);
    delete[] oldText;

    logCall("Encyclopedia copy assignment operator");

    return *this;
}

void Encyclopedia::printDetails()
{
    Book::printDetails();

    int i;

    if (strcmp(this->text, "") != 0)
    {
        cout << "Text: " << this->text << endl;
    }
    else
    {
        cout << "This encyclopedia has no other details to show" << endl;
    }
}

char *Encyclopedia::getText()
{
    return this->text;
}

void Encyclopedia::setText(char *text)
{
    this->text = text;
}